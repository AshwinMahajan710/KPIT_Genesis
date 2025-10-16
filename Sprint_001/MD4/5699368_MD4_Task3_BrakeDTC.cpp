#include"5699368_MD4_Task3_DTC.h"
#include"5699368_MD4_Task3_SeverityLevel.h"
#include"5699368_MD4_Task3_BrakeDTC.h"
#include<iostream>
#include<string>

// constructor for Brake DTC
BrakeDTC::BrakeDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,float brakePressure_,bool absEngaged_) : DTC(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_) ,  m_brakePressure(brakePressure_), m_absEngaged(absEngaged_){};

// printing braking system  info along with dtc
void BrakeDTC::printBrakeDTCInfo() const{
    printDTCInfo(); // will call engine dtc info
    std::cout<<"Brake Pressure: "<<m_brakePressure<<std::endl;
    std::cout<<"ABS Engagement status status: "<<(m_absEngaged ? "YES" : "NO")<<std::endl;
}

// function to check brake abs failure status
bool BrakeDTC::isABSFailure() const{
    return (!m_absEngaged);
}

