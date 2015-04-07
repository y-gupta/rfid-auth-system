#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMouseTracking(true);
    ui->setupUi(this);
    Network::init("localhost/csp.php");

    connect(this,SIGNAL(TIMEOUT()),this,SLOT(timeout()));
    initWelcomeUi();
    initEventLoop();
    gotoAdmin();

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

void MainWindow::processAuthResponse(string _resp){
    current_user.hostel_name=_resp;
//    if(usr.uid==0 && attendResponse!=AUTH){
//        cout<<"Authentication failed!!"<<endl;
//    }
//    else{
//        if(usr.isAdmin){
//            gotoAdmin();
//        }
//        else{
//            current_user.clear();
//            current_user=usr;
            //gotoGeneral();
//        }
//    }
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
