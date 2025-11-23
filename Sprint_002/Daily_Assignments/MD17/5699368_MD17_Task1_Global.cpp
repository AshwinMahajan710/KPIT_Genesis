#include<string>
#include"5699368_MD17_Task1_SensorData.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include"5699368_MD17_Task1_Global.h"
#include<algorithm>

// copies only readings where isValidReadings --> std::copy_if
std::vector<Sensordata> copyValidReadings(const std::vector<Sensordata>& readings){
    std::vector<Sensordata> newVector;
    std::copy_if(readings.begin(), readings.end(), std::back_inserter(newVector), [](const Sensordata& sensor){return (sensor.isValidReading());});
    return newVector;
}

// copies first n readings using std::copy_n
std::vector<Sensordata> copyFirstNReadings(const std::vector<Sensordata>& readings, size_t n){
    std::vector<Sensordata> newVector;
    std::copy_n(readings.begin(), n, std::back_inserter(newVector));
    return newVector;
}

// copy all readings
std::vector<Sensordata> copyAllReadings(const std::vector<Sensordata>& readings){
    std::vector<Sensordata> newVector;
    std::copy(readings.begin(),readings.end(), std::back_inserter(newVector));
    return newVector;
}

// copy readings above threshold
std::vector<Sensordata> copyReadingsAboveThreshold(const std::vector<Sensordata>& readings, double threshold){
    std::vector<Sensordata> newVector;
    std::copy_if(readings.begin(), readings.end(),std::back_inserter(newVector), [threshold](const Sensordata& sensor){return (sensor.getValue()>threshold);});
    return newVector;
}

// copies readings from a specific module
std::vector<Sensordata> copyModuleReadings(const std::vector<Sensordata>& readings, const std::string & module){
    std::vector<Sensordata> newVector;
    std::copy_if(readings.begin(), readings.end(),std::back_inserter(newVector), [module](const Sensordata& sensor){return (sensor.getModuleName()==module);});
    return newVector;
}