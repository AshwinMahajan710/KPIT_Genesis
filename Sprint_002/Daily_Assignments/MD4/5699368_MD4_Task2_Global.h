#ifndef INC_5699368_MD4_TASK2_GLOBAL_H
#define INC_5699368_MD4_TASK2_GLOBAL_H

#include<string>
#include"5699368_MD4_Task2_State.h"
#include"5699368_MD4_Task2_Sensor.h"

void logSensorByRef(Sensor & s);
void logSensorByRRef(Sensor && s);
void logSensorByPtr(Sensor * s);

#endif // INC_5699368_MD4_TASK2_GLOBAL_H
