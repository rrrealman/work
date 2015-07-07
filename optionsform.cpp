#include "optionsform.h"
#include "ui_optionsform.h"

OptionsForm::OptionsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsForm)
{
    ui->setupUi(this);
}

OptionsForm::~OptionsForm()
{
    delete ui;
}
