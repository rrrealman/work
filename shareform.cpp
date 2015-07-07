#include "shareform.h"
#include "ui_shareform.h"

ShareForm::ShareForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShareForm)
{
    ui->setupUi(this);
}

ShareForm::~ShareForm()
{
    delete ui;
}
