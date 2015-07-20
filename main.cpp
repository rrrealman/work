#include "mainwindow.h"
#include "application.h"
#include "splashscreen.h"

// TEST
#include "hostoutput.h"
//#include "hostoutputvarparams.h"
#include <QDebug>
// END TEST

#define STNGS_PREFIX QString("")
#define ORG_NAME     QString("Panorics")
#define PROG_NAME    QString("PreviewMainWindow")

int main(int argc, char *argv[])
{
    Application a(argc, argv, new QSettings(ORG_NAME, PROG_NAME));
    MainWindow w;

    splashScreen(&a, &w);

    // TEST
//    hostOutput *ho = new hostOutput();
//    qDebug()<<ho;
//    ho->getVarParamsWidget()->show();
//    QWidget *wgt = new QWidget();//new HostOutputVarParams();

    // END TEST

    return a.exec();
}
