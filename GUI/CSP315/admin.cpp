#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

void MainWindow::gotoAdmin(){
    ui->stackedWidget->setCurrentIndex(ADMIN);
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    ui->label_notification->setText("Select any one!");
    cout<<"Read-card:"<<read_card<<endl;
    cout<<"Attend-Response"<<attendResponse<<endl;
    cout<<"Admin page is called"<<endl;
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
    ui->label_notification->setText("Place your card!");
    read_card = DELETE_CARD;
    attendRequest=-1;
    cout<<"Read-card:"<<read_card<<endl;
}
void MainWindow::on_pushButton_reg_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    ui->label_notification->setText("Place your card!");
    read_card = CREATE_NEW_CARD;
    attendRequest=-1;
    cout<<"Read-card:"<<read_card<<endl;
}
void MainWindow::on_pushButton_master_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    ui->label_notification->setText("Place your card!");
    read_card = CREATE_MASTER_CARD;
    attendRequest=-1;
    cout<<"Read-card:"<<read_card<<endl;
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
    attendRequest=read_card;
    cout<<"Request confirmed:" <<attendRequest<<endl;
    reset();
}
void MainWindow::on_pushButton_confirm_3_clicked(){
    attendRequest=read_card;
    cout<<"Request confirmed:" <<attendRequest<<endl;
    reset();
}
