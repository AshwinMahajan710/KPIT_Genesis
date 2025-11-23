#ifndef INC_5699368_MD5_TASK2_GLOBAL_H
#define INC_5699368_MD5_TASK2_GLOBAL_H

#include<iostream>
#include<vector>
#include<functional>
#include<string>
#include"5699368_MD5_Task2_AlertManager.h"

// implementing callable types
void logalert(std::string str_, double val_);

class Logger{
    public:
        void record(std::string str_, double val_);
};

struct AlertFunctor
{
    void operator()(std::string, double);
};

#endif // INC_5699368_MD5_TASK2_GLOBAL_H
