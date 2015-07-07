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
        StartForm* pStartForm = new StartForm;//init startform!
        if (pStartForm->exec() == QDialog::Accepted)
        {
//            this->params = pStartForm->GetParams();
            // applying changes in main window
            this->Playing = true;
            ui->StartButton->setText("Stop");
            ui->ShareButton->setEnabled(false);
            ui->OptionsButton->setEnabled(false);
        }
        delete pStartForm;
    }
    else
    {
        this->Playing = false;
        ui->StartButton->setText("Start");
        ui->ShareButton->setEnabled(true);
        ui->OptionsButton->setEnabled(true);
    }
}
void MainWindow::ShareClicked()
{
    ShareForm* pShareForm = new ShareForm;
    if (pShareForm->exec() == QDialog::Accepted)
    {
        // applying changes in main window
    }
    delete pShareForm;
}
void MainWindow::OptionsClicked()
{
    OptionsForm* pOptionsForm = new OptionsForm;
    if (pOptionsForm->exec() == QDialog::Accepted)
    {
        // applying changes in main window
    }
    delete pOptionsForm;
}
