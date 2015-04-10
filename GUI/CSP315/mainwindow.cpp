#include "mainwindow.h"
#include "rapidjson/document.h"
#include "ui_mainwindow.h"
#include "network.h"
using namespace rapidjson;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMyStyleSheet();
    setMouseTracking(true);
    ui->setupUi(this);

    Network::init("10.42.0.77/");

    ui->stackedWidget->setCurrentIndex(INITIALIZE);
    ui->toolButton_home->setHidden(true);

    device_mac = "00-00";
    connect(this,SIGNAL(TIMEOUT()),this,SLOT(timeout()));
    initWelcomeUi();
    initEventLoop();

    //TODO - Send the init request

    //    gotoAdmin();

//    initWelcomeUi();
//    checkWelcomeUi();
//    gotoGeneral();

    QPixmap pixmap(":/images/rupee.jpg");
    cout<<pixmap.isNull()<<endl;
    QIcon ButtonIcon(pixmap);

    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(QSize(60,60));

    ui->pushButton_2->setIcon(ButtonIcon);
    ui->pushButton_2->setIconSize(QSize(60,60));

    ui->pushButton_3->setIcon(ButtonIcon);
    ui->pushButton_3->setIconSize(QSize(60,60));

    ui->pushButton_4->setIcon(ButtonIcon);
    ui->pushButton_4->setIconSize(QSize(60,60));

    ui->pushButton_5->setIcon(ButtonIcon);
    ui->pushButton_5->setIconSize(QSize(60,60));

    ui->pushButton_6->setIcon(ButtonIcon);
    ui->pushButton_6->setIconSize(QSize(60,60));
    installEventFilter(this);
}
MainWindow::~MainWindow()
{
    delete ui;
    removeEventFilter(this);
}

void MainWindow::init(){
    //TODO - Init request
    InitRequest r;
    r.init(device_mac);
    Network::sendRequest(&r);
    string _resp;
    Network::response.lock();
    while(1){
        if(Network::response.isset){
            _resp = Network::response.resp;
            uint16_t _type = Network::response.type;
            if(_type==INIT)
                break;
            Network::response.unset();
        }
    }
    Network::response.unlock();
    processInitResponse(_resp);
    gotoWelcome();
    ui->toolButton_home->setHidden(false);
}

void MainWindow::setMyStyleSheet(){
    ifstream in;
    in.open("../style.css");
    string Mystyle;
    getline(in,Mystyle,((char)-1));
    in.close();
    qApp->setStyleSheet(Mystyle.c_str());
}
void MainWindow::on_toolButton_home_clicked(){reset();
    gotoWelcome();
}
void MainWindow::timeout(){
    gotoWelcome();
}
void MainWindow::reset(){
    idle_time=0;
    if(attendRequest!=DELETE_CARD && attendRequest!=CREATE_NEW_CARD && attendRequest!=CREATE_MASTER_CARD)
        read_card=-1;
    //Yourrequest has expired

}
void MainWindow::processResponse(string _resp,uint16_t _type){
    switch(_type){
        case AUTH:{
            processAuthResponse(_resp);
            break;
        }
        case DELETE_CARD:{
            processDeleteCardResponse(_resp);
            break;
        }
        case CREATE_NEW_CARD:{
            processCreateNewCardResponse(_resp);
            break;
        }
        case CREATE_MASTER_CARD:{
            processCreateMasterCardResponse(_resp);
            break;
        }
        case ALLOW_TEMP:{
            processAllowTempResponse(_resp);
            break;
        }
        case STAFF_LOGIN_REQ:{
            processStaffLoginResponse(_resp);
        }
        default:
            break;
    }
}
void MainWindow::processInitResponse(string _resp){
    //TODO
}

void MainWindow::processAuthResponse(string _resp){
    cout<<"Processing auth"<<endl;
    cout<<"Resp:"<<_resp<<endl;
    Document arr ;arr.Parse(_resp.c_str());
    Value& v = arr["success"];
    assert(v.IsBool() && "invalid auth response");
    User user;

    if(v.GetBool()){

        v = arr["rfid"];
        assert(v.IsInt() && "invalide uid in auth response");
        user.rfid=v.GetInt();
        v = arr["master"];
        assert(v.IsBool() && "invalide master in auth response");
        user.isAdmin = v.GetBool();
        v = arr["hostel"];
        user.hostel_name = v.GetString();
//        v = arr["entry"];
//        assert(v.IsString() &&"invalid entry number in response");
//        user.entry_no = v.GetString();
        user.entry_no = "2013CS007";
        v = arr["name"];
        assert(v.IsString() &&"invalid name in response");
        user.user_name = v.GetString();
   }

    if(user.rfid==0 ||attendResponse!=AUTH){
        cout<<"Authentication failed!!"<<endl;
    }
    else{

        if(user.isAdmin){
            gotoAdmin();
        }
        else{

            current_user.clear();
            current_user=user;
            gotoGeneral();
        }
    }
}
void MainWindow::processCreateMasterCardResponse(string _resp){

}
void MainWindow::processCreateNewCardResponse(string _resp){

}
void MainWindow::processDeleteCardResponse(string _resp){
    bool isSuccess = true;
    if(isSuccess && attendResponse==DELETE_CARD){
        attendResponse=-1;
        gotoWelcome();
    }

}
void MainWindow::processAllowTempResponse(string _resp){
    bool isSuccess = true;
    if(isSuccess && attendResponse==ALLOW_TEMP){
        attendResponse=-1;
        gotoWelcome();
    }
}
void MainWindow::processMessingRequest(string _resp){
    cout<<"This is Messing request"<<endl;
}
void MainWindow::processRebateRequest(string _resp){
    cout<<"This is rebate request"<<endl;
}
void MainWindow::processStaffLoginResponse(string _resp){
    if(attendResponse==STAFF_LOGIN_REQ){
        cout<<"This is Staff Login request"<<endl;
        attendResponse=-1;
        gotoAdmin();
    }
}
