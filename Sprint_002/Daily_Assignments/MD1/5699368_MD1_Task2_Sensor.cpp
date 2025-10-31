#include"5699368_MD1_Task2_SensorType.h"
#include<string>
#include<iostream>
#include"5699368_MD1_Task2_Sensor.h"


Sensor::Sensor(SensorType type_){
    m_sensorType = type_;
}

// show sensor function to check which sensor it is
void Sensor::showSensor() const{
    switch (m_sensorType)
    {
        case SensorType::PRESSURE:{
            std::cout<<"Pressure"<<std::endl;
            break;
        }
        case SensorType::SPEED:{
            std::cout<<"Speed"<<std::endl;
            break;
        }
        case SensorType::TEMPERATURE:{
            std::cout<<"Temperature"<<std::endl;
            break;
        }
    }
}