#include <QApplication>
#include "include/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(32, 32);
    w.show();

    return a.exec();
}

