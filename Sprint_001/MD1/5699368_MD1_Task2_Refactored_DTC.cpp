#include "5699368_MD1_Task2_SeverityLevel.h"
#include "5699368_MD1_Task2_Refactored_DTC.h"
#include <iostream>
#include <ctime>
#include <string>

// Default constructor
DTC::DTC()
    : m_code(),
      m_description(),
      m_active(false),
      m_occurenceCount(0),
      m_lastOccurenceTime(0),
      m_severityLevel(SeverityLevel::NORMAL),
      m_confirmed(false),
      m_pending(false),
      m_milOn(false),
      m_system(),
      m_origin()
{
}

// Parameterized constructor
DTC::DTC(const std::string &code,
         const std::string &description,
         const bool active,
         const int occurenceCount,
         const std::time_t lastOccurenceTime,
         const SeverityLevel severityLevel,
         const bool confirmed,
         const bool pending,
         const bool milOn,
         const std::string &system,
         const std::string &origin)
    : m_code(code),
      m_description(description),
      m_active(active),
      m_occurenceCount(occurenceCount),
      m_lastOccurenceTime(lastOccurenceTime),
      m_severityLevel(severityLevel),
      m_confirmed(confirmed),
      m_pending(pending),
      m_milOn(milOn),
      m_system(system),
      m_origin(origin)
{
}

// Copy constructor
DTC::DTC(const DTC &other)
    : m_code(other.m_code),
      m_description(other.m_description),
      m_active(other.m_active),
      m_occurenceCount(other.m_occurenceCount),
      m_lastOccurenceTime(other.m_lastOccurenceTime),
      m_severityLevel(other.m_severityLevel),
      m_confirmed(other.m_confirmed),
      m_pending(other.m_pending),
      m_milOn(other.m_milOn),
      m_system(other.m_system),
      m_origin(other.m_origin)
{
}

// Getters
std::string DTC::getCode() const
{
    return m_code;
}

std::string DTC::getDescription() const
{
    return m_description;
}

bool DTC::getActive() const
{
    return m_active;
}

int DTC::getOccurenceCount() const
{
    return m_occurenceCount;
}

std::time_t DTC::getLastOccurenceTime() const
{
    return m_lastOccurenceTime;
}

SeverityLevel DTC::getSeverityLevel() const
{
    return m_severityLevel;
}

bool DTC::getConfirmed() const
{
    return m_confirmed;
}

bool DTC::getPending() const
{
    return m_pending;
}

bool DTC::getMilOn() const
{
    return m_milOn;
}

std::string DTC::getSystem() const
{
    return m_system;
}

std::string DTC::getOrigin() const
{
    return m_origin;
}

// Setters
void DTC::setCode(const std::string &code)
{
    m_code = code;
}

void DTC::setDescription(const std::string &description)
{
    m_description = description;
}

void DTC::setActive(const bool active)
{
    m_active = active;
}

void DTC::setOccurenceCount(const int occurenceCount)
{
    m_occurenceCount = occurenceCount;
}

void DTC::setLastOccurenceTime(const std::time_t lastOccurenceTime)
{
    m_lastOccurenceTime = lastOccurenceTime;
}

void DTC::setSeverityLevel(const SeverityLevel severityLevel)
{
    m_severityLevel = severityLevel;
}

void DTC::setConfirmed(const bool confirmed)
{
    m_confirmed = confirmed;
}

void DTC::setPending(const bool pending)
{
    m_pending = pending;
}

void DTC::setMilOn(const bool milOn)
{
    m_milOn = milOn;
}

void DTC::setSystem(const std::string &system)
{
    m_system = system;
}

void DTC::setOrigin(const std::string &origin)
{
    m_origin = origin;
}

// Member functions

void DTC::activate()
{
    m_active = true;
}

void DTC::deActivate()
{
    m_active = false;
}

void DTC::incrementOccurence()
{
    ++m_occurenceCount;
}

void DTC::printDTCInfo() const
{
    std::cout << "Code: " << m_code << std::endl;
    std::cout << "Description: " << m_description << std::endl;
    std::cout << "Activation status: " << ((m_active) ? "Active" : "Inactive") << std::endl;
    std::cout << "Occurance Count: " << m_occurenceCount << std::endl;
    std::cout << "Last Occurance Time: " << std::ctime(&m_lastOccurenceTime);
    std::cout << "Severity Level: " << getSeverityString() << std::endl;
    std::cout << "Detection Confirmed: " << ((m_confirmed) ? "True" : "False") << std::endl;
    std::cout << "Is pending confirmation: " << ((m_pending) ? "Yes" : "False") << std::endl;
    std::cout << "Malfunction Indicator light on: " << ((m_milOn) ? "Yes" : "No") << std::endl;
    std::cout << "Affected Subsystem: " << m_system << std::endl;
    std::cout << "DTC Origin: " << m_origin << std::endl;
}

void DTC::toggleMIL()
{
    m_milOn = !m_milOn;
}

void DTC::markConfirmed()
{
    m_confirmed = true;
    m_pending = false;
}

std::string DTC::getSeverityString() const
{
    switch (m_severityLevel)
    {
    case SeverityLevel::CRITICAL:
        return "Critical";

    case SeverityLevel::NORMAL:
        return "Normal";

    case SeverityLevel::WARN:
        return "Warning";

    default:
        return "UNKNOWN";
    }
}
