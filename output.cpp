#include "output.h"

Output::Output()
{
    this->outputObjects.append(new hostOutput());
    this->outputObjects.append(new YouTubeOutput());
    // append list with new instace of class added in "#include..."
    // this class have to implement next methods:
    // - ...
}

OutputStreamObject* Output::getOutputObject(int i)
{
    return this->outputObjects.value(i, NULL);
}

int Output::length()
{
    return this->outputObjects.length();
}
