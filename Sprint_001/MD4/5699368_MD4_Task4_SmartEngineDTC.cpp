#include"5699368_MD4_Task4_DTC.h"
#include"5699368_MD4_Task4_EngineDTC.h"
#include"5699368_MD4_Task4_EnvironmentData.h"
#include"5699368_MD4_Task4_SmartEngineDTC.h"

// constructor
SmartEngineDTC::SmartEngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,int rpmAtFault_, float coolantTemp_,float ambientTemp_, float altitude_, float humidity_,const std::string& faultContextNote_):EngineDTC(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_,rpmAtFault_,coolantTemp_), EnvironmentData(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_,ambientTemp_,altitude_,humidity_), m_faultContextNote(faultContextNote_){};

// printing smart dtc info 
void SmartEngineDTC::printSmartDTCInfo() const{
    printDTCInfo();
    printEngineDTCInfo();
    printEnvironmentData();
    std::cout<<"Fault Context Note: "<<m_faultContextNote<<std::endl;
}

// another function to implement from SmartEngineDTC
bool SmartEngineDTC::isHighRiskFault() const{
    if(getCoolantTemp()> 120.0 && getAmbientTemperature() > 35.0){
        return true;
    }
    else {return false;}
}