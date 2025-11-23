#ifndef INC_5699368_MD15_TASK2_GLOBAL_H
#define INC_5699368_MD15_TASK2_GLOBAL_H

#include<memory>
#include<vector>
#include"5699368_MD15_Task2_SmartSensorDiagnostics.h"
#include<limits>
#include<algorithm>

// for computing the sum
template <typename... Args>
double computeSum(Args... args){
    return (args + ... + 0);
}

// for computing the average
template <typename... Args>
double computeAverage(Args... args){
    double sum = (computeSum(args...));
    return sum / sizeof...(args);
}

#endif // INC_5699368_MD15_TASK2_GLOBAL_H
