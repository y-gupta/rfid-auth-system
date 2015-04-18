#include "mainwindow.h"
#include "network.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
if(argc==1)
    Network::init("localhost:1337");
else
    Network::init(string(argv[1]));

    //Application::setOverrideCursor(Qt::BlankCursor);
    MainWindow w;
    w.showFullScreen();

    return a.exec();
}
