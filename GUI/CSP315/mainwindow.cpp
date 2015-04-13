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
    connect(this,SIGNAL(TIMEOUT()),this,SLOT(timeout()));
    ui->stackedWidget->setCurrentIndex(INITIALIZE);
    ui->toolButton_home->setHidden(true);

    //Hard coded the mac and the pin
    //Later we can make the script to calculate
    device.mac = "100";
    device.pin = "0000";

    //Initializing everything
    Network::init("localhost:1337");
    initWelcomeUi();
    initMessingUi();
    initStaffLoginUi();
    initEventLoop();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
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
    ui->toolButton_home->setHidden(false);
    gotoWelcome();
}

void MainWindow::setMyStyleSheet(){
    ifstream in;
    in.open("../style.css");
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
    //TODO - Request has been expired
    if(attendRequest!=DELETE_CARD && attendRequest!=CREATE_NEW_CARD && attendRequest!=CREATE_MASTER_CARD)
        read_card=-1;

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
            break;
        }
        default:
            break;
    }
}
void MainWindow::processInitResponse(string _resp){
    Document d;
    d.Parse(_resp.c_str());
    Value& v= d["success"];
    if(v.GetBool()){
        v = d["hostel"];
        device.hostel_name = v.GetString();
        v = d["image"];
        convertToPNG(v.GetString(),"../Resources/graph1.png");
        //TODO - Set the expected & logged in users
    }
    else{
        showConfirmation("Initialization failed!!");
        qApp->exit(1);
    }
}

void MainWindow::processAuthResponse(string _resp){
    Document arr ;
    arr.Parse(_resp.c_str());
    Value& v = arr["success"];
    assert(v.IsBool() && "invalid auth response");
    User user;
    if(v.GetBool()){
        v = arr["rfid"];
        //assert(v.IsInt() && "invalid uid in auth response");
        user.rfid=atoi(v.GetString());
        v = arr["master"];
        assert(v.IsBool() && "invalid master in auth response");
        user.isAdmin = v.GetBool();
        v = arr["hostel"];
        device.hostel_name = v.GetString();
        v = arr["entry"];
        cout<<"Success"<<endl;
        assert(v.IsString() &&"invalid entry number in response");
        user.entry_no = v.GetString();
        v = arr["name"];
        cout<<"Success"<<endl;
        assert(v.IsString() &&"invalid name in response");
        user.user_name = v.GetString();
        if(!user.isAdmin){
        v = arr["image_data"];
        convertToPNG(v.GetString(),"./user.png");
        }
    }

    cout<<"Success"<<endl;
    if(attendResponse==AUTH){
        attendResponse=-1;
        if(user.rfid==0){
            showConfirmation("Authentication failed!!");
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
        cout<<"Registration of master card failed"<<endl;
    }
}
void MainWindow::processCreateNewCardResponse(string _resp){
    Document d;
    d.Parse(_resp.c_str());
    Value& v = d["success"];
    if(v.GetBool()){
        //TODO change all the couts to prints in the popup box
        cout<<"Success!"<<endl;
    }
    else{
        cout<<"Registration of card failed"<<endl;
    }
}
void MainWindow::processDeleteCardResponse(string _resp){

    if(attendResponse==DELETE_CARD){
        Document d;
        d.Parse(_resp.c_str());
        Value& v = d["success"];
        if(v.GetBool()){
            attendResponse=-1;
            cout<<"Success!"<<endl;
            gotoWelcome();
        }
        else{
            cout<<"Deletion failed!"<<endl;
          }
    }
}
void MainWindow::processAllowTempResponse(string _resp){
    if(attendResponse==ALLOW_TEMP){
        Document d;
        d.Parse(_resp.c_str());
        Value& v = d["success"];
        if(v.GetBool()){
            attendResponse=-1;
            cout<<"Success!"<<endl;
            gotoWelcome();
        }
        else{
        cout<<"Deletion failed!"<<endl;
        }
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
        Document d;
        d.Parse(_resp.c_str());
        Value& v = d["success"];
        if(v.GetBool()){
            cout<<"Success!"<<endl;
        attendResponse=-1;
        gotoAdmin();
        }
        else{
            cout<<"Staff Login failed"<<endl;
        }
    }
}
void MainWindow::showConfirmation(string s){
    ConfirmDialog dialog;
    dialog.setString(s);
    dialog.show();
    dialog.activateWindow();
    dialog.exec();
}
