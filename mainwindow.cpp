#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Playing = false;
    connect(ui->actionFileSettings,   SIGNAL(triggered()), this, SLOT(FileSettingsTriggered()));
    connect(ui->actionQuit,           SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionStart,          SIGNAL(triggered()), this, SLOT(StartTriggered()));
    connect(ui->actionCameraSettings, SIGNAL(triggered()), this, SLOT(CameraSettingsTriggered()));
    connect(ui->actionFind_camera,    SIGNAL(triggered()), this, SLOT(Find_cameraTriggered()));
    connect(ui->actionHelp,           SIGNAL(triggered()), this, SLOT(HelpTriggered()));
    connect(ui->actionAbout,          SIGNAL(triggered()), this, SLOT(AboutTriggered()));
//    connect(ui->ShareButton,   SIGNAL(clicked()), this, SLOT(ShareClicked()));
//    connect(ui->OptionsButton, SIGNAL(clicked()), this, SLOT(OptionsClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PlayingMenu()
{
    ui->actionFileSettings->setEnabled(!this->Playing);
    ui->actionCameraSettings->setEnabled(!this->Playing);
    ui->actionFind_camera->setEnabled(!this->Playing);
}

void MainWindow::StartTriggered()
{
    if (!this->Playing)
    {
        ui->actionStart->setText("Stop");
        StartForm* pStartForm = new StartForm;//init startform!
        if (pStartForm->exec() == QDialog::Accepted)
        {
            // applying changes in main window
            this->Playing = true;
            PlayingMenu();
        }
        delete pStartForm;
    }
    else
    {
        ui->actionStart->setText("Start");
        this->Playing = false;
        PlayingMenu();
    }
}

void MainWindow::FileSettingsTriggered()
{
    FileSettings* pFileSettings = new FileSettings;
    if (pFileSettings->exec() == QDialog::Accepted)
    {
        // applying changes in main window
    }
    delete pFileSettings;
}

void MainWindow::CameraSettingsTriggered()
{

}

void MainWindow::Find_cameraTriggered()
{

}
void MainWindow::HelpTriggered()
{

}
void MainWindow::AboutTriggered()
{

}

//void MainWindow::ShareClicked()
//{
//
//}
//void MainWindow::OptionsClicked()
//{
//    OptionsForm* pOptionsForm = new OptionsForm;
//    if (pOptionsForm->exec() == QDialog::Accepted)
//    {
//        // applying changes in main window
//    }
//    delete pOptionsForm;
//}
