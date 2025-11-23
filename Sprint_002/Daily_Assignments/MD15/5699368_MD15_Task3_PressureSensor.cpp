#include<string>
#include"5699368_MD15_Task3_SensorNode.h"
#include"5699368_MD15_Task3_PressureSensor.h"

// parametrized constructor
PressureSensor::PressureSensor(const std::string& id_, double value_): SensorNode(id_, value_){}

void PressureSensor::updateVal(double newVal_) {
    if(newVal_< 0 ) {m_value= 0;}
    else if(newVal_>300 ) {m_value=300;}
    else{m_value = newVal_;}
}