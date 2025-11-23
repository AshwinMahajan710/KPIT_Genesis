#ifndef INC_5699368_MD17_TASK1_GLOBAL_H
#define INC_5699368_MD17_TASK1_GLOBAL_H

#include<string>
#include"5699368_MD17_Task1_SensorData.h"
#include<stdexcept>
#include<iostream>
#include<vector>

// copies only readings where isValidReadings --> std::copy_if
std::vector<Sensordata> copyValidReadings(const std::vector<Sensordata>& readings);

// copies first n readings using std::copy_n
std::vector<Sensordata> copyFirstNReadings(const std::vector<Sensordata>& readings, size_t n);

// copy all readings
std::vector<Sensordata> copyAllReadings(const std::vector<Sensordata>& readings);

// copy readings above threshold
std::vector<Sensordata> copyReadingsAboveThreshold(const std::vector<Sensordata>& readings, double threshold);

// copies readings from a specific module
std::vector<Sensordata> copyModuleReadings(const std::vector<Sensordata>& readings, const std::string & module);

#endif // INC_5699368_MD17_TASK1_GLOBAL_H
