#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include"5699368_MD16_Task1_SensorFaultTracker.h"
#include<iostream>
#include<stdexcept>
#include"5699368_MD16_Task1_Global.h"

// if anyone crosses the threshold return true else return false
bool isSensorCritical(const SensorFaultTracker& tracker, const std::string& sensorId, int threshold){
    std::vector <int> faultVector = tracker.getFaults(sensorId);
    for(auto it = faultVector.begin(); it!=faultVector.end(); it++){
        if(*it > threshold){
            return true;
        }
    }
    return false;
}

// getting sesnors with no faults
std::vector<std::string> getSensorsWithNoFaults(const std::vector<std::string>& allSensors, const SensorFaultTracker& tracker){
    std::vector<std::string> sensorsWithNoFault;
    for(auto& sensor: allSensors){
        std::vector <int> faultVector = tracker.getFaults(sensor);
        if(faultVector.empty()){
            sensorsWithNoFault.push_back(sensor);
        }
    }
    return sensorsWithNoFault;
}

// printing all faults in a tracker
void printFaultSummary(const SensorFaultTracker& tracker){
    std::unordered_map<std::string, std::vector<int>> faultMap = tracker.getFaultMap();
    for(auto &sensor: faultMap){
        std::cout<<"\nSensorId: "<<sensor.first<<std::endl;
        std::cout<<"Fault Codes: ";
        for(auto &fault: sensor.second){
            std::cout<<fault<<" ";
        }
        std::cout<<std::endl;
    }
}