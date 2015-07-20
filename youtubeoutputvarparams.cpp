#include "youtubeoutputvarparams.h"
#include "ui_youtubeoutputvarparams.h"

YoutubeOutputVarParams::YoutubeOutputVarParams(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YoutubeOutputVarParams)
{
    ui->setupUi(this);

}

YoutubeOutputVarParams::~YoutubeOutputVarParams()
{
    delete ui;
}
