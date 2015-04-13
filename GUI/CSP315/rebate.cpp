#include "mainwindow.h"
#include "network.h"
#include "ui_mainwindow.h"

void MainWindow::checkRebateUi(){
    QDate cur_date = QDate::currentDate();
    QDate pre_date = ui->dateEdit_present->date();
    QDate fut_date = ui->dateEdit_future->date();

    if(pre_date==cur_date)
        ui->toolButton_dec_present->setDisabled(true);
    else
        ui->toolButton_dec_present->setEnabled(true);

    if(fut_date <= pre_date){
        ui->dateEdit_future->setDate(pre_date);
        ui->toolButton_dec_future->setDisabled(true);
    }
    else{
        ui->toolButton_dec_future->setEnabled(true);
    }
}
void MainWindow::on_toolButton_inc_present_clicked(){
    reset();
    QDate tmp = ui->dateEdit_present->date();
    ui->dateEdit_present->setDate(tmp.addDays(1));
    checkRebateUi();
}
void MainWindow::on_toolButton_inc_future_clicked(){
    reset();
    QDate tmp = ui->dateEdit_future->date();
    ui->dateEdit_future->setDate(tmp.addDays(1));
    checkRebateUi();
}
void MainWindow::on_toolButton_dec_present_clicked(){
    reset();
    QDate tmp = ui->dateEdit_present->date();
    ui->dateEdit_present->setDate(tmp.addDays(-1));
    checkRebateUi();
}
void MainWindow::on_toolButton_dec_future_clicked(){
    reset();
    QDate tmp = ui->dateEdit_future->date();
    ui->dateEdit_future->setDate(tmp.addDays(-1));
    checkRebateUi();
}
void MainWindow::sendRebateRequest(int nmeals,string start,string end){
    current_user.start=start;
    current_user.end=end;
    RebateRequest req;
    req.init(device.mac,current_user.rfid,nmeals,start,end);
    Network::sendRequest(&req);
    attendRequest=-1;
    attendResponse=REBATE_REQ;
}
void MainWindow::on_pushButton_7_clicked(){
    reset();
    sendRebateRequest(1);
}
void MainWindow::on_pushButton_8_clicked(){
    reset();
    sendRebateRequest(3);
}
void MainWindow::on_pushButton_9_clicked(){
    reset();
    sendRebateRequest(5);
}
void MainWindow::on_pushButton_confirm_clicked(){
    reset();
    string start = ui->dateEdit_present->date().toString("dd/MM/yy").toStdString();
    string end = ui->dateEdit_future->date().toString("dd/MM/yy").toStdString();
    sendRebateRequest(0,start,end);
}
