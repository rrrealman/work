#include "startform.h"
#include "ui_startform.h"
#include <QDebug>

StartForm::StartForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);
    connect(ui->BrowseButton, SIGNAL(clicked()), this, SLOT(SpecifyFile()));
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
