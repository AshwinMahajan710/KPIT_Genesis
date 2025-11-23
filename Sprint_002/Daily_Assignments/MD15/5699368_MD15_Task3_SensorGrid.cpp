#include<string>
#include"5699368_MD15_Task3_SensorNode.h"
#include"5699368_MD15_Task3_PressureSensor.h"
#include"5699368_MD15_Task3_TemperatureSensor.h"
#include<array>
#include<memory>
#include"5699368_MD15_Task3_SensorGrid.h"
#include<stdexcept>
#include<algorithm>

// function to setsensor
void SensorGrid::setSensor(size_t index, std::shared_ptr<SensorNode> sensor_){
    if (index >= m_sensors.size()) 
    {
        throw std::out_of_range("InvalidIndex");        
    }
    else{
        m_sensors[index] = std::move(sensor_);
    }
}

// for updating
void SensorGrid:: updateSensor(size_t idx, double value){
    if (idx >= m_sensors.size()) 
    {
        throw std::out_of_range("InvalidIndex");        
    }
    else{
        if(m_sensors[idx] == nullptr) {throw std::invalid_argument("It is null");}
        else{
            m_sensors[idx]->updateVal(value);
        }
    }
}

std::pair<double, double> SensorGrid::getMinMaxValues() const {
    bool foundAny = false;
    double minVal = 0;
    double maxVal = 0;

    for (const auto& ptr : m_sensors) {
        if (!ptr) continue;    // skip nullptr sensors

        double val = ptr->getVal();

        if (!foundAny) {
            minVal = maxVal = val;
            foundAny = true;
        } else {
            minVal = std::min(minVal, val);
            maxVal = std::max(maxVal, val);
        }
    }

    if (!foundAny)
        throw std::runtime_error("No active sensors");

    return {minVal, maxVal};
}

size_t SensorGrid::getActiveSensorCount(double threshold_) const{
    int count = 0;
    std::for_each(m_sensors.begin(), m_sensors.end(), [&](std::shared_ptr<SensorNode>& node)mutable ->void{
        if(node && node->getVal()>threshold_){
            count++;
        }
    });
    return count;
}