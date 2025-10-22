#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include "5699368_MD2_Task3_SeverityLevel.h"

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
    static int s_DTCCount; // Count of DTC objects

public:
    // Constructors
    DTC(); // Default constructor
    DTC(const std::string &code_,           // Added const & for MISRA compliance
        const std::string &description_,    // Added const &
        bool active_,
        int occurenceCount_,
        std::time_t lastOccurenceTime_,
        SeverityLevel severityLevel_,
        bool confirmed_,
        bool pending_,
        bool milOn_,
        const std::string &system_,         // Added const &
        const std::string &origin_);        // Added const &
    DTC(const DTC &other);                  // Copy constructor

    // Destructor
    ~DTC();

    // Setters (removed const from small types like bool, int; added const & for strings)
    void setCode(const std::string &code_);
    void setDescription(const std::string &description_);
    void setActive(bool active_);
    void setOccurenceCount(int occurenceCount_);
    void setLastOccurenceTime(std::time_t lastOccurenceTime_);
    void setSeverityLevel(SeverityLevel severityLevel_);
    void setConfirmed(bool confirmed_);
    void setPending(bool pending_);
    void setMilOn(bool milOn_);
    void setSystem(const std::string &system_);
    void setOrigin(const std::string &origin_);
    void setSeverity(int level_);           // Overloaded: int
    void setSeverity(const std::string &name_); // Overloaded: string
    void markActive(bool state_ = true);    // Default argument kept (acceptable)

    // Getters (added const for MISRA)
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

    // Member methods
    void activate();
    void deActivate();
    void incrementOccurence();
    void printDTCInfo() const;            // Added const
    void toggleMIL();
    void markConfirmed();

    // Additional method for severity as string
    std::string getSeverityString() const; // Added const

    // New methods
    double computeRiskScore() const;
    std::string recommendAction() const;
    bool mergeIfSameCode(const DTC &other); // Added const &
};

#endif
