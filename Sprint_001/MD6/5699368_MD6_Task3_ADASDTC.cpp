#include"5699368_MD6_Task3_DTC.h"
#include"5699368_MD6_Task3_SeverityLevel.h"
#include"5699368_MD6_Task3_ADASDTC.h"
#include<iostream>
#include<string>

// constructor for ADAS DTC
ADASDTC::ADASDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,std::string sensorType_, float confidenceScore_) : DTC(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_) ,  m_sensorType(sensorType_){

    // validating sensor confidence
    if(confidenceScore_ >= 0.0 && confidenceScore_ <= 1.0) {m_confidenceScore = confidenceScore_;}
    else{throw std::invalid_argument("SensorConfidenceException: \"Sensor confidence score must be between 0.0 to 1.0");}
};

// printing braking system  info along with dtc
void ADASDTC::printADASDTCInfo() const{
    printDTCInfo(); // will call engine dtc info
    std::cout<<"Sensor Type: "<<m_sensorType<<std::endl;
    std::cout<<"Confidence Score: "<<m_confidenceScore<<std::endl;
}

// function to check brake abs failure status
bool ADASDTC::isSensorFaultLikely() const{
    return (m_confidenceScore<0.5);
}



