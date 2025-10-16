#include"5699368_MD4_Task4_DTC.h"
#include"5699368_MD4_Task4_SeverityLevel.h"
#include"5699368_MD4_Task4_EngineDTC.h"
#include<iostream>
#include<string>

// constructor for Engine DTC
EngineDTC::EngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,int rpmAtFault_, float coolantTemp_) : DTC(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_) ,  m_rpmAtFault(rpmAtFault_), m_coolantTemp(coolantTemp_){};

// printing engine info along with dtc
void EngineDTC::printEngineDTCInfo() const{
    std::cout<<"Engine RPM at fault: "<<m_rpmAtFault<<std::endl;
    std::cout<<"Coolant Temperature: "<<m_coolantTemp<<std::endl;
}

// fuction to check engine is overheated or not
bool EngineDTC::isOverheated() const{
    return (m_coolantTemp > 120.0);
}

float EngineDTC:: getCoolantTemp() const{
    return m_coolantTemp;
}

