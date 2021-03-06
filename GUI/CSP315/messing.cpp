#include "mainwindow.h"
#include "network.h"
#include "ui_mainwindow.h"

#define MESSING 0
#define REBATE 1
void MainWindow::sendMessingRequest(uint32_t _value){
    current_user.value = _value;
    MessingRequest req;
    req.init(device.mac,current_user.rfid,_value);
    Network::sendRequest(&req);
    attendRequest=-1;
    attendResponse=MESSING_REQ;
}
void MainWindow::gotoGeneral(){
    ui->stackedWidget->setCurrentIndex(GENERAL);
    ui->label_name->setText(QString::fromStdString(current_user.user_name));
    ui->label_hostel_1->setText(QString::fromStdString(current_user.hostel_name));
    ui->label_id->setText(QString::fromStdString(current_user.entry_no));
    //Initializing the rebate
    ui->dateEdit_present->setDate(QDate::currentDate());
    ui->dateEdit_future->setDate(QDate::currentDate());
    checkRebateUi();
    //Initializing the extra-messing
    ui->tabWidget_option->setCurrentIndex(MESSING);
    ui->spinBox_val->setValue(1);

    //Show the image of the user
    showConfirmation("Hr");
    //    UserDialog dialog;
//    dialog.show();
//    dialog.exec();
//    idle_time=0;
}
void MainWindow::initMessingUi(){
    ui->pushButton->setText(QString::fromUtf8("\u20B9 5"));
    ui->pushButton_2->setText(QString::fromUtf8("\u20B9 7"));
    ui->pushButton_3->setText(QString::fromUtf8("\u20B9 13"));
    ui->pushButton_4->setText(QString::fromUtf8("\u20B9 19"));
    ui->pushButton_5->setText(QString::fromUtf8("\u20B9 23"));
    ui->pushButton_6->setText(QString::fromUtf8("\u20B9 50"));
}
void MainWindow::on_pushButton_clicked(){
    reset();
    int value = ui->pushButton->text().remove(0,2).toInt() * ui->spinBox_val->value();
    sendMessingRequest(value);
}
void MainWindow::on_pushButton_2_clicked(){
    reset();
    int value = ui->pushButton_2->text().remove(0,2).toInt() * ui->spinBox_val->value();
    sendMessingRequest(value);
}
void MainWindow::on_pushButton_3_clicked(){
    reset();
    int value = ui->pushButton_3->text().remove(0,2).toInt() * ui->spinBox_val->value();
    sendMessingRequest(value);
}
void MainWindow::on_pushButton_4_clicked(){
    reset();
    int value = ui->pushButton_4->text().remove(0,2).toInt() * ui->spinBox_val->value();
    sendMessingRequest(value);
}
void MainWindow::on_pushButton_5_clicked(){
    reset();
    int value = ui->pushButton_5->text().remove(0,2).toInt() * ui->spinBox_val->value();
    sendMessingRequest(value);
}
void MainWindow::on_pushButton_6_clicked(){
    reset();
    int value = ui->pushButton_6->text().remove(0,2).toInt() * ui->spinBox_val->value();
    sendMessingRequest(value);
}
void MainWindow::on_toolButton_inc_2_clicked(){
    reset();
    if(ui->spinBox_val->value() >= 1)
        ui->spinBox_val->stepUp();
}
void MainWindow::on_toolButton_dec_2_clicked(){
    reset();
    if(ui->spinBox_val->value() > 1)
        ui->spinBox_val->stepDown();
}

