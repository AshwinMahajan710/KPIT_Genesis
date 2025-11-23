#include<iostream>
#include"5699368_MD4_Task4_EnvironmentData.h"

// constructor
EnvironmentData::EnvironmentData(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,float ambientTemp_, float altitude_, float humidity_): DTC(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_),m_ambientTemperature(ambientTemp_), m_altitude(altitude_), m_humidity(humidity_){};

// printing info
void EnvironmentData::printEnvironmentData() const{
    std::cout<<"Ambient Temp: "<<m_ambientTemperature<<std::endl;
    std::cout<<"Altitude: "<<m_altitude<<std::endl;
    std::cout<<"Humidity: "<<m_humidity<<std::endl;
}

// extreme condition function
bool EnvironmentData::isExtremeCondition() const{
    if(m_ambientTemperature > 50.0 || m_humidity > 50.0) {return true;}
    else {return false;}
}

float EnvironmentData::getAmbientTemperature() const{
    return m_ambientTemperature;
}