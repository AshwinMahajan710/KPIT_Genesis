#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include <iostream>
#include "5699368_MD4_Task1_SeverityLevel.h"

// Class representing a Diagnostic Trouble Code (DTC)
class DTC
{
private:
    // Private data members (all prefixed with 'm_' for clarity)
    std::string m_code;
    std::string m_description;
    bool m_isActive;
    int m_occurenceCount;
    std::time_t m_lastOccurenceTime;
    SeverityLevel m_severityLevel;
    bool m_isConfirmed;
    bool m_isPending;
    bool m_isMilOn;
    std::string m_system;
    std::string m_origin;
    static int s_DTCCount;         // Static counter for tracking DTC instances
    static constexpr int MAX_SEVERITY = 2; // Maximum severity value for validation

public:
    // Constructors
    DTC();
    DTC(const std::string& code,
        const std::string& description,
        bool isActive,
        int occurenceCount,
        std::time_t lastOccurenceTime,
        SeverityLevel severityLevel,
        bool isConfirmed,
        bool isPending,
        bool isMilOn,
        const std::string& system,
        const std::string& origin);

    DTC(const DTC& other);

    // Destructor
    ~DTC();

    // Setters
    void setCode(const std::string& code);
    void setDescription(const std::string& description);
    void setActive(bool isActive);
    void setOccurenceCount(int occurenceCount);
    void setLastOccurenceTime(std::time_t lastOccurenceTime);
    void setSeverityLevel(SeverityLevel severityLevel);
    void setConfirmed(bool isConfirmed);
    void setPending(bool isPending);
    void setMilOn(bool isMilOn);
    void setSystem(const std::string& system);
    void setOrigin(const std::string& origin);

    // Overloaded severity setters
    void setSeverity(int level);
    void setSeverity(const std::string& name);

    // Method to mark DTC active (default argument = true)
    void markActive(bool state = true);

    // Getters
    std::string getCode() const;
    std::string getDescription() const;
    bool isActive() const;
    int getOccurenceCount() const;
    std::time_t getLastOccurenceTime() const;
    SeverityLevel getSeverityLevel() const;
    bool isConfirmed() const;
    bool isPending() const;
    bool isMilOn() const;
    std::string getSystem() const;
    std::string getOrigin() const;
    static int getDTCCount();

    // Functional methods
    void activate();
    void deactivate();
    void incrementOccurence();
    void printDTCInfo() const;
    void toggleMIL();
    void markConfirmed();
    std::string getSeverityString() const;

    // Additional analytical and utility methods
    double computeRiskScore() const;
    std::string recommendAction() const;
    bool mergeIfSameCode(const DTC& other);

    // Summary print method
    void printSummary() const;

    // Friend functions
    friend bool isSevere(const DTC& dtc);
    friend void resetDTC(DTC& dtc);

    // Operator overloads
    bool operator==(const DTC& other) const;
    bool operator!=(const DTC& other) const;
    DTC& operator++();      // Prefix increment
    DTC operator++(int);    // Postfix increment
    friend std::ostream& operator<<(std::ostream& out, const DTC& dtc);
    DTC& operator=(const DTC& other);
    void operator()() const;
    std::string operator[](const std::string& attribute) const;
    bool operator!() const;
    bool operator<(const DTC& other) const;
    bool operator>(const DTC& other) const;
};

#endif // DTC_H
