#ifndef INC_5699368_MD17_TASK2_GLOBAL_H
#define INC_5699368_MD17_TASK2_GLOBAL_H

#include<string>
#include"5699368_MD17_Task2_SensorReading.h"
#include<stdexcept>
#include<iostream>
#include<vector>

// returns true if any of reading if from faulty module --> std::any_of
bool hasAnyFaultyReadings(const std::vector<SensorReading>& readings);

// if all readings have non-negative values return true else return false
bool areAllReadingsValid(const std::vector<SensorReading>& readings);

// returns true if none of the module is form specific module --> std::none_of
bool noneFromModule(const std::vector<SensorReading>& readings, const std::string& module);

// return true if any of reading is greater than threshold --> std::any_of
bool isAnyReadingAbove(const std::vector<SensorReading>& readings, double threshold);

// return true is all module names are non empty
bool areAllModulesNamed(const std::vector<SensorReading>& readings);
 
#endif // INC_5699368_MD17_TASK2_GLOBAL_H
