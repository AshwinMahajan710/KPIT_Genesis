#ifndef DTC_H
#define DTC_H

#include<string>
#include<ctime>
#include"5699368_MD2_Task2_SeverityLevel.h"

class DTC{

    // All private attributes
    private:
        std::string m_code;    
        std::string m_description;
        bool m_active;
        int m_occurenceCount;
        std::time_t m_lastOccurenceTime;
        SeverityLevel m_severityLevel;
        bool m_confirmed;
        bool m_pending;
        bool m_milOn;
        std::string m_system;
        std::string m_origin;
    
    public:

        // constructors 
        DTC();
        DTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_);
        DTC(const DTC& other);

        // setters
        void setCode(const std::string& code_);
        void setDescription(const std::string& description_);
        void setActive(const bool active_);
        void setOccurenceCount(const int occurenceCount_);
        void setLastOccurenceTime(const std::time_t lastOccurenceTime_);
        void setSeverityLevel(const SeverityLevel severityLevel_);
        void setConfirmed(const bool confirmed_);
        void setPending(const bool pending_);
        void setMilOn(const bool milOn_);
        void setSystem(const std::string& system_);
        void setOrigin(const std::string& origin_);

        // Getters
        std::string getCode() const;    
        std::string getDescription() const;
        bool getActive() const;
        int getOccurenceCount() const;
        std::time_t getLastOccurenceTime() const;
        SeverityLevel getSeverityLevel() const;
        bool getConfirmed() const;
        bool getPending() const;
        bool getMilOn() const;
        std::string getSystem() const;
        std::string getOrigin() const;

        // methods
        void activate();
        void deActivate();
        void incrementOccurence();
        void printDTCInfo();
        void toggleMIL();
        void markConfirmed();

        // Additional method to get string string value of severity
        std::string getSeverityString();

        // New additional methods for DTC
        double computeRiskScore() const;
        std::string recommendAction() const;
        bool mergeIfSameCode(const DTC& other);
};

#endif