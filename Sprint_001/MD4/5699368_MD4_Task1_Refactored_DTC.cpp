#include "5699368_MD4_Task1_SeverityLevel.h"
#include "5699368_MD4_Task1_DTC.h"
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>  // ✅ For std::min and std::max (MISRA compliance)

// Initialize static member
int DTC::s_DTCCount = 0;

// Default constructor → delegates to parameterized constructor
DTC::DTC() :
    DTC("", "", false, 0, 0, SeverityLevel::INFO, false, false, false, "", "")
{
}

// Parameterized constructor with initializer list
DTC::DTC(const std::string& code_,
         const std::string& description_,
         bool active_,
         int occurenceCount_,
         std::time_t lastOccurenceTime_,
         SeverityLevel severityLevel_,
         bool confirmed_,
         bool pending_,
         bool milOn_,
         const std::string& system_,
         const std::string& origin_)
    : m_code(code_),
      m_description(description_),
      m_active(active_),
      m_occurenceCount(occurenceCount_),
      m_lastOccurenceTime(lastOccurenceTime_),
      m_severityLevel(severityLevel_),
      m_confirmed(confirmed_),
      m_pending(pending_),
      m_milOn(milOn_),
      m_system(system_),
      m_origin(origin_)
{
    ++s_DTCCount;
}

// Copy constructor
DTC::DTC(const DTC& otherDtc) :
    DTC(otherDtc.m_code,
        otherDtc.m_description,
        otherDtc.m_active,
        otherDtc.m_occurenceCount,
        otherDtc.m_lastOccurenceTime,
        otherDtc.m_severityLevel,
        otherDtc.m_confirmed,
        otherDtc.m_pending,
        otherDtc.m_milOn,
        otherDtc.m_system,
        otherDtc.m_origin)
{
}

// Destructor
DTC::~DTC()
{
    --s_DTCCount;
}

// ------------------------- Getters -------------------------

std::string DTC::getCode() const { return m_code; }
std::string DTC::getDescription() const { return m_description; }
bool DTC::getActive() const { return m_active; }
int DTC::getOccurenceCount() const { return m_occurenceCount; }
std::time_t DTC::getLastOccurenceTime() const { return m_lastOccurenceTime; }
SeverityLevel DTC::getSeverityLevel() const { return m_severityLevel; }
bool DTC::getConfirmed() const { return m_confirmed; }
bool DTC::getPending() const { return m_pending; }
bool DTC::getMilOn() const { return m_milOn; }
std::string DTC::getSystem() const { return m_system; }
std::string DTC::getOrigin() const { return m_origin; }

int DTC::getDTCCount()
{
    return s_DTCCount;
}

// ------------------------- Setters -------------------------

void DTC::setCode(const std::string& code_) { m_code = code_; }
void DTC::setDescription(const std::string& description_) { m_description = description_; }
void DTC::setActive(const bool active_) { m_active = active_; }

void DTC::setOccurenceCount(const int occurenceCount_)
{
    m_occurenceCount = (occurenceCount_ < 0) ? 0 : occurenceCount_;
}

void DTC::setLastOccurenceTime(const std::time_t lastOccurenceTime_)
{
    const std::time_t now_ = std::time(nullptr);
    m_lastOccurenceTime = (lastOccurenceTime_ > now_) ? now_ : lastOccurenceTime_;
}

void DTC::setSeverityLevel(const SeverityLevel severityLevel_) { m_severityLevel = severityLevel_; }
void DTC::setConfirmed(const bool confirmed_) { m_confirmed = confirmed_; }
void DTC::setPending(const bool pending_) { m_pending = pending_; }
void DTC::setMilOn(const bool milOn_) { m_milOn = milOn_; }
void DTC::setSystem(const std::string& system_) { m_system = system_; }
void DTC::setOrigin(const std::string& origin_) { m_origin = origin_; }

// Set severity using int (validated)
void DTC::setSeverity(int level_)
{
    if ((level_ <= 0) || (level_ > m_MAX_SEVRITY))
    {
        m_severityLevel = SeverityLevel::INFO;
    }
    else
    {
        m_severityLevel = static_cast<SeverityLevel>(level_);
    }
}

// Set severity using string
void DTC::setSeverity(const std::string& name_)
{
    if (name_ == "Crit")
    {
        m_severityLevel = SeverityLevel::CRIT;
    }
    else if (name_ == "Warn")
    {
        m_severityLevel = SeverityLevel::WARN;
    }
    else
    {
        m_severityLevel = SeverityLevel::INFO;
    }
}

// Mark active/inactive
void DTC::markActive(bool state_) { m_active = state_; }

// ------------------------- Member Functions -------------------------

void DTC::activate() { m_active = true; }
void DTC::deActivate() { m_active = false; }
void DTC::incrementOccurence() { ++m_occurenceCount; }

void DTC::printDTCInfo() const
{
    std::cout << "Code: " << m_code << std::endl;
    std::cout << "Description: " << m_description << std::endl;
    std::cout << "Activation Status: " << (m_active ? "Active" : "Inactive") << std::endl;
    std::cout << "Occurence Count: " << m_occurenceCount << std::endl;
    std::cout << "Last Occurence Time: " << std::ctime(&m_lastOccurenceTime);
    std::cout << "Severity Level: " << getSeverityString() << std::endl;
    std::cout << "Detection Confirmed: " << (m_confirmed ? "True" : "False") << std::endl;
    std::cout << "Pending Confirmation: " << (m_pending ? "Yes" : "No") << std::endl;
    std::cout << "MIL Status: " << (m_milOn ? "On" : "Off") << std::endl;
    std::cout << "Subsystem: " << m_system << std::endl;
    std::cout << "Origin: " << m_origin << std::endl;
}

void DTC::toggleMIL() { m_milOn = !m_milOn; }

void DTC::markConfirmed()
{
    m_confirmed = true;
    m_pending = false;
}

std::string DTC::getSeverityString() const
{
    switch (m_severityLevel)
    {
        case SeverityLevel::CRIT: return "Critical";
        case SeverityLevel::WARN: return "Warning";
        case SeverityLevel::INFO: return "Informational";
        default: return "Unknown";
    }
}

// ------------------------- Logic Functions -------------------------

double DTC::computeRiskScore() const
{
    double totalScore_ = 0.0;
    double severityScore_ = 0.0;
    double occurenceScore_ = 0.0;
    double ageScore_ = 0.0;

    // Severity contribution
    if (m_severityLevel == SeverityLevel::CRIT) { severityScore_ = 80.0; }
    else if (m_severityLevel == SeverityLevel::WARN) { severityScore_ = 40.0; }
    else { severityScore_ = 10.0; }

    // Occurrence contribution
    occurenceScore_ = (m_occurenceCount * 5.0 > 50.0) ? 50.0 : (m_occurenceCount * 5.0);

    // Time contribution
    const std::time_t now_ = std::time(nullptr);
    if (m_lastOccurenceTime == 0U)
    {
        ageScore_ = 0.0;
    }
    else if (now_ - m_lastOccurenceTime <= 3600)
    {
        ageScore_ = 20.0;
    }
    else if (now_ - m_lastOccurenceTime < 30 * 24 * 3600)
    {
        const double ratio_ = static_cast<double>(now_ - m_lastOccurenceTime - 3600) / (30.0 * 24.0 * 3600.0 - 3600.0);
        ageScore_ = 20.0 * (1.0 - ratio_);
    }

    totalScore_ = severityScore_ + occurenceScore_ + ageScore_;
    if (m_milOn)
    {
        totalScore_ *= 1.25;
    }

    // Clamp to 0–100
    if (totalScore_ < 0.0) { totalScore_ = 0.0; }
    else if (totalScore_ > 100.0) { totalScore_ = 100.0; }

    return totalScore_;
}

std::string DTC::recommendAction() const
{
    const double score_ = computeRiskScore();

    if (m_confirmed && score_ > 75.0) { return "Immediate Attention Required"; }
    else if (m_confirmed && score_ > 45.0) { return "Schedule Urgent Repair"; }
    else if (m_milOn && score_ > 20.0) { return "Drive Restricted – Visit Service Soon"; }
    else if (score_ > 20.0) { return "Monitor and Re-evaluate"; }
    return "No Immediate Action Needed";
}

// ------------------------- Operator Overloads -------------------------

bool DTC::operator==(const DTC& otherDtc) const
{
    return (m_code == otherDtc.m_code) && (m_system == otherDtc.m_system);
}

bool DTC::operator!=(const DTC& otherDtc) const
{
    return !(*this == otherDtc);
}

DTC& DTC::operator++()
{
    ++m_occurenceCount;
    return *this;
}

DTC DTC::operator++(int)
{
    DTC temp = *this;
    ++m_occurenceCount;
    return temp;
}

void DTC::operator=(const DTC& otherDtc)
{
    if (this != &otherDtc)
    {
        m_code = otherDtc.m_code;
        m_description = otherDtc.m_description;
        m_active = otherDtc.m_active;
        m_occurenceCount = otherDtc.m_occurenceCount;
        m_lastOccurenceTime = otherDtc.m_lastOccurenceTime;
        m_severityLevel = otherDtc.m_severityLevel;
        m_confirmed = otherDtc.m_confirmed;
        m_pending = otherDtc.m_pending;
        m_milOn = otherDtc.m_milOn;
        m_system = otherDtc.m_system;
        m_origin = otherDtc.m_origin;
    }
}

void DTC::operator()() const
{
    std::cout << "Code: " << m_code << "\nSystem: " << m_system
              << "\nMIL On: " << (m_milOn ? "Yes" : "No") << std::endl;
}

std::string DTC::operator[](std::string attribute_) const
{
    if (attribute_ == "code") { return m_code; }
    if (attribute_ == "description") { return m_description; }
    if (attribute_ == "active") { return (m_active ? "Yes" : "No"); }
    if (attribute_ == "occurenceCount") { return std::to_string(m_occurenceCount); }
    if (attribute_ == "severity") { return getSeverityString(); }
    if (attribute_ == "system") { return m_system; }
    if (attribute_ == "origin") { return m_origin; }
    return "Unknown";
}

bool DTC::operator!() const { return !m_active; }

bool DTC::operator<(const DTC& otherDtc) const
{
    return m_severityLevel < otherDtc.m_severityLevel;
}

bool DTC::operator>(const DTC& otherDtc) const
{
    return m_severityLevel > otherDtc.m_severityLevel;
}

std::ostream& operator<<(std::ostream& out, const DTC& dtcObj)
{
    out << "Code: " << dtcObj.m_code << "\n"
        << "Description: " << dtcObj.m_description << "\n"
        << "Severity: " << dtcObj.getSeverityString() << "\n"
        << "Subsystem: " << dtcObj.m_system << "\n"
        << "Origin: " << dtcObj.m_origin << std::endl;
    return out;
}

// ------------------------- Friend Functions -------------------------

bool isSevere(const DTC& dtc)
{
    return (dtc.m_severityLevel == SeverityLevel::CRIT);
}

void resetDTC(DTC& dtc)
{
    dtc.m_code = "";
    dtc.m_description = "";
    dtc.m_active = false;
    dtc.m_occurenceCount = 0;
    dtc.m_lastOccurenceTime = 0U;
    dtc.m_severityLevel = SeverityLevel::INFO;
    dtc.m_confirmed = false;
    dtc.m_pending = false;
    dtc.m_milOn = false;
    dtc.m_system = "";
    dtc.m_origin = "";
}
