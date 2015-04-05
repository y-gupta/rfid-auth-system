#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::initEventLoop(){
    //Initializing the timer
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(doEvent()));
    timer->start(1000);
    sec_count = 0;
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
    }

    //TODO rfid stuff
    bool isMasterCard=false;
//    if(ui->stackedWidget->currentIndex()==0){
//        if(RFID::readCard() != -1){
//            if(isMasterCard){
//                gotoAdmin();
//            }
//            else{
//                //User logged in
//                current_user.clear();
//                //Get the details
//                current_user.init(1,"Rishit Sanmukhani","2013CS10255","Zanskar Hostel");
//                gotoGeneral();
//            }
//        }
//    }
}
