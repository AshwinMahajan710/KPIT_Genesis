#include "5699368_MD4_Task4_DTC.h"
#include "5699368_MD4_Task4_SeverityLevel.h"
#include "5699368_MD4_Task4_EngineDTC.h"
#include <iostream>
#include <string>

// Constructor for EngineDTC
EngineDTC::EngineDTC(const std::string& code,
                     const std::string& description,
                     bool isActive,
                     int occurrenceCount,
                     std::time_t lastOccurrenceTime,
                     SeverityLevel severityLevel,
                     bool isConfirmed,
                     bool isPending,
                     bool isMilOn,
                     const std::string& system,
                     const std::string& origin,
                     int rpmAtFault,
                     float coolantTemp)
    : DTC(code, description, isActive, occurrenceCount, lastOccurrenceTime,
          severityLevel, isConfirmed, isPending, isMilOn, system, origin),
      m_rpmAtFault(rpmAtFault),
      m_coolantTemp(coolantTemp)
{
    // No additional initialization required
}

// Print Engine DTC info (includes engine-specific data)
void EngineDTC::printEngineDTCInfo() const
{
    std::cout << "Engine RPM at fault: " << m_rpmAtFault << '\n';
    std::cout << "Coolant Temperature: " << m_coolantTemp << " °C" << '\n';
}

// Function to check if the engine is overheated
bool EngineDTC::isOverheated() const
{
    constexpr float OVERHEAT_THRESHOLD = 120.0F; // Defined constant instead of magic number
    return (m_coolantTemp > OVERHEAT_THRESHOLD);
}

// Getter for coolant temperature
float EngineDTC::getCoolantTemp() const
{
    return m_coolantTemp;
}
