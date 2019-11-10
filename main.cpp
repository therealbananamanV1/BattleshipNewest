#include "mainwindow.h"
#include <QApplication>
#include <cstdlib>
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    srand ( (int)time(nullptr) );
    w.show();
    return app.exec();
}


