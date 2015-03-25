#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_optionwindow.h"
#include "../printer/printer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    // This is the global printer object for each application
    printer my_printer;

    ~MainWindow();

private slots:

    void on_toolButton_inc_present_clicked();

    void on_toolButton_inc_future_clicked();

    void on_toolButton_dec_present_clicked();

    void on_toolButton_dec_future_clicked();

    //These are the messing buttons part
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_toolButton_inc_2_clicked();

    void on_toolButton_dec_2_clicked();

    //These are the staff login buttons
    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_enter_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
