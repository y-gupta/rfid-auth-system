#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

#define TEXT 0
#define OPTION 1

void MainWindow::gotoAdmin(){
    ui->stackedWidget->setCurrentIndex(ADMIN);
    ui->stackedWidget_admin->setAcceptDrops(TEXT);
    ui->label_notification->setText("Select any one!");
}
void MainWindow::on_pushButton_allow_clicked(){
    reset();
    Request *r=new Request;
    r->type=ALLOW_TEMP;
    Network::sendRequest(r);
    ui->label_notification->setText("Your request is being processed!");
}
void MainWindow::on_pushButton_delete_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    read_card = DELETE_CARD;
    attendRequest=false;
}
void MainWindow::on_pushButton_reg_clicked(){
    reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    read_card = CREATE_NEW_CARD;
    //TODO : READ the card and do the stuff

    ui->stackedWidget_admin->setCurrentIndex(OPTION);
    ui->toolButton_dec->setEnabled(true);
    ui->toolButton_inc->setEnabled(true);
    ui->pushButton_confirm_2->setEnabled(true);

}
void MainWindow::on_pushButton_master_clicked(){reset();
    ui->stackedWidget_admin->setCurrentIndex(TEXT);
    //TODO : READ the card and do the stuff

    ui->stackedWidget_admin->setCurrentIndex(OPTION);
    ui->pushButton_confirm_2->setEnabled(true);
}
void MainWindow::on_toolButton_inc_clicked(){reset();
    if(ui->spinBox_days->value()>=1)
    ui->spinBox_days->stepUp();
}
void MainWindow::on_toolButton_dec_clicked(){reset();
    if(ui->spinBox_days->value() > 1)
    ui->spinBox_days->stepDown();
}
void MainWindow::on_pushButton_confirm_2_clicked(){
    attendRequest=true;
    reset();
    gotoWelcome();
}
