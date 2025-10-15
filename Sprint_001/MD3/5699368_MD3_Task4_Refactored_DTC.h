#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include <iostream>
#include "5699368_MD3_Task4_SeverityLevel.h"
#include "5699368_MD3_Task4_DTCDiagnostics.h"

class DTC
{
private:
    // All private member variables (consistent 'm_' prefix)
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
    const int m_maxSeverity = 2; // ✅ Renamed from m_MAX_SEVRITY → m_maxSeverity (consistent naming)
    static int s_dtcCount;       // ✅ Renamed from s_DTCCount → s_dtcCount (consistent lowerCamelCase)

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
    void setActive(const bool localIsActive);
    void setOccurrenceCount(const int localOccurrenceCount);
    void setLastOccurrenceTime(const std::time_t localLastOccurrenceTime);
    void setSeverityLevel(const SeverityLevel localSeverityLevel);
    void setConfirmed(const bool localIsConfirmed);
    void setPending(const bool localIsPending);
    void setMilOn(const bool localIsMilOn);
    void setSystem(const std::string& localSystem);
    void setOrigin(const std::string& localOrigin);
    void setSeverity(int localLevel);              // Overloaded function - set severity by integer
    void setSeverity(const std::string& localName); // Overloaded function - set severity by string
    void markActive(bool localState = true);       // Default parameter included

    // Getters (const-correct)
    std::string getCode() const;    
    std::string getDescription() const;
    bool isActive() const;                         // ✅ Changed name from getActive() to isActive() (boolean getters use "is")
    int getOccurrenceCount() const;                // ✅ Spelling correction from Occurence → Occurrence
    std::time_t getLastOccurrenceTime() const;
    SeverityLevel getSeverityLevel() const;
    bool isConfirmed() const;                      // ✅ Consistent boolean getter
    bool isPending() const;
    bool isMilOn() const;
    std::string getSystem() const;
    std::string getOrigin() const;
    static int getDtcCount();                      // ✅ Consistent with s_dtcCount

    // Methods
    void activate();
    void deactivate();                             // ✅ Renamed from deActivate() → deactivate() (consistent style)
    void incrementOccurrence();                    // ✅ Spelling fix (Occurence → Occurrence)
    void printDtcInfo() const;                     // ✅ Renamed from printDTCInfo() → printDtcInfo()
    void toggleMil();                              // ✅ Renamed from toggleMIL() → toggleMil() (consistent naming)
    void markConfirmed();

    // Additional methods
    std::string getSeverityString() const;
    double computeRiskScore() const;
    std::string recommendAction() const;
    bool mergeIfSameCode(const DTC& other);

    // Summary printer
    void printSummary() const;

    // Friend functions
    friend bool isSevere(const DTC& localDtc);
    friend void resetDtc(DTC& localDtc);           // ✅ Renamed from resetDTC() → resetDtc()

    // Friend class
    friend class DTCDiagnostics;

    // Operator overloading
    bool operator==(const DTC& otherDtc) const;
    bool operator!=(const DTC& otherDtc) const;
    DTC& operator++();         // Prefix
    DTC operator++(int);       // Postfix
    friend std::ostream& operator<<(std::ostream& out, const DTC& otherDtc);
    DTC& operator=(const DTC& otherDtc);           // ✅ Return type changed to DTC& (MISRA prefers assignment returning *this)
    void operator()() const;
    std::string operator[](const std::string& attribute) const;
    bool operator!() const;
    bool operator<(const DTC& otherDtc) const;
    bool operator>(const DTC& otherDtc) const;
};

#endif // DTC_H
