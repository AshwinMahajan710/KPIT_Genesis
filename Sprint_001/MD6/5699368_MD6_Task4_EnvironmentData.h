#ifndef ENVIRONMENTDATA_H
#define ENVIRONMENTDATA_H

#include"5699368_MD6_Task4_DTC.h"

class EnvironmentData: virtual public DTC{
    private:
        float m_ambientTemperature;
        float m_altitude;
        float m_humidity;

    public:
        EnvironmentData(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,int severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,float ambientTemp_, float altitude_, float humidity_);
        bool isExtremeCondition() const;
        void printEnvironmentData() const;

        // getter for ambient temp
        float getAmbientTemperature() const;
};

#endif // ENVIROMENTALDATA_H
