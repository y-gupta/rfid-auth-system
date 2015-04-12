#include "mainwindow.h"
#include "rapidjson/document.h"
#include "ui_mainwindow.h"
#include "network.h"
#include "base64.h"
using namespace rapidjson;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMyStyleSheet();
    setMouseTracking(true);
    ui->setupUi(this);

    Network::init("192.168.1.105:1337");
    //ui->tabWidget_option ->setStyleSheet("QTabBar::tab { height: 100px; width: 660px; }");

        ui->stackedWidget->setCurrentIndex(INITIALIZE);
//    ui->label_14->setText(QString::fromUtf8("\u20B9 50"));
      ui->toolButton_home->setHidden(true);

    device.mac = "100";
    device.pin = "0000";
    connect(this,SIGNAL(TIMEOUT()),this,SLOT(timeout()));
    initWelcomeUi();
    initMessingUi();
    initStaffLoginUi();
  //  gotoWelcome();
    initEventLoop();

    //TODO - Send the init request

    //    gotoAdmin();

//    initWelcomeUi();
//    checkWelcomeUi();
//    gotoGeneral();
}
MainWindow::~MainWindow()
{
    delete ui;
    removeEventFilter(this);
}

void MainWindow::init(){
    //TODO - Init request
    cout<<"initalising"<<endl;
    InitRequest r;
    r.init(device.mac);
    Network::sendRequest(&r);
    string _resp;

    while(1){
         Network::response.lock();
        if(Network::response.isset){
            _resp = Network::response.resp;
            uint16_t _type = Network::response.type;
            if(_type==INIT)
                break;
            Network::response.unset();
        }
        Network::response.unlock();
    }

    Network::response.unlock();
    processInitResponse(_resp);
    gotoWelcome();
   // gotoGeneral();
    ui->toolButton_home->setHidden(false);
}

void MainWindow::setMyStyleSheet(){
    ifstream in;
    in.open("../style.css");
    cout<<"Done"<<endl;
    string Mystyle;
    getline(in,Mystyle,((char)-1));
    in.close();
    qApp->setStyleSheet(Mystyle.c_str());
}
void MainWindow::on_toolButton_home_clicked(){
    reset();
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
        case MESSING_REQ:{
            processMessingRequest(_resp);
            break;
        }
        case REBATE_REQ:{
            processRebateRequest(_resp);
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
    cout<<"processing init response"<<endl;

    //Parse JSON

    Document d;
    d.Parse(_resp.c_str());
    Value& v= d["success"];
    if(v.GetBool()){
        v = d["hostel"];
        device.hostel_name = v.GetString();
        v = d["image"];
        convertToPNG(v.GetString(),"../Resources/graph1.png");
        //TODO set the expected and logged in
    }
    else{
        cout<<"Initialising the device failed"<<endl;
    }

}

void MainWindow::processAuthResponse(string _resp){
    cout<<"Processing auth"<<endl;
    //cout<<"Resp:"<<_resp<<endl;
    Document arr ;arr.Parse(_resp.c_str());
    Value& v = arr["success"];
    assert(v.IsBool() && "invalid auth response");
    User user;

    if(v.GetBool()){

        v = arr["rfid"];
        //assert(v.IsInt() && "invalide uid in auth response");
        user.rfid=atoi(v.GetString());
        v = arr["master"];
        assert(v.IsBool() && "invalide master in auth response");
        user.isAdmin = v.GetBool();
        v = arr["hostel"];
        device.hostel_name = v.GetString();
        v = arr["entry"];
        assert(v.IsString() &&"invalid entry number in response");
        user.entry_no = v.GetString();
        //user.entry_no = "2013CS007";
        v = arr["name"];
        assert(v.IsString() &&"invalid name in response");
        user.user_name = v.GetString();
        if(!user.isAdmin){
        v = arr["image_data"];
        convertToPNG(v.GetString(),"./user.png");
        }
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
            current_user.hostel_name = device.hostel_name;
            gotoGeneral();
        }
    }
}
void MainWindow::processCreateMasterCardResponse(string _resp){
    Document d;
    d.Parse(_resp.c_str());
    Value& v = d["success"];
    if(v.GetBool()){
        //TODO change all the couts to prints in the popup box
        cout<<"Success!"<<endl;
    }
    else{
        cout<<"Creation of master card failed"<<endl;
    }
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
    cout<<_resp<<endl;
    Document d;
    d.Parse(_resp.c_str());
    Value& v = d["success"];
    if(v.GetBool()){
        cout<<"successful transaction"<<endl;
        //TODO give the print command
    }
    else{
        cout<<"transaction failed"<<endl;
    }

}
void MainWindow::processRebateRequest(string _resp){
    cout<<"This is rebate request"<<endl;
    cout<<_resp<<endl;
    //JSON parsing
    Document d;
    d.Parse(_resp.c_str());
    Value& v = d["success"];
    if(v.GetBool()){
        cout<<"successful rebate request"<<endl;
        //TODO print a receipt
    }
    else{
        cout<<"rebate request failed"<<endl;
    }


}
void MainWindow::processStaffLoginResponse(string _resp){
    if(attendResponse==STAFF_LOGIN_REQ){
        cout<<"This is Staff Login request"<<endl;
        attendResponse=-1;
        gotoAdmin();
    }
}
void MainWindow::showConfirmation(string s){
    ConfirmDialog dialog;
    dialog.setString(s);
    dialog.show();
    dialog.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    dialog.exec();
}
