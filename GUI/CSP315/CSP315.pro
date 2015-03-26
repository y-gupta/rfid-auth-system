#-------------------------------------------------
#
# Project created by QtCreator 2015-03-09T20:36:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSP315
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    utility.cpp \
    ../printer/printer.cpp \
    messing.cpp \
    stafflogin.cpp \
    rebate.cpp

HEADERS  += mainwindow.h \
    utility.h \
    ../printer/printer.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
