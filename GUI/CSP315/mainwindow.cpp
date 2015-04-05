#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMouseTracking(true);
    ui->setupUi(this);
    time_out=3;
    Network::init("192.168.0.4/");
    connect(this,SIGNAL(TIMEOUT()),this,SLOT(timeout()));
    initWelcomeUi();
    initEventLoop();
    gotoAdmin();

//    initWelcomeUi();
//    checkWelcomeUi();
//    gotoGeneral();

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
    installEventFilter(this);
}
MainWindow::~MainWindow()
{
    delete ui;
    removeEventFilter(this);
}
void MainWindow::on_toolButton_home_clicked(){reset();
    gotoWelcome();
}
void MainWindow::timeout(){
    gotoWelcome();
}
void MainWindow::reset(){
    idle_time=0;
}
void MainWindow::processAuthResponse(User usr){
    cout<<usr.user_name<<endl;
    cout<<usr.hostel_name<<endl;
}
