#include "mainwindow.h"
#include <QApplication>

#include "splashscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    splashScreen(&a, &w);

    return a.exec();
}
