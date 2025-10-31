#include<string>
#include<iostream>
#include"5699368_MD1_Task2_ActuatorType.h"
#include"5699368_MD1_Task2_Actuator.h"
#include"5699368_MD1_Task2_SensorType.h"
#include"5699368_MD1_Task2_Sensor.h"
#include"5699368_MD1_Task2_ECU.h"


ECU::ECU(Sensor sensor_){
    m_actuator = nullptr;
    m_sensor = sensor_;
}

void ECU::ConnectActuator(Actuator* actuator_){
    m_actuator = actuator_;
}

void ECU::showStatus() const{
    m_sensor.showSensor();
    if(m_actuator == nullptr){std::cout<<"No actuator"<<std::endl;}
    else {m_actuator->showActuator();}
}

ECU::~ECU(){
    if(m_actuator!=nullptr){
        delete m_actuator;
    }
}