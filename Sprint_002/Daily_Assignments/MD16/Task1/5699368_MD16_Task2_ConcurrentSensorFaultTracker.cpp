#include<unordered_map>
#include<queue>
#include<vector>
#include<string>
#include<mutex>
#include"5699368_MD16_Task2_ConcurrentSensorFaultTracker.h"
#include<stdexcept>
#include<iostream>

// adding fault to map and queue --> thread safe addition of fault to map and queue
void ConcurrentSensorFaultTracker:: reportfault(const std::string& sensorId, int faultCode){
    if (faultCode <= 0) {
        throw std::invalid_argument("Fault codes must be positive integers.");
    }
    std::lock_guard<std::mutex> lock(m_faultMutex);
    m_faultMap[sensorId].push_back(faultCode);
    m_faultQueue.push(std::make_pair(faultCode, sensorId));
    std::cout<<"\nFault added successfully.."<<std::endl;
    
}

// getting the fault codes for sensor --> thread safe retrieval of fault codes
std::vector<int> ConcurrentSensorFaultTracker::getFaults(const std::string& sensorId) const{
    std::lock_guard<std::mutex> lock(m_faultMutex);
    auto it = m_faultMap.find(sensorId);
    if(it == m_faultMap.end()){
        std::cout<<"Not found.."<<std::endl;
        return {};
    }
    else {
        return it->second;
    }
}

// pops and return highest priority fault --> throw runtime error is empty --> thread safe pop of highest priority fault
std::pair<int , std::string > ConcurrentSensorFaultTracker::getNextCriticalFault(){
    std::lock_guard<std::mutex> lock(m_faultMutex);
    if(!hasFaults()) {
        throw std::runtime_error("FaultListEmptyException...");
    }else{
        std::pair<int , std::string > highestPriorityFault = m_faultQueue.top();
        m_faultQueue.pop();
        return highestPriorityFault;
    }
}

// returns true if queue is not emptty --> thread safe check for fault emptyness
bool ConcurrentSensorFaultTracker::hasFaults() const{
    std::lock_guard<std::mutex> lock(m_faultMutex);
    return !m_faultQueue.empty();
}

// getter for all faults
std::unordered_map<std::string, std::vector<int>> ConcurrentSensorFaultTracker::getFaultMap() const{
    std::lock_guard<std::mutex> lock(m_faultMutex);
    return m_faultMap;
}