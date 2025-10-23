#include"5699368_MD6_Task4_DTC.h"
#include"5699368_MD6_Task4_SeverityLevel.h"
#include"5699368_MD6_Task4_EngineDTC.h"
#include<iostream>
#include<stdexcept>
#include<string>

// constructor for Engine DTC
EngineDTC::EngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,int severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,int rpmAtFault_, float coolantTemp_){

    // validation for coolant temp
    if(coolantTemp_ > 130.0) {throw std::invalid_argument("OverHeatRiskException: \"coolant Temperature exceeds safe threshold!");}
    else {m_coolantTemp = coolantTemp_;}

    // validation for rpm
    if(rpmAtFault_ < 0) {throw std::invalid_argument("NegativeRPMException: \"RPM cannot be -ve\"");}
    else {m_rpmAtFault = rpmAtFault_;}
    
};

// printing engine info along with dtc
void EngineDTC::printEngineDTCInfo() const{
    std::cout<<"Engine RPM at fault: "<<m_rpmAtFault<<std::endl;
    std::cout<<"Coolant Temperature: "<<m_coolantTemp<<std::endl;
}

// fuction to check engine is overheated or not
bool EngineDTC::isOverheated() const{
    return (m_coolantTemp > 120.0);
}

float EngineDTC::getCoolantTemp() const{
    return m_coolantTemp;
}