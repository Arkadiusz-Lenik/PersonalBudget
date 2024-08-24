#include "DateMethods.h"

string DateMethods::getCurrentDate()
{
    time_t rawTime;
    tm* timeInfo;
    char buffer [80];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer,80,"%Y%m%d",timeInfo);

    return buffer;
}
