#ifndef INC_5699368_MD5_TASK1_GLOBAL_H
#define INC_5699368_MD5_TASK1_GLOBAL_H

#include<string>
#include<functional>
#include"5699368_MD5_Task1_Sensor.h"

void logEvent(int id_, double value_);

class Logger{
    public:
        void log(int id_, double value_);
};

void dispatch(Sensor sensors[], int size);

#endif // INC_5699368_MD5_TASK1_GLOBAL_H
