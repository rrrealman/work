#include "youtubeoutput.h"

#define YT_GR_NAME QString("youtube")
//#define TGT_DIR_NAME QString("targetDir")
//#define URL_LST_NAME QString("URLList")

YouTubeOutput::YouTubeOutput()
{
    this->objName = QString("Youtube");
    this->varParamsWidget = createVarParamsWidget();
    readSettings();
    //    this->varParamsWidget->
    //    this->varParamsWidget->Init();
}

YouTubeOutput::~YouTubeOutput()
{
    writeSettings();
}

QWidget* YouTubeOutput::createVarParamsWidget()
{
    return new YoutubeOutputVarParams();
}

void YouTubeOutput::readSettings()
{
    QSettings *settings = getApplicationSettings();
    settings->beginGroup(YT_GR_NAME);
//        this->targetDir = settings->value(TGT_DIR_NAME, "/~").toString();
//        this->URLList = settings->value(URL_LST_NAME).toList();
}

void YouTubeOutput::writeSettings()
{
    QSettings *settings = getApplicationSettings();
    settings->beginGroup(YT_GR_NAME);
//        settings->setValue(TGT_DIR_NAME, this->targetDir);
//        settings->setValue(URL_LST_NAME, this->URLList);
}
