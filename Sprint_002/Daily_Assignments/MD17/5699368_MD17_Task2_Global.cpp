#include<string>
#include"5699368_MD17_Task2_SensorReading.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include"5699368_MD17_Task2_Global.h"
#include<algorithm>

// returns true if any of reading if from faulty module --> std::any_of
bool hasAnyFaultyReadings(const std::vector<SensorReading>& readings){
    return std::any_of(readings.begin(), readings.end(), [](const SensorReading& sensor){return sensor.isFaultyModule();});
}

// if all readings have non-negative values return true else return false
bool areAllReadingsValid(const std::vector<SensorReading>& readings){
    return std::all_of(readings.begin(), readings.end(), [](const SensorReading& sensor){return (sensor.getValue() >= 0);});
}

// returns true if none of the module is form specific module --> std::none_of
bool noneFromModule(const std::vector<SensorReading>& readings, const std::string& module){
    return std::none_of(readings.begin(), readings.end(), [module](const SensorReading& sensor){return (sensor.getModuleName() == module);});
}

// return true if any of reading is greater than threshold --> std::any_of
bool isAnyReadingAbove(const std::vector<SensorReading>& readings, double threshold){
    return std::any_of(readings.begin(), readings.end(), [threshold](const SensorReading& sensor){return (sensor.getValue() > threshold);});
}

// return true is all module names are non empty
bool areAllModulesNamed(const std::vector<SensorReading>& readings){
    return std::all_of(readings.begin(), readings.end(), [](const SensorReading& sensor){return ((sensor.getModuleName().length()) != 0);});   
}