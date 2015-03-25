#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Application::setOverrideCursor(Qt::BlankCursor);
    MainWindow w;
    w.showFullScreen();

    return a.exec();
}
