#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>
#include "5699368_MD3_Task1_SeverityLevel.h"
#include "5699368_MD3_Task1_DTCDiagnostics.h"

// DTC class representing a Diagnostic Trouble Code
class DTC
{
private:
    // Private member variables using consistent naming convention (m_ prefix)
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

    // MISRA-compliant constant
    static constexpr int m_maxSeverity = 2; // Renamed for consistent camelCase

    // Static member to track DTC object count
    static int s_dtcCount; // Renamed for camelCase

public:
    // --------------------------
    // Constructors
    // --------------------------
    DTC(); // Default constructor
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

    DTC(const DTC& other); // Copy constructor

    // Destructor
    ~DTC();

    // --------------------------
    // Setters
    // --------------------------
    void setCode(const std::string& code_);
    void setDescription(const std::string& description_);
    void setActive(bool active_); // Removed const for MISRA compliance
    void setOccurenceCount(int occurenceCount_);
    void setLastOccurenceTime(std::time_t lastOccurenceTime_);
    void setSeverityLevel(SeverityLevel severityLevel_);
    void setConfirmed(bool confirmed_);
    void setPending(bool pending_);
    void setMilOn(bool milOn_);
    void setSystem(const std::string& system_);
    void setOrigin(const std::string& origin_);
    void setSeverity(int level_);        // Overloaded: integer
    void setSeverity(const std::string& name_); // Overloaded: string
    void markActive(bool state_ = true); // Optional argument

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
    static int getDTCCount(); // Static getter

    // --------------------------
    // Core Member Functions
    // --------------------------
    void activate();
    void deActivate();
    void incrementOccurence();
    void printDTCInfo() const;
    void toggleMIL();
    void markConfirmed();

    // --------------------------
    // Additional Methods
    // --------------------------
    std::string getSeverityString() const; // Returns string representation of severity
    double computeRiskScore() const;       // Computes risk score (0-100)
    std::string recommendAction() const;   // Provides recommendation based on risk
    bool mergeIfSameCode(const DTC& other); // Merge DTCs if code matches
    void printSummary() const;             // Print key DTC information

    // --------------------------
    // Friend Functions
    // --------------------------
    friend bool isSevere(const DTC& dtc); // Checks if severity is critical
    friend void resetDTC(DTC& dtc);       // Resets DTC to default values

    // --------------------------
    // Friend Classes
    // --------------------------
    friend class DTCDiagnostics; // Allows DTCDiagnostics to access private members
};

#endif
