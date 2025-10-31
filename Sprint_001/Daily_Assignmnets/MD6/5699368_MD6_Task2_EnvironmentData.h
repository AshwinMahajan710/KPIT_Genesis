#ifndef ENVIRONMENTDATA_H
#define ENVIRONMENTDATA_H

#include"5699368_MD6_Task2_DTC.h"

class EnvironmentData: public DTC{
    private:
        float m_ambientTemperature;
        float m_altitude;
        float m_humidity;

    public:
        EnvironmentData(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,float ambientTemp_, float altitude_, float humidity_);
        void printEnvironmentData() const;
};

#endif // ENVIROMENTALDATA_H
