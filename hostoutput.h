#ifndef HOSTOUTPUT_H
#define HOSTOUTPUT_H

#include "outputstreamobject.h"
#include "hostoutputvarparams.h"

class hostOutput:public OutputStreamObject
{
public:
    hostOutput();
    ~hostOutput();
    QWidget* createVarParamsWidget();
    void readSettings();
    void writeSettings();
private:
//    QList<QString> URLList;
    QString targetDir;
};

#endif // HOSTOUTPUT_H
