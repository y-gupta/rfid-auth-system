#include "confirmdialog.h"
#include "ui_confirmdialog.h"
#include <QDesktopWidget>

ConfirmDialog::ConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    this->setFixedSize(300,300);

    dummy_timer = new QTimer(this);
    dummy_timer->start(9000);
    connect(dummy_timer,SIGNAL(timeout()),this,SLOT(timeout()));
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint);
    this->move( QApplication::desktop()->rect().center()-this->rect().center());
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}
void ConfirmDialog::setString(string s){
    ui->label->setText(QString::fromStdString(s));
}
void ConfirmDialog::timeout(){
    this->close();
}
void ConfirmDialog::mousePressEvent(QMouseEvent *){
    this->close();
}
