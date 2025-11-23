#ifndef INC_5699368_MD16_TASK2_GLOBAL_H
#define INC_5699368_MD16_TASK2_GLOBAL_H

#include<unordered_map>
#include<queue>
#include<vector>
#include<string>
#include<mutex>
#include"5699368_MD16_Task2_ConcurrentSensorFaultTracker.h"
#include<stdexcept>
#include<iostream>

// if anyone crosses the threshold return true else return false
bool isSensorCritical(const ConcurrentSensorFaultTracker& tracker, const std::string& sensorId, int threshold);

// getting sesnors with no faults
std::vector<std::string> getSensorsWithNoFaults(const std::vector<std::string>& allSensors, const ConcurrentSensorFaultTracker& tacker);

// printing all faults in a tracker
void printFaultSummary(const ConcurrentSensorFaultTracker& tracker);

std::unordered_map<std::string, size_t> getFaultCounts(const ConcurrentSensorFaultTracker& tracker);

#endif // INC_5699368_MD16_TASK2_GLOBAL_H
