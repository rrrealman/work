#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Playing = false;
    connect(ui->StartButton,   SIGNAL(clicked()), this, SLOT(StartClicked()));
    connect(ui->ShareButton,   SIGNAL(clicked()), this, SLOT(ShareClicked()));
    connect(ui->OptionsButton, SIGNAL(clicked()), this, SLOT(OptionsClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartClicked()
{
    if (!this->Playing)
    {
        this->Playing = true;
        ui->StartButton->setText("Stop");
    }
    else
    {
        this->Playing = false;
        ui->StartButton->setText("Start");
    }
}

void MainWindow::ShareClicked()
{
    qDebug()<<"Share clicked";
}
void MainWindow::OptionsClicked()
{
    qDebug()<<"Options clicked";
}
