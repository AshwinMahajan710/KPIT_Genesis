#ifndef GLOBAL_H
#define GLOBAL_H

#include"Sensor.h"
#include<string>

// Compares detection ranges and returns which sensor has greater range.
std::string compareSensorRanges(const Sensor* s1, const Sensor* s2);

// Returns true if sensor is ACTIVE and average reading ≥ threshold.
bool isSensorReliable(const Sensor& sensor, double threshold = 75.0);

// Displays details of all sensors in an array.
void displaySensorArray(Sensor* sensors[], int size);

#endif // GLOBAL_H
