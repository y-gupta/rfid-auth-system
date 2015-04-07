#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

void MainWindow::gotoAdmin(){
    ui->stackedWidget->setCurrentIndex(ADMIN);
    ui->stackedWidget_admin->setAcceptDrops(TEXT);
    ui->label_notification->setText("Select any one!");
}
void MainWindow::on_pushButton_allow_clicked(){
    reset();
    AllowTempRequest r;
    r.init(0,0);
    Network::sendRequest(&r);
    ui->label_notification->setText("Your request is being processed!");
    attendRequest=-1;
    attendResponse=ALLOW_TEMP;
}
void MainWindow::on_pushButton_delete_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    read_card = DELETE_CARD;
    cout<<"Read-card:"<<read_card<<endl;
    attendRequest=-1;
}
void MainWindow::on_pushButton_reg_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    read_card = CREATE_NEW_CARD;
    attendRequest=-1;
}
void MainWindow::on_pushButton_master_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    read_card = CREATE_MASTER_CARD;
    attendRequest=-1;
}
void MainWindow::on_toolButton_inc_clicked(){
    reset();
    if(ui->spinBox_days->value()>=1)
    ui->spinBox_days->stepUp();
}
void MainWindow::on_toolButton_dec_clicked(){
    reset();
    if(ui->spinBox_days->value() > 1)
    ui->spinBox_days->stepDown();
}
void MainWindow::on_pushButton_confirm_2_clicked(){
    cout<<"Read-card confirmed:"<<read_card<<endl;
    attendRequest=read_card;
    cout<<"Request confirmed:" <<attendRequest<<endl;
    reset();
    gotoWelcome();
}
