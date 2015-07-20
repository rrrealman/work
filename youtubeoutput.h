#ifndef YOUTUBEOUTPUT_H
#define YOUTUBEOUTPUT_H

#include "outputstreamobject.h"
#include "youtubeoutputvarparams.h"

class YouTubeOutput: public OutputStreamObject
{
public:
    YouTubeOutput();
    ~YouTubeOutput();
    QWidget* createVarParamsWidget();
    void readSettings();
    void writeSettings();
};

#endif // YOUTUBEOUTPUT_H
