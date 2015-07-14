#include "startform.h"
#include "ui_startform.h"
#include <QDebug>

StartForm::StartForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);
    connect(ui->BrowseButton, SIGNAL(clicked()), this, SLOT(SpecifyFile()));

    RadioButtons = new QSignalMapper(this);
    connect(ui->HostRB,    SIGNAL(clicked()),   RadioButtons, SLOT(map()));
    RadioButtons->setMapping(ui->HostRB, HOST);
    connect(ui->YouTubeRB, SIGNAL(clicked()),   RadioButtons, SLOT(map()));
    RadioButtons->setMapping(ui->YouTubeRB, YT);
    connect(ui->UStreamRB, SIGNAL(clicked()),   RadioButtons, SLOT(map()));
    RadioButtons->setMapping(ui->UStreamRB, US);
    connect(RadioButtons,  SIGNAL(mapped(int)), this,         SLOT(RBClicked(int)));
}

StartForm::~StartForm()
{
    delete ui;
}

QString StartForm::GetParams() const
{
    return QString("This is Params");
}

void StartForm::SpecifyFile()
{
    QFileDialog *pFileDialog = new QFileDialog;
    pFileDialog->exec();
    delete pFileDialog;
}

void StartForm::RBClicked(int RB)
{
    qDebug()<<RB;
//    HideAllParams();
//    switch(RB):
//    case HOST:
//        VisibleHostParams(true);
//        break;
//    case YT:
//        VisibleYTParams(true);
//        break;
//    case US:
//        VisibleUSParams(true);
//        break;
}

//void StartForm::HideAllParams()
//{
//    VisibleHostParams(false);
//    VisibleYTParams(false);
//    VisibleUSParams(false);
//}

//void StartForm::VisibleHostParams(bool visible)
//{
//    ui->
//}
