#include "5699368_MD3_Task4_SeverityLevel.h"
#include "5699368_MD3_Task4_Refactored_DTC.h"
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>  // for std::min, std::max

int DTC::s_dtcCount = 0; // Definition for static member

// Default constructor using delegation
DTC::DTC() 
    : DTC("", "", false, 0, 0, SeverityLevel::INFO, false, false, false, "", "") {}

// Parameterized constructor using initializer list
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
    ++s_dtcCount;
}

// Copy constructor
DTC::DTC(const DTC& other)
    : DTC(other.m_code, other.m_description, other.m_isActive, other.m_occurrenceCount,
           other.m_lastOccurrenceTime, other.m_severityLevel, other.m_isConfirmed,
           other.m_isPending, other.m_isMilOn, other.m_system, other.m_origin) {}

// Destructor
DTC::~DTC()
{
    --s_dtcCount;
}

// ========================== Getters ==========================
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

// ========================== Setters ==========================
void DTC::setCode(const std::string& localCode) { m_code = localCode; }
void DTC::setDescription(const std::string& localDescription) { m_description = localDescription; }
void DTC::setActive(const bool localIsActive) { m_isActive = localIsActive; }
void DTC::setOccurrenceCount(const int localOccurrenceCount)
{
    m_occurrenceCount = (localOccurrenceCount < 0) ? 0 : localOccurrenceCount;
}
void DTC::setLastOccurrenceTime(const std::time_t localLastOccurrenceTime)
{
    const std::time_t now = std::time(nullptr);
    m_lastOccurrenceTime = (localLastOccurrenceTime > now) ? now : localLastOccurrenceTime;
}
void DTC::setSeverityLevel(const SeverityLevel localSeverityLevel)
{
    m_severityLevel = localSeverityLevel;
}
void DTC::setConfirmed(const bool localIsConfirmed) { m_isConfirmed = localIsConfirmed; }
void DTC::setPending(const bool localIsPending) { m_isPending = localIsPending; }
void DTC::setMilOn(const bool localIsMilOn) { m_isMilOn = localIsMilOn; }
void DTC::setSystem(const std::string& localSystem) { m_system = localSystem; }
void DTC::setOrigin(const std::string& localOrigin) { m_origin = localOrigin; }

// Overloaded severity setters
void DTC::setSeverity(int localLevel)
{
    if ((localLevel <= 0) || (localLevel > m_maxSeverity))
    {
        m_severityLevel = static_cast<SeverityLevel>(0);
    }
    else
    {
        m_severityLevel = static_cast<SeverityLevel>(localLevel);
    }
}

void DTC::setSeverity(const std::string& localName)
{
    if (localName == "Crit") { m_severityLevel = SeverityLevel::CRIT; }
    else if (localName == "Warn") { m_severityLevel = SeverityLevel::WARN; }
    else { m_severityLevel = SeverityLevel::INFO; }
}

void DTC::markActive(bool localState)
{
    m_isActive = localState;
}

// ========================== Member Functions ==========================
void DTC::activate() { m_isActive = true; }
void DTC::deactivate() { m_isActive = false; }
void DTC::incrementOccurrence() { ++m_occurrenceCount; }

void DTC::printDtcInfo() const
{
    std::cout << "Code: " << m_code << '\n'
              << "Description: " << m_description << '\n'
              << "Activation Status: " << (m_isActive ? "Active" : "Inactive") << '\n'
              << "Occurrence Count: " << m_occurrenceCount << '\n'
              << "Last Occurrence Time: " << std::ctime(&m_lastOccurrenceTime)
              << "Severity Level: " << getSeverityString() << '\n'
              << "Confirmed: " << (m_isConfirmed ? "True" : "False") << '\n'
              << "Pending: " << (m_isPending ? "Yes" : "No") << '\n'
              << "MIL On: " << (m_isMilOn ? "Yes" : "No") << '\n'
              << "System: " << m_system << '\n'
              << "Origin: " << m_origin << '\n';
}

void DTC::toggleMil() { m_isMilOn = !m_isMilOn; }
void DTC::markConfirmed() { m_isConfirmed = true; m_isPending = false; }

// ========================== Utility Functions ==========================
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

double DTC::computeRiskScore() const
{
    double severityComponent = 0.0;
    if (m_severityLevel == SeverityLevel::INFO) { severityComponent = 10.0; }
    else if (m_severityLevel == SeverityLevel::WARN) { severityComponent = 40.0; }
    else if (m_severityLevel == SeverityLevel::CRIT) { severityComponent = 80.0; }

    double occurrenceComponent = std::min(static_cast<double>(m_occurrenceCount) * 5.0, 50.0);
    const std::time_t now = std::time(nullptr);
    double ageComponent = 0.0;

    if (m_lastOccurrenceTime == 0U || m_lastOccurrenceTime > now) { ageComponent = 0.0; }
    else if (now - m_lastOccurrenceTime <= 3600) { ageComponent = 20.0; }
    else if (now - m_lastOccurrenceTime < 30 * 24 * 3600)
    {
        const double ratio = static_cast<double>((now - m_lastOccurrenceTime) - 3600)
                             / static_cast<double>((30 * 24 * 3600) - 3600);
        ageComponent = 20.0 * (1.0 - ratio);
    }

    double totalScore = severityComponent + occurrenceComponent + ageComponent;
    if (m_isMilOn) { totalScore *= 1.25; }

    if (totalScore < 0.0) { totalScore = 0.0; }
    else if (totalScore > 100.0) { totalScore = 100.0; }

    return totalScore;
}

std::string DTC::recommendAction() const
{
    const double score = computeRiskScore();
    if (m_isConfirmed && score > 75.0) { return "Immediate Attention: isolate system and stop if unsafe."; }
    else if (m_isConfirmed && score > 45.0) { return "Scheduled urgent repair."; }
    else if (m_isMilOn && score > 20.0) { return "Drive Restricted: visit service soon."; }
    else if (score > 20.0) { return "Monitor: record and re-evaluate."; }
    return "Informational: no immediate reaction.";
}

bool DTC::mergeIfSameCode(const DTC& other)
{
    if ((m_code == other.m_code) && (m_system == other.m_system))
    {
        const long newCount = static_cast<long>(m_occurrenceCount) + static_cast<long>(other.m_occurrenceCount);
        setOccurrenceCount(std::min(newCount, static_cast<long>(INT32_MAX)));
        setLastOccurrenceTime(std::max(m_lastOccurrenceTime, other.m_lastOccurrenceTime));
        setConfirmed(m_isConfirmed || other.m_isConfirmed);
        setPending(m_isPending || other.m_isPending);
        setMilOn(m_isMilOn || other.m_isMilOn);

        if (m_origin.empty() && !other.m_origin.empty()) { m_origin = other.m_origin; }
        if (m_description.empty() && !other.m_description.empty()) { m_description = other.m_description; }
        setActive(m_isActive || other.m_isActive);
        return true;
    }
    return false;
}

void DTC::printSummary() const
{
    std::cout << "Code: " << m_code << '\n'
              << "Description: " << m_description << '\n'
              << "Occurrence Count: " << m_occurrenceCount << '\n'
              << "Last Occurrence Time: " << std::ctime(&m_lastOccurrenceTime)
              << "Severity Level: " << getSeverityString() << '\n'
              << "System: " << m_system << '\n'
              << "Origin: " << m_origin << '\n';
}

// ========================== Friend Functions ==========================
bool isSevere(const DTC& localDtc)
{
    return (localDtc.m_severityLevel == SeverityLevel::CRIT);
}

void resetDtc(DTC& localDtc)
{
    localDtc.m_code.clear();
    localDtc.m_description.clear();
    localDtc.m_isActive = false;
    localDtc.m_occurrenceCount = 0;
    localDtc.m_lastOccurrenceTime = 0;
    localDtc.m_severityLevel = SeverityLevel::INFO;
    localDtc.m_isConfirmed = false;
    localDtc.m_isPending = false;
    localDtc.m_isMilOn = false;
    localDtc.m_system.clear();
    localDtc.m_origin.clear();
}

// ========================== Operator Overloads ==========================
bool DTC::operator==(const DTC& otherDtc) const
{
    return ((m_code == otherDtc.m_code) && (m_system == otherDtc.m_system));
}

bool DTC::operator!=(const DTC& otherDtc) const
{
    return !(*this == otherDtc);
}

DTC& DTC::operator++() // Prefix
{
    ++m_occurrenceCount;
    return *this;
}

DTC DTC::operator++(int) // Postfix
{
    DTC temp = *this;
    ++m_occurrenceCount;
    return temp;
}

DTC& DTC::operator=(const DTC& otherDtc)
{
    if (this != &otherDtc)
    {
        m_code = otherDtc.m_code;
        m_description = otherDtc.m_description;
        m_isActive = otherDtc.m_isActive;
        m_occurrenceCount = otherDtc.m_occurrenceCount;
        m_lastOccurrenceTime = otherDtc.m_lastOccurrenceTime;
        m_severityLevel = otherDtc.m_severityLevel;
        m_isConfirmed = otherDtc.m_isConfirmed;
        m_isPending = otherDtc.m_isPending;
        m_isMilOn = otherDtc.m_isMilOn;
        m_system = otherDtc.m_system;
        m_origin = otherDtc.m_origin;
    }
    return *this;
}

void DTC::operator()() const
{
    std::cout << "\nCode: " << m_code
              << "\nSystem: " << m_system
              << "\nMIL On: " << (m_isMilOn ? "Yes" : "No") << '\n';
}

std::string DTC::operator[](const std::string& attribute) const
{
    if (attribute == "code") { return m_code; }
    else if (attribute == "description") { return m_description; }
    else if (attribute == "active") { return (m_isActive ? "Yes" : "No"); }
    else if (attribute == "occurrenceCount") { return std::to_string(m_occurrenceCount); }
    else if (attribute == "lastOccurrenceTime") { return std::to_string(m_lastOccurrenceTime); }
    else if (attribute == "severity") { return getSeverityString(); }
    else if (attribute == "confirmed") { return (m_isConfirmed ? "Yes" : "No"); }
    else if (attribute == "pending") { return (m_isPending ? "Yes" : "No"); }
    else if (attribute == "milOn") { return (m_isMilOn ? "Yes" : "No"); }
    else if (attribute == "system") { return m_system; }
    else if (attribute == "origin") { return m_origin; }
    return "Unknown";
}

bool DTC::operator!() const
{
    return (!m_isActive);
}

std::ostream& operator<<(std::ostream& out, const DTC& otherDtc)
{
    out << "Code: " << otherDtc.m_code << '\n'
        << "Description: " << otherDtc.m_description << '\n'
        << "Activation: " << (otherDtc.m_isActive ? "Active" : "Inactive") << '\n'
        << "Occurrence Count: " << otherDtc.m_occurrenceCount << '\n'
        << "Last Occurrence: " << std::ctime(&otherDtc.m_lastOccurrenceTime)
        << "Severity: " << otherDtc.getSeverityString() << '\n'
        << "Confirmed: " << (otherDtc.m_isConfirmed ? "True" : "False") << '\n'
        << "Pending: " << (otherDtc.m_isPending ? "Yes" : "No") << '\n'
        << "MIL On: " << (otherDtc.m_isMilOn ? "Yes" : "No") << '\n'
        << "System: " << otherDtc.m_system << '\n'
        << "Origin: " << otherDtc.m_origin << '\n';
    return out;
}

bool DTC::operator<(const DTC& otherDtc) const
{
    return (m_severityLevel < otherDtc.m_severityLevel);
}

bool DTC::operator>(const DTC& otherDtc) const
{
    return (m_severityLevel > otherDtc.m_severityLevel);
}
