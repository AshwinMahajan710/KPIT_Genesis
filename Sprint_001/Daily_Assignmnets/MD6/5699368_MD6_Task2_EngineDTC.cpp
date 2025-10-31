#include"5699368_MD6_Task2_DTC.h"
#include"5699368_MD6_Task2_SeverityLevel.h"
#include"5699368_MD6_Task2_EngineDTC.h"
#include<iostream>
#include<string>

// constructor for Engine DTC
EngineDTC::EngineDTC(int rpmAtFault_, float coolantTemp_): m_coolantTemp(coolantTemp_), m_rpmAtFault(rpmAtFault_) {}

// printing engine info along with dtc
void EngineDTC::printEngineDTCInfo() const{
    std::cout<<"Engine RPM at fault: "<<m_rpmAtFault<<std::endl;
    std::cout<<"Coolant Temperature: "<<m_coolantTemp<<std::endl;
}

// fuction to check engine is overheated or not
bool EngineDTC::isOverheated() const{
    return (m_coolantTemp > 120.0);
}

