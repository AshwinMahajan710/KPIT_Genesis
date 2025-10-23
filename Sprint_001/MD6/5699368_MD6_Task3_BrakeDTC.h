#ifndef BRAKEDTC_H
#define BRAKEDTC_H

#include<string>
#include"5699368_MD6_Task3_DTC.h"

// class engine DTC
class BrakeDTC: public DTC{
    private:
        bool m_absEngaged;
        float m_brakePressure;

    public:
        BrakeDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_, float brakePressure_, bool absEngaged_);
        void printBrakeDTCInfo() const;
        bool isABSFailure() const;
};

#endif // BRAKEDTC_H
