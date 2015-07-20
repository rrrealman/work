#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplashScreen>
#include <QThread>
#include <QLabel>
#include "startform.h"
#include "optionsform.h"
#include "filesettings.h"
#include "outputstreamobject.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool Playing;
    QString params;

    void PlayingMenu();

private slots:
    void StartTriggered();
    void CameraSettingsTriggered();
    void FileSettingsTriggered();
    void Find_cameraTriggered();
    void HelpTriggered();
    void AboutTriggered();
};

#endif // MAINWINDOW_H
