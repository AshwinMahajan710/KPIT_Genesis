#ifndef INC_5699368_MD4_TASK3_GLOBAL_H
#define INC_5699368_MD4_TASK3_GLOBAL_H

#include"5699368_MD4_Task3_SignalBuffer.h"
#include<string>
#include"5699368_MD4_Task3_Status.h"
#include<iostream>

//using reference
void logByRef(const SignalBuffer& b);

// using rvaluereference
void logByRRef(const SignalBuffer&& b);

// using ptr
void logByPtr(const SignalBuffer* b);

#endif // INC_5699368_MD4_TASK3_GLOBAL_H
