#include "userdialog.h"
#include "ui_userdialog.h"
#include <iostream>
using namespace std;
UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    this->setFixedSize(300,300);

    dummy_timer = new QTimer(this);
    dummy_timer->start(3000);
    connect(dummy_timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

UserDialog::~UserDialog()
{
    delete ui;
}
void UserDialog::mousePressEvent(QMouseEvent *){
    this->close();
}
void UserDialog::timeout(){
    this->close();
}
