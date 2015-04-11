#include "userdialog.h"
#include "ui_userdialog.h"

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    this->setFixedSize(300,300);
}

UserDialog::~UserDialog()
{
    delete ui;
}
void UserDialog::mousePressEvent(QMouseEvent *){
    this->close();
}
