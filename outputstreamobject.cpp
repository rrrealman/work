#include "outputstreamobject.h"

OutputStreamObject::OutputStreamObject(QObject *parent) :
    QObject(parent)
{
    this->constParamsWidget = createConstParamsWidget();
    this->varParamsWidget   = createVarParamsWidget();
}
OutputStreamObject::~OutputStreamObject()
{}
bool OutputStreamObject::storeVarParams()
{}
void OutputStreamObject::storeConstParams()
{}
void OutputStreamObject::resetVarParams()
{}
void OutputStreamObject::resetConstParams()
{}
void OutputStreamObject::initPipeline()
{}
bool OutputStreamObject::isPipelineDone()
{}

QWidget* OutputStreamObject::createConstParamsWidget()
{
    return NULL;
}

QWidget* OutputStreamObject::createVarParamsWidget()
{
    return NULL;
}

QWidget* OutputStreamObject::getConstParamsWidget()
{
    return this->constParamsWidget;
}
QWidget* OutputStreamObject::getVarParamsWidget()
{
    return this->varParamsWidget;
}
QString OutputStreamObject::getShortName() const
{}

QString OutputStreamObject::getFullName() const
{
    return this->objName;
}

QString OutputStreamObject::getIntName() const
{}
QPixmap* OutputStreamObject::getLogo(){}

void OutputStreamObject::readSettings(){}
void OutputStreamObject::writeSettings(){}
