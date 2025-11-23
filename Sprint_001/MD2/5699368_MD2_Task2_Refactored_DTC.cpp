#include "5699368_MD2_Task2_SeverityLevel.h"
#include "5699368_MD2_Task2_Refactored_DTC.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdint>

// Default constructor using constructor delegation
DTC::DTC()
    : DTC("", "", false, 0, 0, SeverityLevel::INFO, false, false, false, "", "") {}

// Parameterized constructor using initializer list
DTC::DTC(const std::string& code_, const std::string& description_, bool active_, int occurenceCount_,
         std::time_t lastOccurenceTime_, SeverityLevel severityLevel_, bool confirmed_, bool pending_,
         bool milOn_, const std::string& system_, const std::string& origin_)
    : m_code(code_),
      m_description(description_),
      m_active(active_),
      m_occurenceCount((occurenceCount_ < 0) ? 0 : occurenceCount_),
      m_lastOccurenceTime((lastOccurenceTime_ > std::time(nullptr)) ? std::time(nullptr) : lastOccurenceTime_),
      m_severityLevel(severityLevel_),
      m_confirmed(confirmed_),
      m_pending(pending_),
      m_milOn(milOn_),
      m_system(system_),
      m_origin(origin_) {}

// Copy constructor
DTC::DTC(const DTC& other)
    : DTC(other.m_code, other.m_description, other.m_active, other.m_occurenceCount, other.m_lastOccurenceTime,
          other.m_severityLevel, other.m_confirmed, other.m_pending, other.m_milOn, other.m_system, other.m_origin) {}

// Getters
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

// Setters
void DTC::setCode(const std::string& code_) { m_code = code_; }
void DTC::setDescription(const std::string& description_) { m_description = description_; }
void DTC::setActive(const bool active_) { m_active = active_; }
void DTC::setOccurenceCount(const int occurenceCount_) {
    m_occurenceCount = (occurenceCount_ < 0) ? 0 : occurenceCount_;
}
void DTC::setLastOccurenceTime(const std::time_t lastOccurenceTime_) {
    const std::time_t now = std::time(nullptr);
    m_lastOccurenceTime = (lastOccurenceTime_ > now) ? now : lastOccurenceTime_;
}
void DTC::setSeverityLevel(const SeverityLevel severityLevel_) { m_severityLevel = severityLevel_; }
void DTC::setConfirmed(const bool confirmed_) { m_confirmed = confirmed_; }
void DTC::setPending(const bool pending_) { m_pending = pending_; }
void DTC::setMilOn(const bool milOn_) { m_milOn = milOn_; }
void DTC::setSystem(const std::string& system_) { m_system = system_; }
void DTC::setOrigin(const std::string& origin_) { m_origin = origin_; }

// Member functions
void DTC::activate() { m_active = true; }
void DTC::deActivate() { m_active = false; }
void DTC::incrementOccurence() { m_occurenceCount++; }

void DTC::printDTCInfo() {
    std::cout << "Code: " << m_code << '\n';
    std::cout << "Description: " << m_description << '\n';
    std::cout << "Activation status: " << (m_active ? "Active" : "Inactive") << '\n';
    std::cout << "Occurence Count: " << m_occurenceCount << '\n';
    std::cout << "Last Occurence Time: " << std::ctime(&m_lastOccurenceTime);
    std::cout << "Severity Level: " << getSeverityString() << '\n';
    std::cout << "Detection Confirmed: " << (m_confirmed ? "True" : "False") << '\n';
    std::cout << "Pending confirmation: " << (m_pending ? "Yes" : "False") << '\n';
    std::cout << "MIL On: " << (m_milOn ? "Yes" : "No") << '\n';
    std::cout << "Affected Subsystem: " << m_system << '\n';
    std::cout << "DTC Origin: " << m_origin << '\n';
}

void DTC::toggleMIL() { m_milOn = !m_milOn; }
void DTC::markConfirmed() {
    m_confirmed = true;
    m_pending = false;
}

// Additional function to get string value of severity
std::string DTC::getSeverityString() {
    switch (m_severityLevel) {
        case SeverityLevel::CRIT: return "Critical";
        case SeverityLevel::INFO: return "Normal";
        case SeverityLevel::WARN: return "Warning";
        default: return "UNKNOWN";
    }
}

// Compute risk score
double DTC::computeRiskScore() const {
    double severityComponent = 0.0;
    switch (m_severityLevel) {
        case SeverityLevel::INFO: severityComponent = 10.0; break;
        case SeverityLevel::WARN: severityComponent = 40.0; break;
        case SeverityLevel::CRIT: severityComponent = 80.0; break;
        default: severityComponent = 10.0; break;
    }

    double occurenceComponent = std::min(static_cast<double>(m_occurenceCount) * 5.0, 50.0);

    const std::time_t now = std::time(nullptr);
    double ageComponent = 0.0;
    if ((m_lastOccurenceTime != 0) && (m_lastOccurenceTime <= now)) {
        const std::time_t delta = now - m_lastOccurenceTime;
        if (delta <= 3600) {
            ageComponent = 20.0;
        } else if (delta < 30 * 24 * 3600) {
            double ratio = static_cast<double>(delta - 3600) / (30.0 * 24 * 3600.0 - 3600.0);
            ageComponent = 20.0 * (1.0 - ratio);
        }
    }

    double totalScore = severityComponent + occurenceComponent + ageComponent;
    if (m_milOn) {
        totalScore *= 1.25;
    }

    return std::clamp(totalScore, 0.0, 100.0);
}

// Recommend action
std::string DTC::recommendAction() const {
    const double score = computeRiskScore();
    if (getConfirmed() && score > 75.0) return "Immediate Attention: isolate system and stop is unsafe..";
    if (getConfirmed() && score > 45.0) return "Scheduled urgent repair..";
    if (getMilOn() && score > 20.0) return "Drive Restricted: visit service soon";
    if (score > 20.0) return "Monitor: record and re-evaluate";
    return "Informational: no immediate reaction";
}

// Merge DTC if same code
bool DTC::mergeIfSameCode(const DTC& other) {
    if ((getCode() == other.getCode()) && (getSystem() == other.getSystem())) {
        const long newOccurenceCount = static_cast<long>(getOccurenceCount()) + static_cast<long>(other.getOccurenceCount());
        setOccurenceCount(static_cast<int>(std::min(newOccurenceCount, static_cast<long>(INT32_MAX))));
        setLastOccurenceTime(std::max(getLastOccurenceTime(), other.getLastOccurenceTime()));
        setConfirmed(getConfirmed() || other.getConfirmed());
        setPending(getPending() || other.getPending());
        setMilOn(getMilOn() || other.getMilOn());

        if (getOrigin().empty() && !other.getOrigin().empty()) setOrigin(other.getOrigin());
        if (getDescription().empty() && !other.getDescription().empty()) setDescription(other.getDescription());
        setActive(getActive() || other.getActive());

        return true;
    }
    return false;
}
