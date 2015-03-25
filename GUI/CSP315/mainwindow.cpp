#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initRebateUi();
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
