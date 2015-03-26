/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *welcome;
    QGridLayout *gridLayout;
    QLabel *label_hostel_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_developed;
    QPushButton *pushButton_staff_login;
    QLabel *label_time;
    QLabel *label_time_status;
    QFrame *frame_graph;
    QGridLayout *gridLayout_11;
    QStackedWidget *stackedWidget_graph;
    QWidget *page_meal_2;
    QWidget *page_no_meal_2;
    QLabel *label_3;
    QFrame *frame_statistics;
    QGridLayout *gridLayout_10;
    QStackedWidget *stackedWidget_statistics;
    QWidget *page_meal;
    QGridLayout *gridLayout_12;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *page_no_meal;
    QGridLayout *gridLayout_13;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label;
    QWidget *general;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QLabel *label_hostel_1;
    QTabWidget *tabWidget_option;
    QWidget *extra_messing;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_3;
    QGridLayout *gridLayout_18;
    QSpinBox *spinBox_val;
    QLabel *label_13;
    QToolButton *toolButton_inc_2;
    QToolButton *toolButton_dec_2;
    QWidget *rebate;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frame;
    QGridLayout *gridLayout_9;
    QLabel *label_2;
    QToolButton *toolButton_inc_present;
    QToolButton *toolButton_inc_future;
    QDateEdit *dateEdit_present;
    QDateEdit *dateEdit_future;
    QToolButton *toolButton_dec_present;
    QToolButton *toolButton_dec_future;
    QPushButton *pushButton_confirm;
    QWidget *admin;
    QGridLayout *gridLayout_14;
    QLabel *label_admin;
    QPushButton *pushButton_master;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_allow;
    QFrame *frame_2;
    QGridLayout *gridLayout_15;
    QStackedWidget *stackedWidget_admin;
    QWidget *page_4;
    QWidget *page_5;
    QGridLayout *gridLayout_16;
    QLabel *label_4;
    QLabel *label_card;
    QLabel *label_card_num;
    QLabel *label_9;
    QToolButton *toolButton_inc;
    QSpinBox *spinBox_days;
    QToolButton *toolButton_dec;
    QPushButton *pushButton_confirm_2;
    QWidget *login;
    QGridLayout *gridLayout_17;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_14;
    QPushButton *pushButton_17;
    QPushButton *pushButton_12;
    QPushButton *pushButton_16;
    QPushButton *pushButton_18;
    QPushButton *pushButton_10;
    QLabel *label_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
    QLabel *label_staff;
    QPushButton *pushButton_11;
    QPushButton *pushButton_del;
    QPushButton *pushButton_20;
    QPushButton *pushButton_enter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1094, 486);
        MainWindow->setMinimumSize(QSize(1094, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        welcome = new QWidget();
        welcome->setObjectName(QStringLiteral("welcome"));
        gridLayout = new QGridLayout(welcome);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_hostel_2 = new QLabel(welcome);
        label_hostel_2->setObjectName(QStringLiteral("label_hostel_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_hostel_2->sizePolicy().hasHeightForWidth());
        label_hostel_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        label_hostel_2->setFont(font);
        label_hostel_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_hostel_2, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_developed = new QLabel(welcome);
        label_developed->setObjectName(QStringLiteral("label_developed"));
        QFont font1;
        font1.setPointSize(16);
        font1.setItalic(true);
        label_developed->setFont(font1);

        horizontalLayout_2->addWidget(label_developed);

        pushButton_staff_login = new QPushButton(welcome);
        pushButton_staff_login->setObjectName(QStringLiteral("pushButton_staff_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_staff_login->sizePolicy().hasHeightForWidth());
        pushButton_staff_login->setSizePolicy(sizePolicy1);
        pushButton_staff_login->setMaximumSize(QSize(16777215, 100));
        QFont font2;
        font2.setPointSize(16);
        pushButton_staff_login->setFont(font2);

        horizontalLayout_2->addWidget(pushButton_staff_login);

        label_time = new QLabel(welcome);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setFont(font2);
        label_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_time);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);

        label_time_status = new QLabel(welcome);
        label_time_status->setObjectName(QStringLiteral("label_time_status"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_time_status->sizePolicy().hasHeightForWidth());
        label_time_status->setSizePolicy(sizePolicy2);
        label_time_status->setMaximumSize(QSize(16777215, 100));
        QFont font3;
        font3.setPointSize(30);
        label_time_status->setFont(font3);
        label_time_status->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_time_status, 2, 0, 1, 2);

        frame_graph = new QFrame(welcome);
        frame_graph->setObjectName(QStringLiteral("frame_graph"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_graph->sizePolicy().hasHeightForWidth());
        frame_graph->setSizePolicy(sizePolicy3);
        frame_graph->setFrameShape(QFrame::StyledPanel);
        frame_graph->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_graph);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        stackedWidget_graph = new QStackedWidget(frame_graph);
        stackedWidget_graph->setObjectName(QStringLiteral("stackedWidget_graph"));
        stackedWidget_graph->setStyleSheet(QStringLiteral("border-image : url(../Resources/graph.jpg) 0 0 0 0 stretch stretch;"));
        page_meal_2 = new QWidget();
        page_meal_2->setObjectName(QStringLiteral("page_meal_2"));
        stackedWidget_graph->addWidget(page_meal_2);
        page_no_meal_2 = new QWidget();
        page_no_meal_2->setObjectName(QStringLiteral("page_no_meal_2"));
        stackedWidget_graph->addWidget(page_no_meal_2);

        gridLayout_11->addWidget(stackedWidget_graph, 1, 0, 1, 1);

        label_3 = new QLabel(frame_graph);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_3, 0, 0, 1, 1);


        gridLayout->addWidget(frame_graph, 1, 1, 1, 1);

        frame_statistics = new QFrame(welcome);
        frame_statistics->setObjectName(QStringLiteral("frame_statistics"));
        sizePolicy3.setHeightForWidth(frame_statistics->sizePolicy().hasHeightForWidth());
        frame_statistics->setSizePolicy(sizePolicy3);
        frame_statistics->setFrameShape(QFrame::StyledPanel);
        frame_statistics->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_statistics);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        stackedWidget_statistics = new QStackedWidget(frame_statistics);
        stackedWidget_statistics->setObjectName(QStringLiteral("stackedWidget_statistics"));
        page_meal = new QWidget();
        page_meal->setObjectName(QStringLiteral("page_meal"));
        gridLayout_12 = new QGridLayout(page_meal);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_5 = new QLabel(page_meal);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font5;
        font5.setPointSize(26);
        label_5->setFont(font5);

        gridLayout_12->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(page_meal);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font5);

        gridLayout_12->addWidget(label_6, 0, 1, 1, 1);

        label_7 = new QLabel(page_meal);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font5);

        gridLayout_12->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(page_meal);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font5);

        gridLayout_12->addWidget(label_8, 1, 1, 1, 1);

        stackedWidget_statistics->addWidget(page_meal);
        page_no_meal = new QWidget();
        page_no_meal->setObjectName(QStringLiteral("page_no_meal"));
        gridLayout_13 = new QGridLayout(page_no_meal);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_10 = new QLabel(page_no_meal);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font5);

        gridLayout_13->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(page_no_meal);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font5);

        gridLayout_13->addWidget(label_11, 0, 1, 1, 1);

        stackedWidget_statistics->addWidget(page_no_meal);

        gridLayout_10->addWidget(stackedWidget_statistics, 1, 0, 1, 1);

        label = new QLabel(frame_statistics);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(frame_statistics, 1, 0, 1, 1);

        stackedWidget->addWidget(welcome);
        general = new QWidget();
        general->setObjectName(QStringLiteral("general"));
        gridLayout_8 = new QGridLayout(general);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_name = new QLabel(general);
        label_name->setObjectName(QStringLiteral("label_name"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_name->sizePolicy().hasHeightForWidth());
        label_name->setSizePolicy(sizePolicy4);
        QFont font6;
        font6.setPointSize(32);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        label_name->setFont(font6);
        label_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_name, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(general);
        label_id->setObjectName(QStringLiteral("label_id"));
        QFont font7;
        font7.setPointSize(18);
        label_id->setFont(font7);

        horizontalLayout->addWidget(label_id);

        label_hostel_1 = new QLabel(general);
        label_hostel_1->setObjectName(QStringLiteral("label_hostel_1"));
        label_hostel_1->setFont(font7);
        label_hostel_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_hostel_1);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        tabWidget_option = new QTabWidget(general);
        tabWidget_option->setObjectName(QStringLiteral("tabWidget_option"));
        tabWidget_option->setBaseSize(QSize(0, 0));
        QFont font8;
        font8.setPointSize(20);
        font8.setBold(true);
        font8.setWeight(75);
        tabWidget_option->setFont(font8);
        tabWidget_option->setIconSize(QSize(16, 16));
        extra_messing = new QWidget();
        extra_messing->setObjectName(QStringLiteral("extra_messing"));
        gridLayout_4 = new QGridLayout(extra_messing);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton = new QPushButton(extra_messing);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(extra_messing);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(extra_messing);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(extra_messing);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy3.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(extra_messing);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(extra_messing);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy3.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(pushButton_6, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_6, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        frame_3 = new QFrame(extra_messing);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy5);
        frame_3->setMaximumSize(QSize(400, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame_3);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        spinBox_val = new QSpinBox(frame_3);
        spinBox_val->setObjectName(QStringLiteral("spinBox_val"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_val->sizePolicy().hasHeightForWidth());
        spinBox_val->setSizePolicy(sizePolicy6);
        QFont font9;
        font9.setKerning(true);
        spinBox_val->setFont(font9);
        spinBox_val->setFocusPolicy(Qt::WheelFocus);
        spinBox_val->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_val->setStyleSheet(QLatin1String("spinBox_val:focus{\n"
"border:none;\n"
"outline:none\n"
"}"));
        spinBox_val->setFrame(false);
        spinBox_val->setAlignment(Qt::AlignCenter);
        spinBox_val->setReadOnly(true);
        spinBox_val->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_val->setAccelerated(true);
        spinBox_val->setKeyboardTracking(true);
        spinBox_val->setValue(1);

        gridLayout_18->addWidget(spinBox_val, 2, 0, 1, 1);

        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font10;
        font10.setPointSize(12);
        label_13->setFont(font10);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_13, 0, 0, 1, 1);

        toolButton_inc_2 = new QToolButton(frame_3);
        toolButton_inc_2->setObjectName(QStringLiteral("toolButton_inc_2"));
        sizePolicy3.setHeightForWidth(toolButton_inc_2->sizePolicy().hasHeightForWidth());
        toolButton_inc_2->setSizePolicy(sizePolicy3);
        toolButton_inc_2->setFocusPolicy(Qt::TabFocus);

        gridLayout_18->addWidget(toolButton_inc_2, 1, 0, 1, 1);

        toolButton_dec_2 = new QToolButton(frame_3);
        toolButton_dec_2->setObjectName(QStringLiteral("toolButton_dec_2"));
        sizePolicy3.setHeightForWidth(toolButton_dec_2->sizePolicy().hasHeightForWidth());
        toolButton_dec_2->setSizePolicy(sizePolicy3);

        gridLayout_18->addWidget(toolButton_dec_2, 3, 0, 1, 1);


        gridLayout_4->addWidget(frame_3, 1, 3, 1, 1);

        tabWidget_option->addTab(extra_messing, QString());
        rebate = new QWidget();
        rebate->setObjectName(QStringLiteral("rebate"));
        gridLayout_6 = new QGridLayout(rebate);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_9 = new QPushButton(rebate);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy3.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(pushButton_9, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(rebate);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy3.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(rebate);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy3.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(pushButton_8, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_4, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        frame = new QFrame(rebate);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy7);
        label_2->setBaseSize(QSize(0, 0));
        label_2->setFont(font10);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_2, 0, 0, 1, 2);

        toolButton_inc_present = new QToolButton(frame);
        toolButton_inc_present->setObjectName(QStringLiteral("toolButton_inc_present"));
        sizePolicy3.setHeightForWidth(toolButton_inc_present->sizePolicy().hasHeightForWidth());
        toolButton_inc_present->setSizePolicy(sizePolicy3);

        gridLayout_9->addWidget(toolButton_inc_present, 1, 0, 1, 1);

        toolButton_inc_future = new QToolButton(frame);
        toolButton_inc_future->setObjectName(QStringLiteral("toolButton_inc_future"));
        sizePolicy3.setHeightForWidth(toolButton_inc_future->sizePolicy().hasHeightForWidth());
        toolButton_inc_future->setSizePolicy(sizePolicy3);

        gridLayout_9->addWidget(toolButton_inc_future, 1, 1, 1, 1);

        dateEdit_present = new QDateEdit(frame);
        dateEdit_present->setObjectName(QStringLiteral("dateEdit_present"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(dateEdit_present->sizePolicy().hasHeightForWidth());
        dateEdit_present->setSizePolicy(sizePolicy8);
        dateEdit_present->setAlignment(Qt::AlignCenter);
        dateEdit_present->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_9->addWidget(dateEdit_present, 2, 0, 1, 1);

        dateEdit_future = new QDateEdit(frame);
        dateEdit_future->setObjectName(QStringLiteral("dateEdit_future"));
        sizePolicy8.setHeightForWidth(dateEdit_future->sizePolicy().hasHeightForWidth());
        dateEdit_future->setSizePolicy(sizePolicy8);
        dateEdit_future->setAlignment(Qt::AlignCenter);
        dateEdit_future->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_9->addWidget(dateEdit_future, 2, 1, 1, 1);

        toolButton_dec_present = new QToolButton(frame);
        toolButton_dec_present->setObjectName(QStringLiteral("toolButton_dec_present"));
        sizePolicy3.setHeightForWidth(toolButton_dec_present->sizePolicy().hasHeightForWidth());
        toolButton_dec_present->setSizePolicy(sizePolicy3);

        gridLayout_9->addWidget(toolButton_dec_present, 3, 0, 1, 1);

        toolButton_dec_future = new QToolButton(frame);
        toolButton_dec_future->setObjectName(QStringLiteral("toolButton_dec_future"));
        sizePolicy3.setHeightForWidth(toolButton_dec_future->sizePolicy().hasHeightForWidth());
        toolButton_dec_future->setSizePolicy(sizePolicy3);

        gridLayout_9->addWidget(toolButton_dec_future, 3, 1, 1, 1);

        pushButton_confirm = new QPushButton(frame);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        sizePolicy3.setHeightForWidth(pushButton_confirm->sizePolicy().hasHeightForWidth());
        pushButton_confirm->setSizePolicy(sizePolicy3);

        gridLayout_9->addWidget(pushButton_confirm, 4, 0, 1, 2);


        gridLayout_6->addWidget(frame, 0, 3, 3, 1);

        tabWidget_option->addTab(rebate, QString());

        verticalLayout_2->addWidget(tabWidget_option);


        gridLayout_8->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(general);
        admin = new QWidget();
        admin->setObjectName(QStringLiteral("admin"));
        gridLayout_14 = new QGridLayout(admin);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_admin = new QLabel(admin);
        label_admin->setObjectName(QStringLiteral("label_admin"));
        label_admin->setFont(font);
        label_admin->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_admin, 0, 0, 1, 4);

        pushButton_master = new QPushButton(admin);
        pushButton_master->setObjectName(QStringLiteral("pushButton_master"));
        sizePolicy8.setHeightForWidth(pushButton_master->sizePolicy().hasHeightForWidth());
        pushButton_master->setSizePolicy(sizePolicy8);
        pushButton_master->setMaximumSize(QSize(16777215, 100));
        pushButton_master->setFont(font5);

        gridLayout_14->addWidget(pushButton_master, 1, 0, 1, 1);

        pushButton_reg = new QPushButton(admin);
        pushButton_reg->setObjectName(QStringLiteral("pushButton_reg"));
        sizePolicy8.setHeightForWidth(pushButton_reg->sizePolicy().hasHeightForWidth());
        pushButton_reg->setSizePolicy(sizePolicy8);
        pushButton_reg->setMaximumSize(QSize(16777215, 100));
        pushButton_reg->setFont(font5);

        gridLayout_14->addWidget(pushButton_reg, 1, 1, 1, 1);

        pushButton_delete = new QPushButton(admin);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        sizePolicy8.setHeightForWidth(pushButton_delete->sizePolicy().hasHeightForWidth());
        pushButton_delete->setSizePolicy(sizePolicy8);
        pushButton_delete->setMaximumSize(QSize(16777215, 100));
        pushButton_delete->setFont(font5);

        gridLayout_14->addWidget(pushButton_delete, 1, 2, 1, 1);

        pushButton_allow = new QPushButton(admin);
        pushButton_allow->setObjectName(QStringLiteral("pushButton_allow"));
        sizePolicy8.setHeightForWidth(pushButton_allow->sizePolicy().hasHeightForWidth());
        pushButton_allow->setSizePolicy(sizePolicy8);
        pushButton_allow->setMaximumSize(QSize(16777215, 100));
        pushButton_allow->setFont(font5);

        gridLayout_14->addWidget(pushButton_allow, 1, 3, 1, 1);

        frame_2 = new QFrame(admin);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy3.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy3);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_2);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        stackedWidget_admin = new QStackedWidget(frame_2);
        stackedWidget_admin->setObjectName(QStringLiteral("stackedWidget_admin"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget_admin->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        gridLayout_16 = new QGridLayout(page_5);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_4, 0, 0, 1, 4);

        label_card = new QLabel(page_5);
        label_card->setObjectName(QStringLiteral("label_card"));
        sizePolicy5.setHeightForWidth(label_card->sizePolicy().hasHeightForWidth());
        label_card->setSizePolicy(sizePolicy5);
        label_card->setFont(font2);

        gridLayout_16->addWidget(label_card, 1, 0, 1, 1);

        label_card_num = new QLabel(page_5);
        label_card_num->setObjectName(QStringLiteral("label_card_num"));
        sizePolicy2.setHeightForWidth(label_card_num->sizePolicy().hasHeightForWidth());
        label_card_num->setSizePolicy(sizePolicy2);
        label_card_num->setFont(font5);
        label_card_num->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_card_num, 1, 1, 1, 3);

        label_9 = new QLabel(page_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy5.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy5);
        label_9->setFont(font2);

        gridLayout_16->addWidget(label_9, 2, 0, 1, 1);

        toolButton_inc = new QToolButton(page_5);
        toolButton_inc->setObjectName(QStringLiteral("toolButton_inc"));
        sizePolicy3.setHeightForWidth(toolButton_inc->sizePolicy().hasHeightForWidth());
        toolButton_inc->setSizePolicy(sizePolicy3);
        toolButton_inc->setFont(font5);

        gridLayout_16->addWidget(toolButton_inc, 2, 1, 1, 1);

        spinBox_days = new QSpinBox(page_5);
        spinBox_days->setObjectName(QStringLiteral("spinBox_days"));
        sizePolicy3.setHeightForWidth(spinBox_days->sizePolicy().hasHeightForWidth());
        spinBox_days->setSizePolicy(sizePolicy3);
        spinBox_days->setFont(font5);
        spinBox_days->setAlignment(Qt::AlignCenter);
        spinBox_days->setReadOnly(false);
        spinBox_days->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_days->setKeyboardTracking(true);

        gridLayout_16->addWidget(spinBox_days, 2, 2, 1, 1);

        toolButton_dec = new QToolButton(page_5);
        toolButton_dec->setObjectName(QStringLiteral("toolButton_dec"));
        sizePolicy3.setHeightForWidth(toolButton_dec->sizePolicy().hasHeightForWidth());
        toolButton_dec->setSizePolicy(sizePolicy3);
        toolButton_dec->setFont(font5);

        gridLayout_16->addWidget(toolButton_dec, 2, 3, 1, 1);

        pushButton_confirm_2 = new QPushButton(page_5);
        pushButton_confirm_2->setObjectName(QStringLiteral("pushButton_confirm_2"));
        sizePolicy8.setHeightForWidth(pushButton_confirm_2->sizePolicy().hasHeightForWidth());
        pushButton_confirm_2->setSizePolicy(sizePolicy8);
        pushButton_confirm_2->setFont(font5);

        gridLayout_16->addWidget(pushButton_confirm_2, 3, 0, 1, 4);

        stackedWidget_admin->addWidget(page_5);

        gridLayout_15->addWidget(stackedWidget_admin, 0, 0, 1, 1);


        gridLayout_14->addWidget(frame_2, 2, 0, 1, 4);

        stackedWidget->addWidget(admin);
        login = new QWidget();
        login->setObjectName(QStringLiteral("login"));
        login->setMinimumSize(QSize(1076, 0));
        gridLayout_17 = new QGridLayout(login);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        lineEdit_password = new QLineEdit(login);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        sizePolicy3.setHeightForWidth(lineEdit_password->sizePolicy().hasHeightForWidth());
        lineEdit_password->setSizePolicy(sizePolicy3);
        lineEdit_password->setMaximumSize(QSize(16777215, 80));
        lineEdit_password->setFont(font5);
        lineEdit_password->setMaxLength(4);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_password->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(lineEdit_password, 1, 1, 1, 2);

        pushButton_14 = new QPushButton(login);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy3.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy3);
        pushButton_14->setFont(font5);

        gridLayout_17->addWidget(pushButton_14, 5, 1, 1, 1);

        pushButton_17 = new QPushButton(login);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy3.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy3);
        pushButton_17->setFont(font5);

        gridLayout_17->addWidget(pushButton_17, 6, 1, 1, 1);

        pushButton_12 = new QPushButton(login);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy3.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy3);
        pushButton_12->setFont(font5);

        gridLayout_17->addWidget(pushButton_12, 4, 2, 1, 1);

        pushButton_16 = new QPushButton(login);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy3.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy3);
        pushButton_16->setFont(font5);

        gridLayout_17->addWidget(pushButton_16, 6, 0, 1, 1);

        pushButton_18 = new QPushButton(login);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy3.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy3);
        pushButton_18->setFont(font5);

        gridLayout_17->addWidget(pushButton_18, 6, 2, 1, 1);

        pushButton_10 = new QPushButton(login);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy3.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy3);
        pushButton_10->setFont(font5);

        gridLayout_17->addWidget(pushButton_10, 4, 0, 1, 1);

        label_12 = new QLabel(login);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setFont(font5);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_12, 1, 0, 1, 1);

        pushButton_13 = new QPushButton(login);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy3.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy3);
        pushButton_13->setFont(font5);

        gridLayout_17->addWidget(pushButton_13, 5, 0, 1, 1);

        pushButton_15 = new QPushButton(login);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy3.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy3);
        pushButton_15->setFont(font5);

        gridLayout_17->addWidget(pushButton_15, 5, 2, 1, 1);

        label_staff = new QLabel(login);
        label_staff->setObjectName(QStringLiteral("label_staff"));
        label_staff->setFont(font);
        label_staff->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_staff, 0, 0, 1, 3);

        pushButton_11 = new QPushButton(login);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy3.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy3);
        pushButton_11->setFont(font5);

        gridLayout_17->addWidget(pushButton_11, 4, 1, 1, 1);

        pushButton_del = new QPushButton(login);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));
        sizePolicy3.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy3);
        pushButton_del->setFont(font5);

        gridLayout_17->addWidget(pushButton_del, 7, 0, 1, 1);

        pushButton_20 = new QPushButton(login);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy3.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy3);
        pushButton_20->setFont(font5);

        gridLayout_17->addWidget(pushButton_20, 7, 1, 1, 1);

        pushButton_enter = new QPushButton(login);
        pushButton_enter->setObjectName(QStringLiteral("pushButton_enter"));
        sizePolicy3.setHeightForWidth(pushButton_enter->sizePolicy().hasHeightForWidth());
        pushButton_enter->setSizePolicy(sizePolicy3);
        pushButton_enter->setFont(font5);

        gridLayout_17->addWidget(pushButton_enter, 7, 2, 1, 1);

        stackedWidget->addWidget(login);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1094, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_graph->setCurrentIndex(0);
        stackedWidget_statistics->setCurrentIndex(1);

        tabWidget_option->setCurrentIndex(0);
        stackedWidget_admin->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_hostel_2->setText(QApplication::translate("MainWindow", "Zanskar Hostel", 0));
        label_developed->setText(QApplication::translate("MainWindow", "Developed by IITD", 0));
        pushButton_staff_login->setText(QApplication::translate("MainWindow", "Staff Login", 0));
        label_time->setText(QString());
        label_time_status->setText(QApplication::translate("MainWindow", "25 min to next meal", 0));
        label_3->setText(QApplication::translate("MainWindow", "Graph", 0));
        label_5->setText(QApplication::translate("MainWindow", "Logged in:", 0));
        label_6->setText(QApplication::translate("MainWindow", "100", 0));
        label_7->setText(QApplication::translate("MainWindow", "Expected:", 0));
        label_8->setText(QApplication::translate("MainWindow", "250", 0));
        label_10->setText(QApplication::translate("MainWindow", "Expected:", 0));
        label_11->setText(QApplication::translate("MainWindow", "300", 0));
        label->setText(QApplication::translate("MainWindow", "Statistics", 0));
        label_name->setText(QApplication::translate("MainWindow", "Rishit Sanmukhani", 0));
        label_id->setText(QApplication::translate("MainWindow", "2013CS10255", 0));
        label_hostel_1->setText(QApplication::translate("MainWindow", "Zanskar hostel", 0));
        pushButton->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "19", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "23", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "13", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "50", 0));
        spinBox_val->setSpecialValueText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Quantity", 0));
        toolButton_inc_2->setText(QApplication::translate("MainWindow", "Increase", 0));
        toolButton_dec_2->setText(QApplication::translate("MainWindow", "Decrease", 0));
        tabWidget_option->setTabText(tabWidget_option->indexOf(extra_messing), QApplication::translate("MainWindow", "Extra Messing", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Next 5 meals", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Next meal", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Next 3 meals", 0));
        label_2->setText(QApplication::translate("MainWindow", "Custom Date", 0));
        toolButton_inc_present->setText(QApplication::translate("MainWindow", "Increase", 0));
        toolButton_inc_future->setText(QApplication::translate("MainWindow", "Increase", 0));
        toolButton_dec_present->setText(QApplication::translate("MainWindow", "Decrease", 0));
        toolButton_dec_future->setText(QApplication::translate("MainWindow", "Decrease", 0));
        pushButton_confirm->setText(QApplication::translate("MainWindow", "Confirm", 0));
        tabWidget_option->setTabText(tabWidget_option->indexOf(rebate), QApplication::translate("MainWindow", "Rebate", 0));
        label_admin->setText(QApplication::translate("MainWindow", "Admin Portal", 0));
        pushButton_master->setText(QApplication::translate("MainWindow", "Master Card", 0));
        pushButton_reg->setText(QApplication::translate("MainWindow", "Register New Card", 0));
        pushButton_delete->setText(QApplication::translate("MainWindow", "Delete Card", 0));
        pushButton_allow->setText(QApplication::translate("MainWindow", "Allow Temporarily", 0));
        label_4->setText(QApplication::translate("MainWindow", "Register New Card", 0));
        label_card->setText(QApplication::translate("MainWindow", "Card Number :", 0));
        label_card_num->setText(QApplication::translate("MainWindow", "19", 0));
        label_9->setText(QApplication::translate("MainWindow", "Days of Validity :", 0));
        toolButton_inc->setText(QApplication::translate("MainWindow", "Increase", 0));
        toolButton_dec->setText(QApplication::translate("MainWindow", "Decrease", 0));
        pushButton_confirm_2->setText(QApplication::translate("MainWindow", "Confirm", 0));
        lineEdit_password->setText(QString());
        pushButton_14->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "1", 0));
        label_12->setText(QApplication::translate("MainWindow", "Enter Your Pin:", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "6", 0));
        label_staff->setText(QApplication::translate("MainWindow", "Staff login", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton_del->setText(QApplication::translate("MainWindow", "DEL", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_enter->setText(QApplication::translate("MainWindow", "ENTER", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
