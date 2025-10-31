#include "5699368_MD3_Task1_SeverityLevel.h"
#include "5699368_MD3_Task1_Refactored_DTC.h"
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm> // for std::min and std::max

// Initialize static member
int DTC::s_dtcCount = 0;

// --------------------------
// Constructors
// --------------------------

// Default constructor
DTC::DTC()
    : m_code(""),
      m_description(""),
      m_active(false),
      m_occurenceCount(0),
      m_lastOccurenceTime(0),
      m_severityLevel(SeverityLevel::INFO),
      m_confirmed(false),
      m_pending(false),
      m_milOn(false),
      m_system(""),
      m_origin("")
{
    s_dtcCount++; // increment DTC count
}

// Parameterized constructor
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
    s_dtcCount++; // increment DTC count
}

// Copy constructor
DTC::DTC(const DTC& other)
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
    s_dtcCount++; // count copy as a new DTC
}

// Destructor
DTC::~DTC()
{
    if (s_dtcCount > 0)
    {
        s_dtcCount--; // decrement DTC count
    }
}

// --------------------------
// Getters
// --------------------------

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
int DTC::getDTCCount() { return s_dtcCount; } // static getter

// --------------------------
// Setters
// --------------------------

void DTC::setCode(const std::string& code_) { m_code = code_; }
void DTC::setDescription(const std::string& description_) { m_description = description_; }
void DTC::setActive(bool active_) { m_active = active_; }
void DTC::setOccurenceCount(int occurenceCount_)
{
    m_occurenceCount = (occurenceCount_ < 0) ? 0 : occurenceCount_;
}
void DTC::setLastOccurenceTime(std::time_t lastOccurenceTime_)
{
    std::time_t now = std::time(nullptr);
    m_lastOccurenceTime = (lastOccurenceTime_ > now) ? now : lastOccurenceTime_;
}
void DTC::setSeverityLevel(SeverityLevel severityLevel_) { m_severityLevel = severityLevel_; }
void DTC::setConfirmed(bool confirmed_) { m_confirmed = confirmed_; }
void DTC::setPending(bool pending_) { m_pending = pending_; }
void DTC::setMilOn(bool milOn_) { m_milOn = milOn_; }
void DTC::setSystem(const std::string& system_) { m_system = system_; }
void DTC::setOrigin(const std::string& origin_) { m_origin = origin_; }

// Set severity using integer
void DTC::setSeverity(int level_)
{
    if ((level_ <= 0) || (level_ > m_maxSeverity))
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

// Default argument setter
void DTC::markActive(bool state_) { m_active = state_; }

// --------------------------
// Member Functions
// --------------------------

void DTC::activate() { m_active = true; }
void DTC::deActivate() { m_active = false; }
void DTC::incrementOccurence() { m_occurenceCount++; }

// --------------------------
// Print Functions
// --------------------------

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

void DTC::printSummary() const
{
    std::cout << "Code: " << m_code << std::endl;
    std::cout << "Description: " << m_description << std::endl;
    std::cout << "Occurance Count: " << m_occurenceCount << std::endl;
    std::cout << "Last Occurance Time: " << std::ctime(&m_lastOccurenceTime);
    std::cout << "Severity Level: " << getSeverityString() << std::endl;
    std::cout << "Affected Subsystem: " << m_system << std::endl;
    std::cout << "DTC Origin: " << m_origin << std::endl;
}

// --------------------------
// Other Functions
// --------------------------

void DTC::toggleMIL() { m_milOn = !m_milOn; }
void DTC::markConfirmed() { m_confirmed = true; m_pending = false; }

std::string DTC::getSeverityString() const
{
    switch (m_severityLevel)
    {
    case SeverityLevel::CRIT:
        return "Critical";
    case SeverityLevel::WARN:
        return "Warning";
    case SeverityLevel::INFO:
        return "Normal";
    default:
        return "UNKNOWN";
    }
}

double DTC::computeRiskScore() const
{
    double severityScore = 0.0;
    if (m_severityLevel == SeverityLevel::INFO)
        severityScore = 10.0;
    else if (m_severityLevel == SeverityLevel::WARN)
        severityScore = 40.0;
    else if (m_severityLevel == SeverityLevel::CRIT)
        severityScore = 80.0;

    double occurenceScore = std::min(static_cast<double>(m_occurenceCount) * 5.0, 50.0);

    std::time_t now = std::time(nullptr);
    double ageScore = 0.0;
    if ((m_lastOccurenceTime != 0) && (m_lastOccurenceTime <= now))
    {
        if (now - m_lastOccurenceTime <= 3600)
            ageScore = 20.0;
        else if (now - m_lastOccurenceTime < 30 * 24 * 3600)
        {
            double ratio = ((now - m_lastOccurenceTime) - 3600.0) / ((30 * 24 * 3600.0) - 3600.0);
            ageScore = 20.0 * (1.0 - ratio);
        }
    }

    double totalScore = severityScore + occurenceScore + ageScore;
    if (m_milOn)
        totalScore *= 1.25;

    return std::clamp(totalScore, 0.0, 100.0);
}

std::string DTC::recommendAction() const
{
    double score = computeRiskScore();
    if (getConfirmed() && score > 75.0)
        return "Immediate Attention: isolate system and stop is unsafe..";
    if (getConfirmed() && score > 45.0)
        return "Scheduled urgent repair..";
    if (getMilOn() && score > 20.0)
        return "Drive Restricted: visit service soon";
    if (score > 20.0)
        return "Monitor: record and re-evaluate";
    return "Informational: no immediate reaction";
}

// Merge DTC if code and system match
bool DTC::mergeIfSameCode(const DTC& other)
{
    if ((getCode() == other.getCode()) && (getSystem() == other.getSystem()))
    {
        long newCount = static_cast<long>(getOccurenceCount()) + static_cast<long>(other.getOccurenceCount());
        setOccurenceCount(std::min(newCount, static_cast<long>(INT32_MAX)));
        setLastOccurenceTime(std::max(getLastOccurenceTime(), other.getLastOccurenceTime()));
        setConfirmed(getConfirmed() || other.getConfirmed());
        setPending(getPending() || other.getPending());
        setMilOn(getMilOn() || other.getMilOn());
        if (getOrigin().empty() && !other.getOrigin().empty())
            setOrigin(other.getOrigin());
        if (getDescription().empty() && !other.getDescription().empty())
            setDescription(other.getDescription());
        setActive(getActive() || other.getActive());
        return true;
    }
    return false;
}

// --------------------------
// Friend Functions
// --------------------------

bool isSevere(const DTC& dtc) { return dtc.m_severityLevel == SeverityLevel::CRIT; }

void resetDTC(DTC& dtc)
{
    dtc.m_code = "";
    dtc.m_description = "";
    dtc.m_active = false;
    dtc.m_occurenceCount = 0;
    dtc.m_lastOccurenceTime = 0;
    dtc.m_severityLevel = SeverityLevel::INFO;
    dtc.m_confirmed = false;
    dtc.m_pending = false;
    dtc.m_milOn = false;
    dtc.m_system = "";
    dtc.m_origin = "";
}
