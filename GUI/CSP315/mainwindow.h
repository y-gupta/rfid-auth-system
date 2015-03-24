#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_optionwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_toolButton_inc_present_clicked();

    void on_toolButton_inc_future_clicked();

    void on_toolButton_dec_present_clicked();

    void on_toolButton_dec_future_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
