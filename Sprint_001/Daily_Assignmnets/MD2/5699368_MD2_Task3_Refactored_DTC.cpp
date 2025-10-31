#include "5699368_MD2_Task3_SeverityLevel.h"
#include "5699368_MD2_Task3_Refactored_DTC.h"
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm> // for std::min and std::max
#include <cstdint>   // for INT32_MAX

// Default constructor using constructor delegation
DTC::DTC() 
    : DTC("", "", false, 0, 0, SeverityLevel::INFO, false, false, false, "", "")
{
    // MISRA: Constructor delegation for clarity and to avoid code duplication
}

// Parameterized constructor using initializer list
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
    s_DTCCount++; // Increment DTC object count
}

// Copy constructor
DTC::DTC(const DTC& other)
    : DTC(other.m_code,
          other.m_description,
          other.m_active,
          other.m_occurenceCount,
          other.m_lastOccurenceTime,
          other.m_severityLevel,
          other.m_confirmed,
          other.m_pending,
          other.m_milOn,
          other.m_system,
          other.m_origin)
{
    // MISRA: Delegating copy constructor to parameterized constructor
}

// Destructor
DTC::~DTC()
{
    s_DTCCount--; // Decrement DTC object count
}

// ----------------- Getters -----------------
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

// Static getter
int DTC::getDTCCount()
{
    return s_DTCCount;
}

// ----------------- Setters -----------------
void DTC::setCode(const std::string& code_)
{
    m_code = code_;
}

void DTC::setDescription(const std::string& description_)
{
    m_description = description_;
}

void DTC::setActive(bool active_)
{
    m_active = active_;
}

void DTC::setOccurenceCount(int occurenceCount_)
{
    m_occurenceCount = (occurenceCount_ < 0) ? 0 : occurenceCount_;
}

void DTC::setLastOccurenceTime(std::time_t lastOccurenceTime_)
{
    const std::time_t now = std::time(nullptr);
    m_lastOccurenceTime = (lastOccurenceTime_ > now) ? now : lastOccurenceTime_;
}

void DTC::setSeverityLevel(SeverityLevel severityLevel_)
{
    m_severityLevel = severityLevel_;
}

void DTC::setConfirmed(bool confirmed_)
{
    m_confirmed = confirmed_;
}

void DTC::setPending(bool pending_)
{
    m_pending = pending_;
}

void DTC::setMilOn(bool milOn_)
{
    m_milOn = milOn_;
}

void DTC::setSystem(const std::string& system_)
{
    m_system = system_;
}

void DTC::setOrigin(const std::string& origin_)
{
    m_origin = origin_;
}

// Set severity using int values
void DTC::setSeverity(int level_)
{
    if ((level_ == 1) || (level_ == 2))
    {
        m_severityLevel = static_cast<SeverityLevel>(level_);
    }
    else
    {
        m_severityLevel = SeverityLevel::INFO;
    }
}

// Set severity using string value
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
void DTC::markActive(bool state_)
{
    m_active = state_;
}

// ----------------- Member functions -----------------
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
    m_occurenceCount++;
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

// Severity as string
std::string DTC::getSeverityString() const
{
    switch (m_severityLevel)
    {
    case SeverityLevel::CRIT:
        return "Critical";
    case SeverityLevel::INFO:
        return "Normal";
    case SeverityLevel::WARN:
        return "Warning";
    default:
        return "UNKNOWN";
    }
}

// Compute risk score
double DTC::computeRiskScore() const
{
    double totalScore_ = 0.0;
    double severityComponent_ = 10.0;

    if (m_severityLevel == SeverityLevel::WARN)
    {
        severityComponent_ = 40.0;
    }
    else if (m_severityLevel == SeverityLevel::CRIT)
    {
        severityComponent_ = 80.0;
    }

    double occurenceComponent_ = (m_occurenceCount < 0) ? 0.0 : std::min(m_occurenceCount * 5.0, 50.0);

    const std::time_t now = std::time(nullptr);
    double ageComponent_ = 0.0;
    if ((m_lastOccurenceTime != 0) && (m_lastOccurenceTime <= now))
    {
        if (now - m_lastOccurenceTime <= 3600)
        {
            ageComponent_ = 20.0;
        }
        else if (now - m_lastOccurenceTime < 30 * 24 * 3600)
        {
            double ratio = (static_cast<double>(now - m_lastOccurenceTime) - 3600.0) / ((30.0 * 24 * 3600.0) - 3600.0);
            ageComponent_ = 20.0 * (1.0 - ratio);
        }
    }

    double MIL_multiplier = severityComponent_ + occurenceComponent_ + ageComponent_;
    totalScore_ = (m_milOn) ? MIL_multiplier * 1.25 : MIL_multiplier;

    return std::clamp(totalScore_, 0.0, 100.0); // MISRA: Clamp instead of manual ternary
}

// Recommend action
std::string DTC::recommendAction() const
{
    const double score = computeRiskScore();
    if (getConfirmed() && score > 75.0)
    {
        return "Immediate Attention: isolate system and stop is unsafe..";
    }
    if (getConfirmed() && score > 45.0)
    {
        return "Scheduled urgent repair..";
    }
    if (getMilOn() && score > 20.0)
    {
        return "Drive Restricted: visit service soon";
    }
    if (score > 20.0)
    {
        return "Monitor: record and re-evaluate";
    }
    return "Informational: no immediate reaction";
}

// Merge DTC if same code
bool DTC::mergeIfSameCode(const DTC& other)
{
    if ((getCode() == other.getCode()) && (getSystem() == other.getSystem()))
    {
        const long newOccurenceCount = static_cast<long>(getOccurenceCount()) + static_cast<long>(other.getOccurenceCount());
        setOccurenceCount(static_cast<int>(std::min(newOccurenceCount, static_cast<long>(INT32_MAX))));
        setLastOccurenceTime(std::max(getLastOccurenceTime(), other.getLastOccurenceTime()));
        setConfirmed(getConfirmed() || other.getConfirmed());
        setPending(getPending() || other.getPending());
        setMilOn(getMilOn() || other.getMilOn());
        if ((getOrigin().length() == 0) && (other.getOrigin().length() != 0))
        {
            setOrigin(other.getOrigin());
        }
        if ((getDescription().length() == 0) && (other.getDescription().length() != 0))
        {
            setDescription(other.getDescription());
        }
        setActive(getActive() || other.getActive());
        return true;
    }
    return false;
}
