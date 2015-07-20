#ifndef OUTPUT_H
#define OUTPUT_H

#include <QVector>
//#include "outputstreamobject.h"

#include "hostoutput.h"
#include "youtubeoutput.h"
//#include "ustreamoutput.h"
// add header of class of output

class Output
{
public:
    Output();
    OutputStreamObject* getOutputObject(int i);
    int length();
private:
    QVector<OutputStreamObject*> outputObjects; // maybe iterator will help
};

#endif // OUTPUT_H
