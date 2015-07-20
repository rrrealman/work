#include "hostoutput.h"

// TEST
#include <QDebug>
// END TEST

#define HOST_GR_NAME QString("host")
#define TGT_DIR_NAME QString("targetDir")
#define URL_LST_NAME QString("URLList")

hostOutput::hostOutput()
{
    this->objName = QString("Host");
    this->varParamsWidget = createVarParamsWidget();
    readSettings();
//    this->varParamsWidget->
//    this->varParamsWidget->Init();
}

hostOutput::~hostOutput()
{
    writeSettings();
}

QWidget* hostOutput::createVarParamsWidget()
{
    return new HostOutputVarParams();
}

void hostOutput::readSettings()
{
    QSettings *settings = getApplicationSettings();
    settings->beginGroup(HOST_GR_NAME);
//        this->targetDir = settings->value(TGT_DIR_NAME, "/~").toString();
//        this->URLList = settings->value(URL_LST_NAME).toList();
}

void hostOutput::writeSettings()
{
    QSettings *settings = getApplicationSettings();
    settings->beginGroup(HOST_GR_NAME);
//        settings->setValue(TGT_DIR_NAME, this->targetDir);
//        settings->setValue(URL_LST_NAME, this->URLList);
}
