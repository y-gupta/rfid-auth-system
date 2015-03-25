/********************************************************************************
** Form generated from reading UI file 'optionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONWINDOW_H
#define UI_OPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionWindow
{
public:
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QLabel *label_hostel;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget_option;
    QWidget *extra_messing;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QWidget *rebate;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_12;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *OptionWindow)
    {
        if (OptionWindow->objectName().isEmpty())
            OptionWindow->setObjectName(QStringLiteral("OptionWindow"));
        OptionWindow->resize(706, 453);
        gridLayout_6 = new QGridLayout(OptionWindow);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_name = new QLabel(OptionWindow);
        label_name->setObjectName(QStringLiteral("label_name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_name->sizePolicy().hasHeightForWidth());
        label_name->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_name->setFont(font);
        label_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(OptionWindow);
        label_id->setObjectName(QStringLiteral("label_id"));

        horizontalLayout->addWidget(label_id);

        label_hostel = new QLabel(OptionWindow);
        label_hostel->setObjectName(QStringLiteral("label_hostel"));
        label_hostel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_hostel);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer, 0, 1, 1, 1);

        tabWidget_option = new QTabWidget(OptionWindow);
        tabWidget_option->setObjectName(QStringLiteral("tabWidget_option"));
        tabWidget_option->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget_option->setFont(font1);
        tabWidget_option->setIconSize(QSize(16, 16));
        extra_messing = new QWidget();
        extra_messing->setObjectName(QStringLiteral("extra_messing"));
        gridLayout_3 = new QGridLayout(extra_messing);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_5 = new QRadioButton(extra_messing);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioButton_5->sizePolicy().hasHeightForWidth());
        radioButton_5->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        radioButton_5->setFont(font2);

        gridLayout_2->addWidget(radioButton_5, 1, 1, 1, 1);

        radioButton = new QRadioButton(extra_messing);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        sizePolicy1.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy1);
        radioButton->setFont(font2);
        radioButton->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_4 = new QRadioButton(extra_messing);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        sizePolicy1.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy1);
        radioButton_4->setFont(font2);

        gridLayout_2->addWidget(radioButton_4, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(extra_messing);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        sizePolicy1.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy1);
        radioButton_3->setFont(font2);

        gridLayout_2->addWidget(radioButton_3, 2, 0, 1, 1);

        radioButton_2 = new QRadioButton(extra_messing);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        sizePolicy1.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy1);
        radioButton_2->setFont(font2);

        gridLayout_2->addWidget(radioButton_2, 1, 0, 1, 1);

        radioButton_6 = new QRadioButton(extra_messing);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        sizePolicy1.setHeightForWidth(radioButton_6->sizePolicy().hasHeightForWidth());
        radioButton_6->setSizePolicy(sizePolicy1);
        radioButton_6->setFont(font2);

        gridLayout_2->addWidget(radioButton_6, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_6, 2, 1, 1, 1);

        tabWidget_option->addTab(extra_messing, QString());
        rebate = new QWidget();
        rebate->setObjectName(QStringLiteral("rebate"));
        gridLayout_5 = new QGridLayout(rebate);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        radioButton_7 = new QRadioButton(rebate);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        sizePolicy1.setHeightForWidth(radioButton_7->sizePolicy().hasHeightForWidth());
        radioButton_7->setSizePolicy(sizePolicy1);
        radioButton_7->setFont(font2);

        gridLayout_4->addWidget(radioButton_7, 1, 1, 1, 1);

        radioButton_8 = new QRadioButton(rebate);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        sizePolicy1.setHeightForWidth(radioButton_8->sizePolicy().hasHeightForWidth());
        radioButton_8->setSizePolicy(sizePolicy1);
        radioButton_8->setFont(font2);

        gridLayout_4->addWidget(radioButton_8, 0, 0, 1, 1);

        radioButton_9 = new QRadioButton(rebate);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        sizePolicy1.setHeightForWidth(radioButton_9->sizePolicy().hasHeightForWidth());
        radioButton_9->setSizePolicy(sizePolicy1);
        radioButton_9->setFont(font2);

        gridLayout_4->addWidget(radioButton_9, 0, 1, 1, 1);

        radioButton_10 = new QRadioButton(rebate);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        sizePolicy1.setHeightForWidth(radioButton_10->sizePolicy().hasHeightForWidth());
        radioButton_10->setSizePolicy(sizePolicy1);
        radioButton_10->setFont(font2);

        gridLayout_4->addWidget(radioButton_10, 2, 0, 1, 1);

        radioButton_11 = new QRadioButton(rebate);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        sizePolicy1.setHeightForWidth(radioButton_11->sizePolicy().hasHeightForWidth());
        radioButton_11->setSizePolicy(sizePolicy1);
        radioButton_11->setFont(font2);

        gridLayout_4->addWidget(radioButton_11, 1, 0, 1, 1);

        radioButton_12 = new QRadioButton(rebate);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));
        sizePolicy1.setHeightForWidth(radioButton_12->sizePolicy().hasHeightForWidth());
        radioButton_12->setSizePolicy(sizePolicy1);
        radioButton_12->setFont(font2);

        gridLayout_4->addWidget(radioButton_12, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_4, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_3, 0, 1, 1, 1);

        tabWidget_option->addTab(rebate, QString());

        gridLayout_6->addWidget(tabWidget_option, 2, 1, 1, 1);

        pushButton_confirm = new QPushButton(OptionWindow);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setFont(font2);

        gridLayout_6->addWidget(pushButton_confirm, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_2, 4, 1, 1, 1);


        retranslateUi(OptionWindow);

        tabWidget_option->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OptionWindow);
    } // setupUi

    void retranslateUi(QDialog *OptionWindow)
    {
        OptionWindow->setWindowTitle(QApplication::translate("OptionWindow", "Dialog", 0));
        label_name->setText(QApplication::translate("OptionWindow", "Rishit Sanmukhani", 0));
        label_id->setText(QApplication::translate("OptionWindow", "2013CS10255", 0));
        label_hostel->setText(QApplication::translate("OptionWindow", "Zanskar hostel", 0));
        radioButton_5->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_4->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_3->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_2->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_6->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        tabWidget_option->setTabText(tabWidget_option->indexOf(extra_messing), QApplication::translate("OptionWindow", "Extra Messing", 0));
        radioButton_7->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_8->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_9->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_10->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_11->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        radioButton_12->setText(QApplication::translate("OptionWindow", "RadioButton", 0));
        tabWidget_option->setTabText(tabWidget_option->indexOf(rebate), QApplication::translate("OptionWindow", "Rebate", 0));
        pushButton_confirm->setText(QApplication::translate("OptionWindow", "Confirm", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionWindow: public Ui_OptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONWINDOW_H
