#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

void MainWindow::initEventLoop(){
    //Initializing the timer
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(doEvent()));
    timer->start(1);
    //Every thing is in milli-seconds
    sec_count = 0;
    time_out=5000;
    idle_time=1000;
    read_card=attendRequest=attendResponse=-1;
    //Initializing the rfid
    RFID::init();
}
void MainWindow::doEvent(){
    if(ui->stackedWidget->currentIndex()==INITIALIZE){
        init();
    }
    sec_count = (sec_count+ 1)%60000;
    idle_time++;
    ui->label_time->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->label_developed->setText(QDate::currentDate().toString("dd/MM/yy"));
    checkAlterUi();
    if(sec_count==0){
        checkWelcomeUi();
    }
    if(idle_time>=time_out){
        emit TIMEOUT();
        idle_time=0;
    }
    Network::response.lock();
    if(Network::response.isset){
        processResponse(Network::response.resp,Network::response.type);
        Network::response.unset();
    }
    Network::response.unlock();

    if(read_card !=-1 || ui->stackedWidget->currentIndex()==0){
        string rfid = RFID::readCard();
        if(rfid!=""){
            doReadCard(rfid);
         if(ui->stackedWidget->currentIndex()==0){
                if(attendRequest==-1){
                AuthRequest r;
                r.init(device.mac,"19");
                Network::sendRequest(&r);
                attendRequest=-1;
                attendResponse=AUTH;
                }
            }
        }
    }
}
void MainWindow::doReadCard(string rfid){
    QString _id = QString::fromStdString(to_string(rfid));
    switch (read_card){
    case DELETE_CARD:{
        ui->stackedWidget_admin->setCurrentIndex(DELETE);
        ui->label_admin_status->setText("Your card number:"+_id);
        if(attendRequest==DELETE_CARD){
            DeleteCardRequest r;
            r.init(device.mac,device.pin,rfid);
            Network::sendRequest(&r);
            read_card=-1;
            attendResponse = DELETE_CARD;
            attendRequest = -1;
        }
        break;
    }
    case CREATE_NEW_CARD:{
        ui->stackedWidget_admin->setCurrentIndex(OPTION);
        ui->label_card_num->setText(_id);
        if(attendRequest==CREATE_NEW_CARD){
            CreateCardRequest r;
            r.init(device.mac,device.pin,rfid,false);
            Network::sendRequest(&r);
            read_card=-1;
            attendResponse = CREATE_NEW_CARD;
            attendRequest = -1;
        }
        break;
    }
    case CREATE_MASTER_CARD:{
        ui->stackedWidget_admin->setCurrentIndex(DELETE);
        ui->label_admin_status->setText("Your card number:"+_id);
        if(attendRequest==CREATE_MASTER_CARD){
            CreateCardRequest r;
            r.init(device.mac,device.pin,rfid,true);
            Network::sendRequest(&r);
            read_card=-1;
            attendResponse = CREATE_MASTER_CARD;
            attendRequest = -1;
        }
        break;
    }
    default:
        break;
    }
}
