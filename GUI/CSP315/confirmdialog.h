#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>
#include <QTimer>
#include <iostream>
using namespace std;

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = 0);
    ~ConfirmDialog();
    QTimer *dummy_timer;
    void mousePressEvent(QMouseEvent *);
    void setString(string s);
private:
    Ui::ConfirmDialog *ui;

public slots:
    void timeout();
};

#endif // CONFIRMDIALOG_H
