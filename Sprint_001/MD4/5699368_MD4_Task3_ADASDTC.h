#ifndef ADASDTC_H
#define ADASDTC_H

#include<string>
#include"5699368_MD4_Task3_DTC.h"

// class engine DTC
class ADASDTC: public DTC{
    private:
        std::string m_sensorType;
        float m_confidenceScore;

    public:
        ADASDTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_, std::string sensorType_, float confidenceScore_);
        void printADASDTCInfo() const;
        bool isSensorFaultLikely() const;
};

#endif // ADASDTC_H
