#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include "5699368_MD1_Task2_SeverityLevel.h"

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

public:
    // Constructors
    DTC();
    DTC(const std::string &code,
        const std::string &description,
        const bool active,
        const int occurenceCount,
        const std::time_t lastOccurenceTime,
        const SeverityLevel severityLevel,
        const bool confirmed,
        const bool pending,
        const bool milOn,
        const std::string &system,
        const std::string &origin);

    DTC(const DTC &other);

    // Setters
    void setCode(const std::string &code);
    void setDescription(const std::string &description);
    void setActive(const bool active);
    void setOccurenceCount(const int occurenceCount);
    void setLastOccurenceTime(const std::time_t lastOccurenceTime);
    void setSeverityLevel(const SeverityLevel severityLevel);
    void setConfirmed(const bool confirmed);
    void setPending(const bool pending);
    void setMilOn(const bool milOn);
    void setSystem(const std::string &system);
    void setOrigin(const std::string &origin);

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

    // Methods
    void activate();
    void deActivate();
    void incrementOccurence();
    void printDTCInfo() const;
    void toggleMIL();
    void markConfirmed();

    // Additional method
    std::string getSeverityString() const;
};

#endif // DTC_H
