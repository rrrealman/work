#include "filesettings.h"
#include "ui_filesettings.h"

FileSettings::FileSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSettings)
{
    ui->setupUi(this);
}

FileSettings::~FileSettings()
{
    delete ui;
}
