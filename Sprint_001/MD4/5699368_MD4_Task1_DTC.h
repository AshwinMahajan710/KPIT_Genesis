#ifndef DTC_H
#define DTC_H

#include<string>
#include<ctime>
#include"5699368_MD4_Task1_SeverityLevel.h"
#include<iostream>

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
        const int m_MAX_SEVRITY = 2; // setting up max_severity so that we can use this to take validity
        static int s_DTCCount; // will help in counting the DTC instances

    public:

        // constructors 
        DTC();
        DTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_);
        DTC(const DTC& other);

        // Destructor
        ~DTC();

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
        void setSeverity(int level_); // overloaded function which sets severity using int value
        void setSeverity(const std::string& name_); // overloaded function which sets severity using string name value
        void markActive(bool state_ = true); // sets state to active and additional default argument method

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
        static int getDTCCount();

        // methods
        void activate();
        void deActivate();
        void incrementOccurence();
        void printDTCInfo() const;
        void toggleMIL();
        void markConfirmed();

        // Additional method to get string string value of severity
        std::string getSeverityString() const;

        // New additional methods for DTC
        double computeRiskScore() const;
        std::string recommendAction() const;
        bool mergeIfSameCode(const DTC& other);

        // printsummary new member method to print key info of DTC
        void printSummary() const;

        // Now lets use friend function
        friend bool isSevere(const DTC& dtc);
        friend void resetDTC(DTC& dtc);

        // Operator overloading
        bool operator==(const DTC& otherDtc) const;
        bool operator!=(const DTC& otherDtc) const;
        DTC& operator++(); // for prefix 
        DTC operator++(int); // for postfix
        friend std::ostream& operator <<(std::ostream& out, const DTC& otherDtc);
        void operator =(const DTC& otherDtc);
        void operator()() const;
        std::string operator[](std::string attribute) const;
        bool operator!() const;
        bool operator<(const DTC& otherDtc) const;
        bool operator>(const DTC& otherDtc) const;
};

#endif