#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PLACE_CARD 0
#define OPTION 1

void MainWindow::gotoAdmin(){
    ui->stackedWidget->setCurrentIndex(ADMIN);
    ui->pushButton_confirm_2->setDisabled(true);
    ui->toolButton_inc->setDisabled(true);
    ui->toolButton_dec->setDisabled(true);
}
void MainWindow::on_pushButton_allow_clicked(){reset();
    //TODO - check the request response part of
    gotoWelcome();
}
void MainWindow::on_pushButton_delete_clicked(){reset();
    ui->stackedWidget_admin->setCurrentIndex(PLACE_CARD);
    //TODO : READ the card and do the stuff

    ui->stackedWidget_admin->setCurrentIndex(OPTION);
    ui->pushButton_confirm_2->setEnabled(true);

}
void MainWindow::on_pushButton_reg_clicked(){reset();
    ui->stackedWidget_admin->setCurrentIndex(PLACE_CARD);
    //TODO : READ the card and do the stuff

    ui->stackedWidget_admin->setCurrentIndex(OPTION);
    ui->toolButton_dec->setEnabled(true);
    ui->toolButton_inc->setEnabled(true);
    ui->pushButton_confirm_2->setEnabled(true);

}
void MainWindow::on_pushButton_master_clicked(){reset();
    ui->stackedWidget_admin->setCurrentIndex(PLACE_CARD);
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
void MainWindow::on_pushButton_confirm_2_clicked(){reset();
    //TODO confirm stuff
    gotoWelcome();
}
