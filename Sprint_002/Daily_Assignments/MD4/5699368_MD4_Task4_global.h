#ifndef INC_5699368_MD4_TASK4_GLOBAL_H
#define INC_5699368_MD4_TASK4_GLOBAL_H

#include<string>
#include"5699368_MD4_Task4_Level.h"
#include"5699368_MD4_Task4_TelemetryPacket.h"
#include<iostream>

void logByValue(TelemetryPacket p);
void logByRef(const TelemetryPacket& p);
void logByRRef(TelemetryPacket&& p);
void logByPtr(const TelemetryPacket* p);

#endif // INC_5699368_MD4_TASK4_GLOBAL_H
