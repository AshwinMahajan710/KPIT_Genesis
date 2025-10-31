#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include "5699368_MD2_Task4_SeverityLevel.h"

class DTC
{
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
    const int m_MAX_SEVRITY = 2;
    static int s_DTCCount;

public:
    // Constructors
    DTC(); // no change
    DTC(const std::string &code_,             // Added const & for MISRA: avoids copying
        const std::string &description_,      // Added const &
        bool active_,
        int occurenceCount_,
        std::time_t lastOccurenceTime_,
        SeverityLevel severityLevel_,
        bool confirmed_,
        bool pending_,
        bool milOn_,
        const std::string &system_,           // Added const &
        const std::string &origin_);          // Added const &

    DTC(const DTC &other); // copy constructor

    // Destructor
    ~DTC();

    // Setters
    void setCode(const std::string &code_);             // Added const & to follow MISRA
    void setDescription(const std::string &description_); // Added const &
    void setActive(bool active_);                        // Removed const qualifier from bool, MISRA recommends pass-by-value for bool
    void setOccurenceCount(int occurenceCount_);         // Removed const qualifier for int, MISRA recommends pass-by-value for small types
    void setLastOccurenceTime(std::time_t lastOccurenceTime_); // Same as above
    void setSeverityLevel(SeverityLevel severityLevel_);
    void setConfirmed(bool confirmed_);
    void setPending(bool pending_);
    void setMilOn(bool milOn_);
    void setSystem(const std::string &system_);         // Added const &
    void setOrigin(const std::string &origin_);         // Added const &
    void setSeverity(int level_);
    void setSeverity(const std::string &name_);
    void markActive(bool state_ = true);                // default argument kept; MISRA usually warns but acceptable in this context

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

    // Methods
    void activate();
    void deActivate();
    void incrementOccurence();
    void printDTCInfo() const;          // Added const to indicate it does not modify object
    void toggleMIL();
    void markConfirmed();

    std::string getSeverityString() const; // Added const

    double computeRiskScore() const;       // Added const
    std::string recommendAction() const;   // Added const
    bool mergeIfSameCode(const DTC &other); // Added const &

    void printSummary() const;             // Added const
};

#endif
