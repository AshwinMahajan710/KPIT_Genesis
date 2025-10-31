#include"5699368_MD1_Task2_ActuatorType.h"
#include<string>
#include<iostream>
#include"5699368_MD1_Task2_Actuator.h"


Actuator::Actuator(ActuatorType type_){
    m_actuatorType = type_;
}

// show sensor function to check which sensor it is
void Actuator::showActuator() const{
    switch (m_actuatorType)
    {
        case ActuatorType::DISPLAY:{
            std::cout<<"Display"<<std::endl;
            break;
        }
        case ActuatorType::MOTOR:{
            std::cout<<"Motor"<<std::endl;
            break;
        }
        case ActuatorType::VALVE:{
            std::cout<<"Valve"<<std::endl;
            break;
        }
    }
}