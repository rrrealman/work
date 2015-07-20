#include "hostoutputvarparams.h"
#include "ui_hostoutputvarparams.h"

HostOutputVarParams::HostOutputVarParams(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HostOutputVarParams)
{
    ui->setupUi(this);
    //    connect(ui->BrowseButton, SIGNAL(clicked()), this, SLOT(SpecifyFile()));

}

HostOutputVarParams::~HostOutputVarParams()
{
    delete ui;
}

void HostOutputVarParams::SpecifyFile()
{
    QFileDialog *pFileDialog = new QFileDialog;
    pFileDialog->exec();
    delete pFileDialog;
}

