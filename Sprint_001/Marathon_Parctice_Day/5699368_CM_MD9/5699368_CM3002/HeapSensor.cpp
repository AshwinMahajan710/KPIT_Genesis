
#include<stdexcept>
#include"HeapSensor.h"

//constructor --> default
HeapSensor::HeapSensor(){
    m_id = -1;
    m_voltageV = 0.0f;
    m_temperatureC = 25.0f;
    m_active = false;

}

//constructor --> Parameterized
HeapSensor::HeapSensor(int id_, float voltageV_, float temperatureC_, bool active_){
    
    // validate id
    if(id_<0) {throw std::invalid_argument("InvalidIDException: \"Id can never be -ve\"");}
    else {m_id = id_;}

    // cap and assign voltage and temperature
    m_voltageV = (voltageV_ > MAX_VOLTAGE) ? MAX_VOLTAGE : ((voltageV_ < MIN_VOLTAGE) ? MIN_VOLTAGE : voltageV_);
    m_temperatureC = (temperatureC_ > MAX_TEMPERATURE) ? MAX_TEMPERATURE : ((temperatureC_ < MIN_TEMPERATURE) ? MIN_TEMPERATURE : temperatureC_);

    m_active = active_;

    // increment instances
    s_totalInstances++;
}

// getters
int HeapSensor::getId() const{
    return m_id;
}
float HeapSensor::getVoltageV() const{
    return m_voltageV;
}
float HeapSensor::getTemperatureC() const{
    return m_temperatureC;
}
bool HeapSensor::getActive() const{
    return m_active;
}
int HeapSensor::getTotalInstances(){
    return s_totalInstances;
}

// setters
void HeapSensor::setId(int id_){
    // validate id
    if(id_<0) {throw std::invalid_argument("InvalidIDException: \"Id can never be -ve\"");}
    else {m_id = id_;}
}
void HeapSensor::setVoltageV(float voltageV_){
    m_voltageV = (voltageV_ > MAX_VOLTAGE) ? MAX_VOLTAGE : ((voltageV_ < MIN_VOLTAGE) ? MIN_VOLTAGE : voltageV_);
}
void HeapSensor::setTemperatureC(float temperatureC_){
     m_temperatureC = (temperatureC_ > MAX_TEMPERATURE) ? MAX_TEMPERATURE : ((temperatureC_ < MIN_TEMPERATURE) ? MIN_TEMPERATURE : temperatureC_);
}
void HeapSensor::setActive(bool active_){
    m_active = active_;
}

// overloaded function
void HeapSensor::calibrate(float tempOffset_){
    setTemperatureC(getTemperatureC() + tempOffset_);
}

void HeapSensor::calibrate(float tempScale_, float tempOffset_){
    setTemperatureC((getTemperatureC()*tempScale_) + tempOffset_);
}

// desctructor
HeapSensor::~HeapSensor(){
    s_totalInstances--;
}