#ifndef ENGINEDTC_H
#define ENGINEDTC_H

#include <string>
#include "5699368_MD4_Task4_DTC.h"

// Class representing Engine-specific Diagnostic Trouble Code (DTC)
class EngineDTC : public DTC
{
private:
    int m_rpmAtFault;       // Engine RPM at the time of fault
    float m_coolantTemp;    // Coolant temperature in °C at the time of fault

public:
    // Constructor with member initializer list
    EngineDTC(const std::string& code,
              const std::string& description,
              bool isActive,
              int occurenceCount,
              std::time_t lastOccurenceTime,
              SeverityLevel severityLevel,
              bool isConfirmed,
              bool isPending,
              bool isMilOn,
              const std::string& system,
              const std::string& origin,
              int rpmAtFault,
              float coolantTemp);

    // Function to print engine-specific DTC details
    void printEngineDTCInfo() const;

    // Function to check if engine is overheated
    bool isOverheated() const;

    // Getter for coolant temperature
    float getCoolantTemp() const;
};

#endif // ENGINEDTC_H
