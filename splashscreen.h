#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDesktopWidget>
#include <QSplashScreen>
//#include <QThread>

#define SPLASH_IMG     QString("splash.png")
#define LOW_RES_DESK   QSize(1280, 720)
#define HIG_RES_DESK   QSize(1920, 1080)
#define LOW_RES_SPLASH QSize(620, 300)
#define MID_RES_SPLASH QSize(868, 420)
#define HIG_RES_SPLASH QSize(1116, 540)
#define SPLSH_TXT_CLR  Qt::white
#define SPLSH_TXT_ALG  Qt::AlignRight|Qt::AlignBottom

// For testing ////
#include <QTime>
#include <QDebug>
void delay(unsigned int delay_sec)
{
    QTime time;
//    qDebug()<<delay_sec;
    time.start();
   unsigned int i;
    for (i=0; i<=delay_sec;)
    {
        qDebug()<<time.elapsed;
        if(time.elapsed() > 1000)
        {
            qDebug()<<"ELAPSED";
            time.start();
            qApp->processEvents(QEventLoop::AllEvents);
            ++i;
        }
    }
}
// End ////

bool camsFound()
{
    //Searching for connected cameras
}

bool downloadingCath()
{
    //Downloading cathalog of files
}

bool downloadingProg()
{
    //Downloading programm
}

void splashScreen(QApplication* a, QWidget* w)
{
    QPixmap splashImage(SPLASH_IMG);
    QSplashScreen* pSplash;

    QSize desktopSize = a->desktop()->screenGeometry(a->desktop()->primaryScreen()).size();
    if (desktopSize.height() <= LOW_RES_DESK.height())
        pSplash = new QSplashScreen(splashImage.scaled(LOW_RES_SPLASH));
    else if (desktopSize.height() <= HIG_RES_DESK.height())
        pSplash = new QSplashScreen(splashImage.scaled(MID_RES_SPLASH));
    else
        pSplash = new QSplashScreen(splashImage.scaled(HIG_RES_SPLASH));

    pSplash->show();
    pSplash->showMessage("Searching for connected cameras", SPLSH_TXT_ALG, SPLSH_TXT_CLR);
        delay(1000);
    if (camsFound())
    {
        pSplash->showMessage("Downloading cathalog of files", SPLSH_TXT_ALG, SPLSH_TXT_CLR);
            delay(1000);
        downloadingCath();
    }
    pSplash->showMessage("Downloading programm", SPLSH_TXT_ALG, SPLSH_TXT_CLR);
        delay(1000);
    downloadingProg();

    w->show();
    pSplash->finish(w);
    delete pSplash;
}

#endif // SPLASHSCREEN_H
