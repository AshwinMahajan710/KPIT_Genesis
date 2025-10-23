#ifndef ENGINEDTC_H
#define ENGINEDTC_H

#include<string>
#include"5699368_MD6_Task4_DTC.h"

// class engine DTC
class EngineDTC: virtual public DTC{
    private:
        int m_rpmAtFault;
        float m_coolantTemp;

    public:
        EngineDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,int severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_, int rpmAtFault_, float coolantTemp_);
        void printEngineDTCInfo() const;
        bool isOverheated() const;
        float getCoolantTemp() const;

};

#endif // ENGINEDTC_H
