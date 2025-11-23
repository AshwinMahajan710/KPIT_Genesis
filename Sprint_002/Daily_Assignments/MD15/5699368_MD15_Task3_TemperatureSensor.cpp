#include<string>
#include"5699368_MD15_Task3_SensorNode.h"
#include"5699368_MD15_Task3_TemperatureSensor.h"

// parametrized constructor
TemperatureSensor::TemperatureSensor(const std::string& id_, double value_): SensorNode(id_, value_){}

void TemperatureSensor::updateVal(double newVal_) {
    if(newVal_<-40 ) {m_value=-40;}
    else if(newVal_>150 ) {m_value=150;}
    else{m_value = newVal_;}
}