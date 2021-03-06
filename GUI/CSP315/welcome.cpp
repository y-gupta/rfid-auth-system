#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "request.h"
#include "network.h"


#define MEAL_TIME 0
#define NO_MEAL_TIME 1

void MainWindow::initWelcomeUi(){
    timing.resize(4);
    timing[0].first.setHMS(7,0,0);
    timing[0].second.setHMS(9,0,0);
    timing[1].first.setHMS(12,0,0);
    timing[1].second.setHMS(14,0,0);
    timing[2].first.setHMS(19,0,0);
    timing[2].second.setHMS(21,0,0);

    timing[3].first.setHMS(0,0,1);
    timing[3].second.setHMS(23,59,59);

    checkWelcomeUi();
}
void MainWindow::checkWelcomeUi(){
//    QTime curr_time = QTime::currentTime();
//    for(int i=0;i<3;i++){
//        if(timing[i].first <= curr_time && curr_time <= timing[i].second){
//            int elapsed = curr_time.secsTo(timing[i].second);
//            int hrs = elapsed/3600;
//            int min = (elapsed%3600)/60;
//            string str = to_string(hrs) + " hr " + to_string(min) + " min remaining";
//            ui->label_time_status->setText(QString::fromStdString(str));
//            setUpMealTimeUi();
//            break;
//        }
//        if(curr_time < timing[i].first){
//            int elapsed = curr_time.secsTo(timing[i].first);
//            int hrs = elapsed/3600;
//            int min = (elapsed%3600)/60;
//            string str = to_string(hrs) + " hr " + to_string(min) + " min to next meal";
//            ui->label_time_status->setText(QString::fromStdString(str));
//            setUpNoMealTimeUi();
//            break;
//        }
//    }
//    if(curr_time > timing[2].second){
//        int elapsed = curr_time.secsTo(timing[3].second) + timing[3].first.secsTo(timing[0].first);
//        int hrs = elapsed/3600;
//        int min = (elapsed%3600)/60;
//        string str = to_string(hrs) + " hr " + to_string(min) + " min to next meal";
//        ui->label_time_status->setText(QString::fromStdString(str));
//        setUpNoMealTimeUi();
//    }
    InitRequest r;
    r.init(device.mac);
    Network::sendRequest(&r);
    attendResponse=INIT;
}
void MainWindow::checkAlterUi(){
    uint64_t min = QTime::currentTime().minute();
    uint64_t sec = QTime::currentTime().second();
    string str;
    if(min%6==0){
        str = to_string(60-sec)+" sec remaining in breakfast.";
        ui->label_time_status->setText(QString::fromStdString(str));
        setUpMealTimeUi();
    }else if(min%6==1){
        str = to_string(60-sec)+" sec to lunch.";
        ui->label_time_status->setText(QString::fromStdString(str));
        setUpNoMealTimeUi();
    }else if(min%6==2){
        str = to_string(60-sec)+" sec remaining in lunch.";
        ui->label_time_status->setText(QString::fromStdString(str));
        setUpMealTimeUi();
    }else if(min%6==3){
        str = to_string(60-sec)+" sec to dinner.";
        ui->label_time_status->setText(QString::fromStdString(str));
        setUpNoMealTimeUi();
    }else if(min%6==4){
        str = to_string(60-sec)+" sec remaining in dinner.";
        ui->label_time_status->setText(QString::fromStdString(str));
        setUpMealTimeUi();
    }else if(min%6==5){
        str = to_string(60-sec)+" sec to breakfast.";
        ui->label_time_status->setText(QString::fromStdString(str));
        setUpNoMealTimeUi();
    }
}
void MainWindow::gotoWelcome(){
    ui->stackedWidget->setCurrentIndex(WELCOME);
    checkWelcomeUi();
}
void MainWindow::setUpMealTimeUi(){
    //TODO - MEAL TIME STUFF
    ui->stackedWidget_statistics->setCurrentIndex(MEAL_TIME);
    ui->stackedWidget_graph->setCurrentIndex(MEAL_TIME);
}
void MainWindow::setUpNoMealTimeUi(){
    //TODO - NO_MEAL_TIME Stuff
    ui->stackedWidget_statistics->setCurrentIndex(NO_MEAL_TIME);
    ui->stackedWidget_graph->setCurrentIndex(NO_MEAL_TIME);
}
void MainWindow::on_pushButton_staff_login_clicked(){reset();
    gotoStaffLogin();
}
