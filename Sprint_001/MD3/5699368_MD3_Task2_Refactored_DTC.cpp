#include "5699368_MD3_Task2_SeverityLevel.h"
#include "5699368_MD3_Task2_Refactored_DTC.h"
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm> // for std::min, std::max

// --------------------------
// Initialize static member
// --------------------------
int DTC::s_dtcCount = 0; // renamed from s_DTCCount → s_dtcCount (camelCase)

// --------------------------
// Constructors
// --------------------------

// Default constructor using delegation
DTC::DTC() 
    : DTC("", "", false, 0, 0, SeverityLevel::INFO, false, false, false, "", "") 
{
    // Nothing extra needed, delegated constructor handles initialization
}

// Parameterized constructor with initializer list
DTC::DTC(const std::string& code_, const std::string& description_,
         bool active_, int occurenceCount_, std::time_t lastOccurenceTime_,
         SeverityLevel severityLevel_, bool confirmed_, bool pending_,
         bool milOn_, const std::string& system_, const std::string& origin_)
    : m_code(code_), m_description(description_), m_active(active_),
      m_occurenceCount(occurenceCount_), m_lastOccurenceTime(lastOccurenceTime_),
      m_severityLevel(severityLevel_), m_confirmed(confirmed_), m_pending(pending_),
      m_milOn(milOn_), m_system(system_), m_origin(origin_) 
{
    s_dtcCount++; // Increment count for each DTC object created
}

// Copy constructor using delegation
DTC::DTC(const DTC& other)
    : DTC(other.m_code, other.m_description, other.m_active, other.m_occurenceCount,
          other.m_lastOccurenceTime, other.m_severityLevel, other.m_confirmed,
          other.m_pending, other.m_milOn, other.m_system, other.m_origin)
{
    // Delegation handles initialization
}

// Destructor
DTC::~DTC()
{
    s_dtcCount--; // Decrement static count on destruction
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
void DTC::setActive(bool active_) { m_active = active_; } // MISRA: removed const
void DTC::setOccurenceCount(int occurenceCount_) {
    m_occurenceCount = (occurenceCount_ < 0) ? 0 : occurenceCount_;
}
void DTC::setLastOccurenceTime(std::time_t lastOccurenceTime_) {
    const std::time_t now = std::time(nullptr);
    m_lastOccurenceTime = (lastOccurenceTime_ > now) ? now : lastOccurenceTime_;
}
void DTC::setSeverityLevel(SeverityLevel severityLevel_) { m_severityLevel = severityLevel_; }
void DTC::setConfirmed(bool confirmed_) { m_confirmed = confirmed_; }
void DTC::setPending(bool pending_) { m_pending = pending_; }
void DTC::setMilOn(bool milOn_) { m_milOn = milOn_; }
void DTC::setSystem(const std::string& system_) { m_system = system_; }
void DTC::setOrigin(const std::string& origin_) { m_origin = origin_; }

// Overloaded setter for severity by integer
void DTC::setSeverity(int level_) {
    if (level_ <= 0 || level_ > m_maxSeverity) {
        m_severityLevel = static_cast<SeverityLevel>(0); // default INFO
    } else {
        m_severityLevel = static_cast<SeverityLevel>(level_);
    }
}

// Overloaded setter for severity by string
void DTC::setSeverity(const std::string& name_) {
    if (name_ == "Crit") m_severityLevel = SeverityLevel::CRIT;
    else if (name_ == "Warn") m_severityLevel = SeverityLevel::WARN;
    else m_severityLevel = SeverityLevel::INFO;
}

// Mark active with optional argument
void DTC::markActive(bool state_) { m_active = state_; }

// --------------------------
// Core Member Functions
// --------------------------
void DTC::activate() { m_active = true; }
void DTC::deActivate() { m_active = false; }
void DTC::incrementOccurence() { m_occurenceCount++; }
void DTC::toggleMIL() { m_milOn = !m_milOn; }
void DTC::markConfirmed() { m_confirmed = true; m_pending = false; }

// Print full DTC info (MISRA: const-correctness retained)
void DTC::printDTCInfo() const {
    std::cout << "Code: " << m_code << "\n"
              << "Description: " << m_description << "\n"
              << "Activation status: " << (m_active ? "Active" : "Inactive") << "\n"
              << "Occurance Count: " << m_occurenceCount << "\n"
              << "Last Occurance Time: " << std::ctime(&m_lastOccurenceTime)
              << "Severity Level: " << getSeverityString() << "\n"
              << "Detection Confirmed: " << (m_confirmed ? "True" : "False") << "\n"
              << "Pending confirmation: " << (m_pending ? "Yes" : "False") << "\n"
              << "MIL On: " << (m_milOn ? "Yes" : "No") << "\n"
              << "Affected Subsystem: " << m_system << "\n"
              << "DTC Origin: " << m_origin << std::endl;
}

// Return severity as string
std::string DTC::getSeverityString() const {
    switch (m_severityLevel) {
        case SeverityLevel::CRIT: return "Critical";
        case SeverityLevel::WARN: return "Warning";
        case SeverityLevel::INFO: return "Normal";
        default: return "UNKNOWN";
    }
}

// --------------------------
// Risk Score & Recommendation
// --------------------------
double DTC::computeRiskScore() const {
    double severityScore = 0.0;
    switch (m_severityLevel) {
        case SeverityLevel::INFO: severityScore = 10.0; break;
        case SeverityLevel::WARN: severityScore = 40.0; break;
        case SeverityLevel::CRIT: severityScore = 80.0; break;
        default: severityScore = 10.0;
    }

    double occurenceScore = std::min(static_cast<double>(m_occurenceCount) * 5.0, 50.0);

    const std::time_t now = std::time(nullptr);
    double ageScore = 0.0;
    if (m_lastOccurenceTime != 0 && m_lastOccurenceTime <= now) {
        std::time_t delta = now - m_lastOccurenceTime;
        if (delta <= 3600) ageScore = 20.0;
        else if (delta < 30 * 24 * 3600) ageScore = 20.0 * (1.0 - static_cast<double>(delta - 3600) / (30 * 24 * 3600 - 3600));
    }

    double totalScore = severityScore + occurenceScore + ageScore;
    if (m_milOn) totalScore *= 1.25;
    return std::clamp(totalScore, 0.0, 100.0); // cap between 0 and 100
}

// Recommend action based on risk score
std::string DTC::recommendAction() const {
    double score = computeRiskScore();
    if (getConfirmed() && score > 75.0) return "Immediate Attention: isolate system and stop is unsafe..";
    if (getConfirmed() && score > 45.0) return "Scheduled urgent repair..";
    if (getMilOn() && score > 20.0) return "Drive Restricted: visit service soon";
    if (score > 20.0) return "Monitor: record and re-evaluate";
    return "Informational: no immediate reaction";
}
