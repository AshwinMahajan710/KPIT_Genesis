#ifndef GLOBAL_H
#define GLOBAL_H

#include"HeapSensor.h"

// function to calculate maxVoltage
float computeMaxVoltage(const HeapSensor* arr_[], int count_);

// function to adjust temperature in particular range
void adjustTemperaturesToRange(HeapSensor* arr_[], int count_, float minAllowed_, float maxAllowed_); 

float computeAverageTemperature(const HeapSensor* arr_[], int count_);
#endif // GLOBAL_H
