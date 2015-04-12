#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    QTimer *dummy_timer;
    void mousePressEvent(QMouseEvent *);
private:
    Ui::UserDialog *ui;

public slots:
    void timeout();
};

#endif // USERDIALOG_H
