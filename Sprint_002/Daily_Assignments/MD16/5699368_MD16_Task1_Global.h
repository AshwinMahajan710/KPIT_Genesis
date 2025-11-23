#ifndef INC_5699368_MD16_TASK1_GLOBAL_H
#define INC_5699368_MD16_TASK1_GLOBAL_H
#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include"5699368_MD16_Task1_SensorFaultTracker.h"
#include<iostream>
#include<stdexcept>

// if anyone crosses the threshold return true else return false
bool isSensorCritical(const SensorFaultTracker& tracker, const std::string& sensorId, int threshold);

// getting sesnors with no faults
std::vector<std::string> getSensorsWithNoFaults(const std::vector<std::string>& allSensors, const SensorFaultTracker& tacker);

// printing all faults in a tracker
void printFaultSummary(const SensorFaultTracker& tracker);

#endif // INC_5699368_MD16_TASK1_GLOBAL_H
