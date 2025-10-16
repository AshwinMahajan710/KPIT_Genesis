#ifndef SMART_ENGINE_DTC
#define SMART_ENGINE_DTC

#include"5699368_MD4_Task4_DTC.h"
#include"5699368_MD4_Task4_EngineDTC.h"
#include"5699368_MD4_Task4_EnvironmentData.h"

class SmartEngineDTC : virtual public EngineDTC, virtual public EnvironmentData{
    private:
        std::string m_faultContextNote;

    public:
        SmartEngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,int rpmAtFault_, float coolantTemp_,float ambientTemp_, float altitude_, float humidity_,const std::string& faultContextNote_);
        void printSmartDTCInfo() const;
        bool isHighRiskFault() const;
};

#endif 