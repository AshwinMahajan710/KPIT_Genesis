#include"5699368_MD4_Task2_EngineDTC.h"
#include"5699368_MD4_Task2_FullEngineDTC.h"
#include"5699368_MD4_Task2_EnvironmentData.h"
#include<iostream>
#include<string>

// constructor
FullEngineDTC:: FullEngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,int rpmAtFault_, float coolantTemp_, float ambientTemp_, float altitude_, float humidity_, const std::string& testConditionNote_): EngineDTC(code_,description_, active_, occurenceCount_, lastOccurenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_, rpmAtFault_, coolantTemp_), EnvironmentData(ambientTemp_, altitude_, humidity_), m_testConditionNote(testConditionNote_){};

// printing full report
void FullEngineDTC::printFullDTCReport() const{
    printEngineDTCInfo();
    printEnvironmentData();
    std::cout<<"Test Condition Note: "<<m_testConditionNote<<std::endl;
}