#include "mainwindow.h"
#include "network.h"
#include "ui_mainwindow.h"

#define MESSING 0
#define REBATE 1

void MainWindow::gotoGeneral(){
    ui->stackedWidget->setCurrentIndex(GENERAL);

    //Initializing the rebate
    ui->dateEdit_present->setDate(QDate::currentDate());
    ui->dateEdit_future->setDate(QDate::currentDate());
    checkRebateUi();
    
    //Initializing the extra-messing
    ui->tabWidget_option->setCurrentIndex(MESSING);
    ui->spinBox_val->setValue(1);

    //Initializing the current user details
//    current_user.user_name="Rishit Sanmukhani";
//    current_user.hostel_name="Zanskar hostel";
//    current_user.entry_no="2013CS10255";
    ui->label_name->setText(QString::fromStdString(current_user.user_name));
    ui->label_hostel_1->setText(QString::fromStdString(current_user.hostel_name));
    ui->label_id->setText(QString::fromStdString(current_user.entry_no));
    UserDialog dialog;
    dialog.show();
    cout<<"Before entering loop"<<endl;
    dialog.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    dialog.exec();

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
    MessingRequest req;
   req.init(device.mac,current_user.rfid,value);
    Network::sendRequest(&req);
    //TODO remove this from here
   // my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_2_clicked(){
    reset();
    int value = ui->pushButton_2->text().remove(0,2).toInt() * ui->spinBox_val->value();
    MessingRequest req;
   req.init(device.mac,current_user.rfid,value);
    Network::sendRequest(&req);
    //TODO remove this from her
    //my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_3_clicked(){
    reset();
    int value = ui->pushButton_3->text().remove(0,2).toInt() * ui->spinBox_val->value();
    MessingRequest req;
   req.init(device.mac,current_user.rfid,value);
    Network::sendRequest(&req);
    //TODO remove this from her
 //   my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_4_clicked(){
    reset();
    int value = ui->pushButton_4->text().remove(0,2).toInt() * ui->spinBox_val->value();
    MessingRequest req;
   req.init(device.mac,current_user.rfid,value);
    Network::sendRequest(&req);
    //TODO remove this from her
   // my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_5_clicked(){
    reset();
    int value = ui->pushButton_5->text().remove(0,2).toInt() * ui->spinBox_val->value();
    MessingRequest req;
   req.init(device.mac,current_user.rfid,value);
    Network::sendRequest(&req);
    //TODO remove this from her
    //my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_6_clicked(){
    reset();
    int value = ui->pushButton_6->text().remove(0,2).toInt() * ui->spinBox_val->value();
    MessingRequest req;
   req.init(device.mac,current_user.rfid,value);
    Network::sendRequest(&req);
    //TODO remove this from her
    //my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_toolButton_inc_2_clicked(){reset();
    if(ui->spinBox_val->value() >= 1)
        ui->spinBox_val->stepUp();
}
void MainWindow::on_toolButton_dec_2_clicked(){reset();
    if(ui->spinBox_val->value() > 1)
        ui->spinBox_val->stepDown();
}

