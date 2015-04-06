#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../printer/printer.h"
#include "../rfid/rfid.h"
#include "user.h"
#include "utility.cpp"
#include "request.h"

#include <vector>
#include <QTimer>
#include <cstring>

using namespace std;

#define WELCOME 0
#define GENERAL 1
#define ADMIN 2
#define STAFF_LOGIN 3


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

    //Timeout helper function
    int time_out;
    int idle_time;
    void reset();

    //Extra information
    User current_user;
    uint64_t device_id;
    //Event loop helper functions
    QTimer *timer;
    int sec_count;
    void initEventLoop();    
    int read_card;
    void doReadCard(int64_t);
    bool attendRequest;
    int attendResponse;

    //Welcome helper functions
    vector< pair<QTime,QTime> > timing;
    void initWelcomeUi();
    void gotoWelcome();
    void checkWelcomeUi();
    void setUpMealTimeUi();
    void setUpNoMealTimeUi();

    //General helper functions
    void gotoGeneral();
    void checkRebateUi();

    //Admin helper function
    void gotoAdmin();

    //Staff Login helper functions
    void gotoStaffLogin();

    //Processing the response functions
    void processAuthResponse(User usr);
    void processCreateMasterCardResponse();
    void processCreateNewCardResponse();
    void processDeleteCardResponse();
    void processAllowTempResponse(bool isSuccess);


public slots:
    //Event loop helper slots
    void doEvent();
    void timeout();

signals:
    void TIMEOUT();
private slots:

    //These are the rebate buttons
    void on_toolButton_inc_present_clicked();
    void on_toolButton_inc_future_clicked();
    void on_toolButton_dec_present_clicked();
    void on_toolButton_dec_future_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

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
    void on_pushButton_staff_login_clicked();

    //These are MainWindow buttons
    void on_toolButton_home_clicked();

    //There are admin buttons
    void on_pushButton_allow_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_reg_clicked();
    void on_pushButton_master_clicked();
    void on_toolButton_inc_clicked();
    void on_toolButton_dec_clicked();
    void on_pushButton_confirm_2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
