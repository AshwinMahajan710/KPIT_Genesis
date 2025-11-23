#include<unordered_map>
#include<queue>
#include<stack>
#include<array>
#include<string>
#include<vector>
#include<tuple>
#include<iostream>
#include"5699368_MD16_Task4_SensorEventAggregator.h"

// adding new sensorId and its type to map --> if already exist ignore it
void SensorEventAggregator:: addSensor(int sensorId, const std::string& type){
    auto findSensorId = m_sensorIdToType.find(sensorId);
    if(findSensorId == m_sensorIdToType.end()){
        m_sensorIdToType[sensorId] = type;
        m_sensorHistory.push(sensorId);
        std::cout<<"New Entry added..."<<std::endl;
    }else{
        std::cout<<"Entry with similar sensorId exist.."<<std::endl;
    }
}

// adding new event in priorityqueue
void SensorEventAggregator::pushEvent(int priority, int sensorId, const std::string& description){
    m_eventQueue.emplace(std::make_tuple(priority, sensorId, description));
    
}

// getting the highest priority Tuple
std::tuple<int, int, std::string> SensorEventAggregator::popHighestPrioriy();

// pops and returns most recent sensor id from stack
int SensorEventAggregator::popSensorFromHistory() ;

// retrieves configuration string at given index --> throws std::out_of_range if index invalid
std::string SensorEventAggregator::getConfigData(size_t index) const;

// getting sensortype by sensorId --> throws error if not found
std::string SensorEventAggregator::getSensorType(int sensorId);