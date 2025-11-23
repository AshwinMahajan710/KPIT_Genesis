#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include"5699368_MD16_Task1_SensorFaultTracker.h"
#include<iostream>
#include<stdexcept>

// adding fault to map and queue
void SensorFaultTracker::reportfault(const std::string& sensorId, int faultCode){
    m_faultMap[sensorId].push_back(faultCode);
    m_faultQueue.push(std::make_pair(faultCode, sensorId));
    std::cout<<"\nFault added successfully.."<<std::endl;
}

// getting the fault codes for sensor
std::vector<int> SensorFaultTracker::getFaults(const std::string& sensorId) const {
    auto it = m_faultMap.find(sensorId);
    if (it != m_faultMap.end()) {
        return it->second;   // safe, does NOT modify the map
    } else {
        std::cout << "\nFaults for respective sensorId not found..\n";
        return {};           // return empty vector directly
    }
}


// pops and return highest priority fault --> throw runtime error is empty
std::pair<int , std::string > SensorFaultTracker:: getNextCriticalFault(){
    if(!hasFaults()) {
        throw std::runtime_error("FaultListEmptyException...");
    }else{
        std::pair<int , std::string > highestPriorityFault = m_faultQueue.top();
        m_faultQueue.pop();
        return highestPriorityFault;
    }
}

// returns true if queue is not emptty
bool SensorFaultTracker:: hasFaults() const{
    return !m_faultQueue.empty();
}

std::unordered_map<std::string, std::vector<int>>   SensorFaultTracker::getFaultMap() const{
    return m_faultMap;
}