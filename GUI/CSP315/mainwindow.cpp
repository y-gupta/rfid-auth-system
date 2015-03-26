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
    QPixmap pixmap(":/images/rupee.jpg");
    cout<<pixmap.isNull()<<endl;
    QIcon ButtonIcon(pixmap);

    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(QSize(60,60));

    ui->pushButton_2->setIcon(ButtonIcon);
    ui->pushButton_2->setIconSize(QSize(60,60));

    ui->pushButton_3->setIcon(ButtonIcon);
    ui->pushButton_3->setIconSize(QSize(60,60));

    ui->pushButton_4->setIcon(ButtonIcon);
    ui->pushButton_4->setIconSize(QSize(60,60));

    ui->pushButton_5->setIcon(ButtonIcon);
    ui->pushButton_5->setIconSize(QSize(60,60));

    ui->pushButton_6->setIcon(ButtonIcon);
    ui->pushButton_6->setIconSize(QSize(60,60));
}

MainWindow::~MainWindow()
{
    delete ui;
}
