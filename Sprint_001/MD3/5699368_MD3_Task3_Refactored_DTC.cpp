#include "5699368_MD3_Task3_Refactored_DTC.h"
#include "5699368_MD3_Task3_SeverityLevel.h"
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm> // for std::min, std::max

// Static variable initialization
int DTC::s_dtcCount = 0;

// Default constructor using constructor delegation
DTC::DTC()
    : DTC("", "", false, 0, 0, SeverityLevel::INFO, false, false, false, "", "")
{
}

// Parameterized constructor
DTC::DTC(const std::string& localCode,
         const std::string& localDescription,
         bool localIsActive,
         int localOccurrenceCount,
         std::time_t localLastOccurrenceTime,
         SeverityLevel localSeverityLevel,
         bool localIsConfirmed,
         bool localIsPending,
         bool localIsMilOn,
         const std::string& localSystem,
         const std::string& localOrigin)
    : m_code(localCode),
      m_description(localDescription),
      m_isActive(localIsActive),
      m_occurrenceCount(localOccurrenceCount),
      m_lastOccurrenceTime(localLastOccurrenceTime),
      m_severityLevel(localSeverityLevel),
      m_isConfirmed(localIsConfirmed),
      m_isPending(localIsPending),
      m_isMilOn(localIsMilOn),
      m_system(localSystem),
      m_origin(localOrigin)
{
    s_dtcCount++;
}

// Copy constructor using delegation
DTC::DTC(const DTC& other)
    : DTC(other.m_code, other.m_description, other.m_isActive, other.m_occurrenceCount,
          other.m_lastOccurrenceTime, other.m_severityLevel, other.m_isConfirmed,
          other.m_isPending, other.m_isMilOn, other.m_system, other.m_origin)
{
}

// Destructor
DTC::~DTC()
{
    s_dtcCount--;
}

// Getters
std::string DTC::getCode() const { return m_code; }
std::string DTC::getDescription() const { return m_description; }
bool DTC::isActive() const { return m_isActive; }
int DTC::getOccurrenceCount() const { return m_occurrenceCount; }
std::time_t DTC::getLastOccurrenceTime() const { return m_lastOccurrenceTime; }
SeverityLevel DTC::getSeverityLevel() const { return m_severityLevel; }
bool DTC::isConfirmed() const { return m_isConfirmed; }
bool DTC::isPending() const { return m_isPending; }
bool DTC::isMilOn() const { return m_isMilOn; }
std::string DTC::getSystem() const { return m_system; }
std::string DTC::getOrigin() const { return m_origin; }
int DTC::getDtcCount() { return s_dtcCount; }

// Setters
void DTC::setCode(const std::string& localCode) { m_code = localCode; }
void DTC::setDescription(const std::string& localDescription) { m_description = localDescription; }
void DTC::setActive(bool localIsActive) { m_isActive = localIsActive; }
void DTC::setOccurrenceCount(int localOccurrenceCount)
{
    m_occurrenceCount = (localOccurrenceCount < 0) ? 0 : localOccurrenceCount;
}
void DTC::setLastOccurrenceTime(std::time_t localLastOccurrenceTime)
{
    std::time_t now = std::time(nullptr);
    m_lastOccurrenceTime = (localLastOccurrenceTime > now) ? now : localLastOccurrenceTime;
}
void DTC::setSeverityLevel(SeverityLevel localSeverityLevel) { m_severityLevel = localSeverityLevel; }
void DTC::setConfirmed(bool localIsConfirmed) { m_isConfirmed = localIsConfirmed; }
void DTC::setPending(bool localIsPending) { m_isPending = localIsPending; }
void DTC::setMilOn(bool localIsMilOn) { m_isMilOn = localIsMilOn; }
void DTC::setSystem(const std::string& localSystem) { m_system = localSystem; }
void DTC::setOrigin(const std::string& localOrigin) { m_origin = localOrigin; }

// Set severity using int
void DTC::setSeverity(int localLevel)
{
    if (localLevel <= 0 || localLevel > m_maxSeverity)
    {
        m_severityLevel = SeverityLevel::INFO;
    }
    else
    {
        m_severityLevel = static_cast<SeverityLevel>(localLevel);
    }
}

// Set severity using string
void DTC::setSeverity(const std::string& localName)
{
    if (localName == "Crit") { m_severityLevel = SeverityLevel::CRIT; }
    else if (localName == "Warn") { m_severityLevel = SeverityLevel::WARN; }
    else { m_severityLevel = SeverityLevel::INFO; }
}

// Mark active (default argument)
void DTC::markActive(bool localState) { m_isActive = localState; }

// Activate / Deactivate
void DTC::activate() { m_isActive = true; }
void DTC::deactivate() { m_isActive = false; }

// Increment occurrence
void DTC::incrementOccurrence() { m_occurrenceCount++; }

// Toggle MIL
void DTC::toggleMil() { m_isMilOn = !m_isMilOn; }

// Mark confirmed
void DTC::markConfirmed() { m_isConfirmed = true; m_isPending = false; }

// Print info
void DTC::printDtcInfo() const
{
    std::cout << "Code: " << m_code << std::endl;
    std::cout << "Description: " << m_description << std::endl;
    std::cout << "Activation status: " << (m_isActive ? "Active" : "Inactive") << std::endl;
    std::cout << "Occurrence Count: " << m_occurrenceCount << std::endl;
    std::cout << "Last Occurrence Time: " << std::ctime(&m_lastOccurrenceTime);
    std::cout << "Severity Level: " << getSeverityString() << std::endl;
    std::cout << "Detection Confirmed: " << (m_isConfirmed ? "True" : "False") << std::endl;
    std::cout << "Pending Confirmation: " << (m_isPending ? "Yes" : "No") << std::endl;
    std::cout << "MIL On: " << (m_isMilOn ? "Yes" : "No") << std::endl;
    std::cout << "Affected Subsystem: " << m_system << std::endl;
    std::cout << "Origin: " << m_origin << std::endl;
}

// Severity string
std::string DTC::getSeverityString() const
{
    switch (m_severityLevel)
    {
    case SeverityLevel::CRIT: return "Critical";
    case SeverityLevel::WARN: return "Warning";
    case SeverityLevel::INFO: return "Normal";
    default: return "UNKNOWN";
    }
}

// Compute risk score
double DTC::computeRiskScore() const
{
    double severityScore = 0.0;
    switch (m_severityLevel)
    {
    case SeverityLevel::INFO: severityScore = 10.0; break;
    case SeverityLevel::WARN: severityScore = 40.0; break;
    case SeverityLevel::CRIT: severityScore = 80.0; break;
    default: severityScore = 10.0; break;
    }

    double occurrenceScore = std::min(static_cast<double>(m_occurrenceCount) * 5.0, 50.0);

    std::time_t now = std::time(nullptr);
    double ageScore = 0.0;
    if (m_lastOccurrenceTime != 0 && m_lastOccurrenceTime <= now)
    {
        std::time_t delta = now - m_lastOccurrenceTime;
        if (delta <= 3600) ageScore = 20.0;
        else if (delta < 30 * 24 * 3600)
        {
            double ratio = (delta - 3600.0) / ((30.0 * 24 * 3600.0) - 3600.0);
            ageScore = 20.0 * (1.0 - ratio);
        }
    }

    double totalScore = severityScore + occurrenceScore + ageScore;
    if (m_isMilOn) { totalScore *= 1.25; }

    return std::clamp(totalScore, 0.0, 100.0);
}

// Recommend action
std::string DTC::recommendAction() const
{
    double score = computeRiskScore();
    if (m_isConfirmed && score > 75.0) return "Immediate Attention: isolate system and stop is unsafe..";
    if (m_isConfirmed && score > 45.0) return "Scheduled urgent repair..";
    if (m_isMilOn && score > 20.0) return "Drive Restricted: visit service soon";
    if (score > 20.0) return "Monitor: record and re-evaluate";
    return "Informational: no immediate reaction";
}

// Merge if same code
bool DTC::mergeIfSameCode(const DTC& other)
{
    if (m_code == other.m_code && m_system == other.m_system)
    {
        long newOccurrence = static_cast<long>(m_occurrenceCount) + static_cast<long>(other.m_occurrenceCount);
        m_occurrenceCount = static_cast<int>(std::min(newOccurrence, static_cast<long>(INT32_MAX)));

        m_lastOccurrenceTime = std::max(m_lastOccurrenceTime, other.m_lastOccurrenceTime);
        m_isConfirmed |= other.m_isConfirmed;
        m_isPending |= other.m_isPending;
        m_isMilOn |= other.m_isMilOn;

        if (m_origin.empty() && !other.m_origin.empty()) m_origin = other.m_origin;
        if (m_description.empty() && !other.m_description.empty()) m_description = other.m_description;
        m_isActive |= other.m_isActive;

        return true;
    }
    return false;
}

// Print summary
void DTC::printSummary() const
{
    std::cout << "Code: " << m_code << std::endl;
    std::cout << "Description: " << m_description << std::endl;
    std::cout << "Occurrence Count: " << m_occurrenceCount << std::endl;
    std::cout << "Last Occurrence Time: " << std::ctime(&m_lastOccurrenceTime);
    std::cout << "Severity Level: " << getSeverityString() << std::endl;
    std::cout << "Affected Subsystem: " << m_system << std::endl;
    std::cout << "Origin: " << m_origin << std::endl;
}

// Friend functions
bool isSevere(const DTC& dtc) { return dtc.m_severityLevel == SeverityLevel::CRIT; }
void resetDtc(DTC& dtc)
{
    dtc.m_code.clear();
    dtc.m_description.clear();
    dtc.m_isActive = false;
    dtc.m_occurrenceCount = 0;
    dtc.m_lastOccurrenceTime = 0;
    dtc.m_severityLevel = SeverityLevel::INFO;
    dtc.m_isConfirmed = false;
    dtc.m_isPending = false;
    dtc.m_isMilOn = false;
    dtc.m_system.clear();
    dtc.m_origin.clear();
}

// Operator overloads
bool DTC::operator==(const DTC& other) const { return m_code == other.m_code && m_system == other.m_system; }
bool DTC::operator!=(const DTC& other) const { return !(*this == other); }
DTC& DTC::operator++() { ++m_occurrenceCount; return *this; }
DTC DTC::operator++(int) { DTC temp(*this); ++m_occurrenceCount; return temp; }
DTC& DTC::operator=(const DTC& other)
{
    if (this != &other)
    {
        m_code = other.m_code;
        m_description = other.m_description;
        m_isActive = other.m_isActive;
        m_occurrenceCount = other.m_occurrenceCount;
        m_lastOccurrenceTime = other.m_lastOccurrenceTime;
        m_severityLevel = other.m_severityLevel;
        m_isConfirmed = other.m_isConfirmed;
        m_isPending = other.m_isPending;
        m_isMilOn = other.m_isMilOn;
        m_system = other.m_system;
        m_origin = other.m_origin;
    }
    return *this;
}
void DTC::operator()() const
{
    std::cout << "\nCode: " << m_code << std::endl;
    std::cout << "System: " << m_system << std::endl;
    std::cout << "MIL On: " << (m_isMilOn ? "Yes" : "No") << std::endl;
}
std::string DTC::operator[](const std::string& attribute) const
{
    if (attribute == "code") return m_code;
    if (attribute == "description") return m_description;
    if (attribute == "active") return m_isActive ? "Yes" : "No";
    if (attribute == "occurrenceCount") return std::to_string(m_occurrenceCount);
    if (attribute == "lastOccurrenceTime") return std::to_string(m_lastOccurrenceTime);
    if (attribute == "severity") return getSeverityString();
    if (attribute == "confirmed") return m_isConfirmed ? "Yes" : "No";
    if (attribute == "pending") return m_isPending ? "Yes" : "No";
    if (attribute == "MILon") return m_isMilOn ? "Yes" : "No";
    if (attribute == "system") return m_system;
    if (attribute == "origin") return m_origin;
    return "Unknown";
}
bool DTC::operator!() const { return !m_isActive; }
std::ostream& operator<<(std::ostream& out, const DTC& dtc)
{
    dtc.printDtcInfo();
    return out;
}
bool DTC::operator<(const DTC& other) const { return m_severityLevel < other.m_severityLevel; }
bool DTC::operator>(const DTC& other) const { return m_severityLevel > other.m_severityLevel; }
