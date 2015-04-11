#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    void mousePressEvent(QMouseEvent *);
private:
    Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
