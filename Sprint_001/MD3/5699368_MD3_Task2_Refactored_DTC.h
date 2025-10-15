#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include <iostream>
#include "5699368_MD3_Task2_SeverityLevel.h"
#include "5699368_MD3_Task2_DTCDiagnostics.h"

// Refactored class with MISRA-compliant naming and consistent style
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

    static int s_dtcCount;              // renamed from s_DTCCount → s_dtcCount (consistent camelCase)
    const int m_maxSeverity = 2;        // renamed from m_MAX_SEVRITY → m_maxSeverity, MISRA: no all-caps for const members

public:
    // --------------------------
    // Constructors
    // --------------------------
    DTC();  // Default constructor
    DTC(const std::string& code_,
        const std::string& description_,
        bool active_,
        int occurenceCount_,
        std::time_t lastOccurenceTime_,
        SeverityLevel severityLevel_,
        bool confirmed_,
        bool pending_,
        bool milOn_,
        const std::string& system_,
        const std::string& origin_);
    DTC(const DTC& other);  // Copy constructor

    // --------------------------
    // Destructor
    // --------------------------
    ~DTC();

    // --------------------------
    // Setters
    // --------------------------
    void setCode(const std::string& code_);
    void setDescription(const std::string& description_);
    void setActive(bool active_);                      // removed const from bool, MISRA prefers simple type
    void setOccurenceCount(int occurenceCount_);       // removed const from int
    void setLastOccurenceTime(std::time_t lastOccurenceTime_);
    void setSeverityLevel(SeverityLevel severityLevel_);
    void setConfirmed(bool confirmed_);
    void setPending(bool pending_);
    void setMilOn(bool milOn_);
    void setSystem(const std::string& system_);
    void setOrigin(const std::string& origin_);
    void setSeverity(int level_);                      // Overloaded: using int
    void setSeverity(const std::string& name_);       // Overloaded: using string
    void markActive(bool state_ = true);              // Default argument for optional activation

    // --------------------------
    // Getters
    // --------------------------
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
    static int getDTCCount();                         // Static getter for total DTC instances

    // --------------------------
    // Member methods
    // --------------------------
    void activate();
    void deActivate();
    void incrementOccurence();
    void printDTCInfo() const;                        // Made const as it doesn't modify object
    void toggleMIL();
    void markConfirmed();
    std::string getSeverityString() const;            // Added const for safety

    double computeRiskScore() const;
    std::string recommendAction() const;
    bool mergeIfSameCode(const DTC& other);
    void printSummary() const;

    // --------------------------
    // Friend functions
    // --------------------------
    friend bool isSevere(const DTC& dtc);
    friend void resetDTC(DTC& dtc);
    friend class DTCDiagnostics;                      // Class friendship retained

    // --------------------------
    // Operator overloads
    // --------------------------
    bool operator==(const DTC& otherDtc) const;
    bool operator!=(const DTC& otherDtc) const;
    DTC& operator++();           // Prefix increment
    DTC operator++(int);         // Postfix increment
    void operator=(const DTC& otherDtc);
    void operator()() const;
    std::string operator[](const std::string& attribute) const; // const reference for MISRA
    bool operator!() const;
    bool operator<(const DTC& otherDtc) const;
    bool operator>(const DTC& otherDtc) const;

    friend std::ostream& operator<<(std::ostream& out, const DTC& otherDtc);
};

#endif // DTC_H
