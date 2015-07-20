#include "startform.h"
#include "ui_startform.h"

// TEST
#include <QDebug>
// END TEST

StartForm::StartForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);

    this->output = new Output();
    QSignalMapper *RadioButtons = new QSignalMapper(this);
//    QVBoxLayout *vLayout = new QVBoxLayout(this);
//    QVBoxLayout *topLayout = new QVBoxLayout();
    int numOfOObj = output->length();
    OutputStreamObject *outputObj;
    for(unsigned short i = 0; i < numOfOObj; i++)
    {
        outputObj = output->getOutputObject(i);
        QRadioButton *RadioButton = new QRadioButton(QString(outputObj->getFullName()));
        connect(RadioButton, SIGNAL(clicked()), RadioButtons, SLOT(map()));
        RadioButtons->setMapping(RadioButton, i);
        ui->vLayout->addWidget(RadioButton);
//        ui->vLayout->addWidget(RadioButton);
//        vLayout->addWidget(RadioButton);
        ui->vLayout->addWidget(outputObj->getVarParamsWidget());
        outputObj->getVarParamsWidget()->hide();
    }
//    ui->addStretch()
    \
    connect(RadioButtons, SIGNAL(mapped(int)), this, SLOT(RBClicked(int)));
}

StartForm::~StartForm()
{
    delete ui;
}

//QString StartForm::GetParams() const
//{
//    return QString("This is Params");
//}


void StartForm::RBClicked(int RB)
{
    HideAll();
    this->output->getOutputObject(RB)->getVarParamsWidget()->show();
    // TEST
    qDebug()<<this->output->getOutputObject(RB)->getVarParamsWidget()->size();
    qDebug()<<this->output->getOutputObject(RB)->getVarParamsWidget()->isVisible();
    // END TEST
}

void StartForm::HideAll()
{
//    OutputStreamObject *outputObj;
//    foreach(outputObj, output->outputObjects)
//        outputObj->getVarParamsWidget()->hide();
    int len = this->output->length();

    for(int i = 0; i < len; i++)
        this->output->getOutputObject(i)->getVarParamsWidget()->hide();
}
