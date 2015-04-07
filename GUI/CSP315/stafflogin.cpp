#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "request.h"
#include "network.h"


void MainWindow::gotoStaffLogin(){
    ui->stackedWidget->setCurrentIndex(STAFF_LOGIN);
    ui->lineEdit_password->clear();
}
void MainWindow::on_pushButton_10_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_10->text());
}
void MainWindow::on_pushButton_11_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_11->text());
}
void MainWindow::on_pushButton_12_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_12->text());
}
void MainWindow::on_pushButton_13_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_13->text());
}
void MainWindow::on_pushButton_14_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_14->text());
}
void MainWindow::on_pushButton_15_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_15->text());
}
void MainWindow::on_pushButton_16_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_16->text());
}
void MainWindow::on_pushButton_17_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_17->text());
}
void MainWindow::on_pushButton_18_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_18->text());
}
void MainWindow::on_pushButton_20_clicked(){
reset();
    ui->lineEdit_password->setText(ui->lineEdit_password->text() + ui->pushButton_20->text());
}
void MainWindow::on_pushButton_del_clicked(){
reset();
    QString password = ui->lineEdit_password->text();
    if(password.size()>=1)
    ui->lineEdit_password->setText(password.left(password.size()-1));
}
void MainWindow::on_pushButton_enter_clicked(){
reset();
StaffLoginRequest r;
r.init(device_id,ui->lineEdit_password->text().toStdString());
Network::sendRequest(&r);
attendRequest=-1;
attendResponse=STAFF_LOGIN_REQ;
}

