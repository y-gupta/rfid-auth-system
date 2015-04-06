#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

void MainWindow::initEventLoop(){
    //Initializing the timer
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(doEvent()));
    timer->start(1000);
    sec_count = 0;
    time_out=5;
    idle_time=0;
    read_card=-1;
    //Initializing the rfid
    RFID::init();
}
void MainWindow::doEvent(){
    //Date and time event in the welcome screen
    sec_count = (sec_count+ 1)%60;
    idle_time++;
    ui->label_time->setText(QString::fromStdString("Date : "+QDate::currentDate().toString("dd/MM/yy").toStdString() + "\nTime : " +
    QTime::currentTime().toString("hh:mm:ss").toStdString() + " "));

    if(sec_count==0){
        checkWelcomeUi();
    }
    if(idle_time>=time_out){
        emit TIMEOUT();
        idle_time=0;
    }

    if(read_card!=-1 || ui->stackedWidget->currentIndex()==0){
        int64_t rfid = RFID::readCard();
        if(rfid!=-1){
            doReadCard(rfid);
            if(ui->stackedWidget->currentIndex()==0){
                AuthRequest r;
                r.init(AUTH,device_id,current_user.uid);
                r.rfid = rfid;
                Network::sendRequest(&r);
            }
        }
    }


}
void MainWindow::doReadCard(int64_t rfid){
    switch (read_card){
    case DELETE_CARD:
        ui->stackedWidget_admin->setCurrentIndex(OPTION);
        ui->pushButton_confirm_2->setEnabled(true);
        if(attendRequest){
            DeleteCardRequest r;
            r.init(DELETE_CARD,device_id,current_user.uid);
            r.rfid = rfid;
            Network::sendRequest(&r);
            read_card=-1;
        }
        break;
    case CREATE_NEW_CARD:{
        ui->stackedWidget_admin->setCurrentIndex(OPTION);
        ui->toolButton_dec->setEnabled(true);
        ui->toolButton_inc->setEnabled(true);
        ui->pushButton_confirm_2->setEnabled(true);

        CreateCardRequest r;
        r.init(CREATE_NEW_CARD,device_id,current_user.uid);
        r.rfid = rfid;
        r.isMasterCard = false;
        Network::sendRequest(&r);
        read_card=-1;
        break;
    }
    case CREATE_MASTER_CARD:{
        CreateCardRequest r;
        r.init(CREATE_MASTER_CARD,device_id,current_user.uid);
        r.rfid = rfid;
        r.isMasterCard = true;
        Network::sendRequest(&r);
        read_card=-1;
        break;}
    default:
        return;
    }
}
