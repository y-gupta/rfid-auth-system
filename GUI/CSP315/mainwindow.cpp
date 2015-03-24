#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit_present->setDate(QDate::currentDate());
    ui->dateEdit_future->setDate(QDate::currentDate().addDays(1));
    ui->stackedWidget->addWidget(new QWidget);

    //TODO - Set the date and time
    ui->label_time->setText(QString::fromStdString("Date : " +
    QDate::currentDate().toString("dd/MM/yy").toStdString() + "\nTime : " +
    QTime::currentTime().toString("hh:mm:ss").toStdString() + " "));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_inc_present_clicked()
{
    QDate tmp = ui->dateEdit_present->date();
    ui->dateEdit_present->setDate(tmp.addDays(1));
}

void MainWindow::on_toolButton_inc_future_clicked()
{
    QDate tmp = ui->dateEdit_future->date();
    ui->dateEdit_future->setDate(tmp.addDays(1));
}

void MainWindow::on_toolButton_dec_present_clicked()
{
    QDate tmp = ui->dateEdit_present->date();
    ui->dateEdit_present->setDate(tmp.addDays(-1));
}

void MainWindow::on_toolButton_dec_future_clicked()
{
    QDate tmp = ui->dateEdit_future->date();
    ui->dateEdit_future->setDate(tmp.addDays(-1));
}
