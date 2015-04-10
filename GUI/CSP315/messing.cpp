#include "mainwindow.h"
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
    ui->label_name->setText(QString::fromStdString(current_user.user_name));
    ui->label_hostel_1->setText(QString::fromStdString(current_user.hostel_name));
    ui->label_id->setText(QString::fromStdString(current_user.entry_no));
}
void MainWindow::on_pushButton_clicked(){reset();
    int value = ui->pushButton->text().toInt() * ui->spinBox_val->value();
    my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_2_clicked(){reset();
    int value = ui->pushButton_2->text().toInt() * ui->spinBox_val->value();
    my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_3_clicked(){reset();
    int value = ui->pushButton_3->text().toInt() * ui->spinBox_val->value();
    my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_4_clicked(){reset();
    int value = ui->pushButton_4->text().toInt() * ui->spinBox_val->value();
    my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_5_clicked(){reset();
    int value = ui->pushButton_5->text().toInt() * ui->spinBox_val->value();
    my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_pushButton_6_clicked(){reset();
    int value = ui->pushButton_6->text().toInt() * ui->spinBox_val->value();
    my_printer.extra_messing(current_user,to_string(value));
}
void MainWindow::on_toolButton_inc_2_clicked(){reset();
    if(ui->spinBox_val->value() >= 1)
        ui->spinBox_val->stepUp();
}
void MainWindow::on_toolButton_dec_2_clicked(){reset();
    if(ui->spinBox_val->value() > 1)
        ui->spinBox_val->stepDown();
}

