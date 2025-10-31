#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include <iostream>
#include "5699368_MD3_Task3_SeverityLevel.h"
#include "5699368_MD3_Task3_DTCDiagnostics.h"

// Class: DTC
// Purpose: Represents a Diagnostic Trouble Code with relevant attributes and methods
class DTC
{
private:
    // Member variables (consistent 'm_' prefix)
    std::string m_code;
    std::string m_description;
    bool m_isActive;
    int m_occurrenceCount;
    std::time_t m_lastOccurrenceTime;
    SeverityLevel m_severityLevel;
    bool m_isConfirmed;
    bool m_isPending;
    bool m_isMilOn;
    std::string m_system;
    std::string m_origin;

    const int m_maxSeverity = 2; // ✅ consistent naming
    static int s_dtcCount;       // ✅ consistent naming

public:
    // Constructors
    DTC();
    DTC(const std::string& localCode,
        const std::string& localDescription,
        bool localIsActive,
        int localOccurrenceCount,
        std::time_t localLastOccurrenceTime,
        SeverityLevel localSeverityLevel,
        bool localIsConfirmed,
        bool localIsPending,
        bool localIsMilOn,
        const std::string& localSystem,
        const std::string& localOrigin);
    DTC(const DTC& other);

    // Destructor
    ~DTC();

    // Setters
    void setCode(const std::string& localCode);
    void setDescription(const std::string& localDescription);
    void setActive(bool localIsActive);
    void setOccurrenceCount(int localOccurrenceCount);
    void setLastOccurrenceTime(std::time_t localLastOccurrenceTime);
    void setSeverityLevel(SeverityLevel localSeverityLevel);
    void setConfirmed(bool localIsConfirmed);
    void setPending(bool localIsPending);
    void setMilOn(bool localIsMilOn);
    void setSystem(const std::string& localSystem);
    void setOrigin(const std::string& localOrigin);
    void setSeverity(int localLevel);              // Overloaded: int
    void setSeverity(const std::string& localName); // Overloaded: string
    void markActive(bool localState = true);

    // Getters (const-correct)
    std::string getCode() const;
    std::string getDescription() const;
    bool isActive() const;           // ✅ consistent boolean getter
    int getOccurrenceCount() const;
    std::time_t getLastOccurrenceTime() const;
    SeverityLevel getSeverityLevel() const;
    bool isConfirmed() const;
    bool isPending() const;
    bool isMilOn() const;
    std::string getSystem() const;
    std::string getOrigin() const;
    static int getDtcCount();

    // Member methods
    void activate();
    void deactivate();               // ✅ consistent naming
    void incrementOccurrence();
    void printDtcInfo() const;
    void toggleMil();
    void markConfirmed();

    // Additional methods
    std::string getSeverityString() const;
    double computeRiskScore() const;
    std::string recommendAction() const;
    bool mergeIfSameCode(const DTC& other);
    void printSummary() const;

    // Friend functions
    friend bool isSevere(const DTC& localDtc);
    friend void resetDtc(DTC& localDtc);

    // Friend class
    friend class DTCDiagnostics;

    // Operator overloading
    bool operator==(const DTC& otherDtc) const;
    bool operator!=(const DTC& otherDtc) const;
    DTC& operator++();         // Prefix
    DTC operator++(int);       // Postfix
    DTC& operator=(const DTC& otherDtc);
    void operator()() const;
    std::string operator[](const std::string& attribute) const;
    bool operator!() const;
    bool operator<(const DTC& otherDtc) const;
    bool operator>(const DTC& otherDtc) const;
    friend std::ostream& operator<<(std::ostream& out, const DTC& otherDtc);
};

#endif // DTC_H
