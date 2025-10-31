#ifndef FULL_ENGINE_DTC_H
#define FULL_ENGINE_DTC_H
#include"5699368_MD6_Task2_EngineDTC.h"
#include"5699368_MD6_Task2_EnvironmentData.h"

class FullEngineDTC: public EngineDTC, public EnvironmentData{
    private:
        std::string m_testConditionNote;
    public:
        FullEngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,int rpmAtFault_, float coolantTemp_, float ambientTemp_, float altitude_, float humidity_, const std::string& testConditionNote_);
        void printFullDTCReport() const;
};

#endif // FULL_ENGINE_DTC_H
