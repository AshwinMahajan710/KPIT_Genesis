#include"5699368_MD6_Task2_DTC.h"
#include"5699368_MD6_Task2_SeverityLevel.h"
#include<iostream>
#include<ctime>
#include<string>
#include<stdexcept>

// Default constructors --> using the concept of constructor delegation
DTC::DTC() : DTC("","",false,0,0,SeverityLevel::INFO,false,false,false,"","") {}

// Parameterized constructor --> using the initializer list
DTC::DTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_): m_description(description_), m_active(active_), m_occurenceCount(occurenceCount_),m_severityLevel(severityLevel_),m_confirmed(confirmed_),m_pending(pending_),m_milOn(milOn_),m_system(system_),m_origin(origin_) {

    // handling empty code exception
    if(code_ == "") {throw std::invalid_argument("EmptyCodeException: \"DTC code cannot be empty...\"");}
    else{
        bool isSpace = true;
        for(char ch : code_){
            if(ch != ' '){
                isSpace = false;
                break;
            }
        }
        if(isSpace) {throw std::invalid_argument("EmptyCodeException: \"DTC code cannot be empty...\"");}
    }
    m_code = code_; // after validation of emptyness assign 

    // handline invalid time
    if(lastOccurenceTime_<0){throw std::invalid_argument("InvalidTimeStampException: \"Timestamp must be a valid non-negative UNIX time\"");}
    else {m_lastOccurenceTime = lastOccurenceTime_;} // after validation assign lastoccurence time

    // incrementing DTC count
    s_DTCCount++; 
}

// copy constructor
DTC::DTC(const DTC& other) : DTC(other.m_code,other.m_description,other.m_active,other.m_occurenceCount,other.m_lastOccurenceTime,other.m_severityLevel,other.m_confirmed,other.m_pending,other.m_milOn,other.m_system,other.m_origin){}

// Destructor
DTC::~DTC(){
    s_DTCCount--; // decrementing count after object deletion
} 
// Getters
std::string DTC:: getCode() const{
    return m_code;
}    
std::string DTC::getDescription() const{
    return m_description;
}
bool DTC::getActive() const{
    return m_active;
}
int DTC::getOccurenceCount() const{
    return m_occurenceCount;
}
std::time_t DTC::getLastOccurenceTime() const{
    return m_lastOccurenceTime;
}
SeverityLevel DTC::getSeverityLevel() const{
    return m_severityLevel;
}
bool DTC::getConfirmed() const{
    return m_confirmed;
}
bool DTC::getPending() const{
    return m_pending;
}
bool DTC::getMilOn() const{
    return m_milOn;
}
std::string DTC::getSystem() const{
    return m_system;
}
std::string DTC::getOrigin() const{
    return m_origin;
}

// getter function for DTC object count
int DTC::getDTCCount(){
    return s_DTCCount;
}

// setters
void DTC::setCode(const std::string& code_){
    if(code_ == "") {throw std::invalid_argument("EmptyCodeException: \"DTC code cannot be empty...\"");}
    else{
        bool isSpace = true;
        for(char ch : code_){
            if(ch != ' '){
                isSpace = false;
                break;
            }
        }
        if(isSpace) {throw std::invalid_argument("EmptyCodeException: \"DTC code cannot be empty...\"");}
    }
    m_code = code_; // after validation of emptyness assign 
}
void DTC::setDescription(const std::string& description_){
    m_description = description_;
}
void DTC::setActive(const bool active_){
    m_active = active_;
}
void DTC::setOccurenceCount(const int occurenceCount_){
    m_occurenceCount = (occurenceCount_ < 0 ) ? 0 : occurenceCount_;
}
void DTC::setLastOccurenceTime(const std::time_t lastOccurenceTime_){
    // handline invalid time
    if(lastOccurenceTime_<0){throw std::invalid_argument("InvalidTimeStampException: \"Timestamp must be a valid non-negative UNIX time\"");}
    time_t now = std::time(nullptr);
    m_lastOccurenceTime = (lastOccurenceTime_ > now) ? now: lastOccurenceTime_;
}
void DTC::setSeverityLevel(const SeverityLevel severityLevel_){
    m_severityLevel = severityLevel_;
}
void DTC::setConfirmed(const bool confirmed_){
    m_confirmed = confirmed_;
}
void DTC::setPending(const bool pending_){
    m_pending = pending_;
}
void DTC::setMilOn(const bool milOn_){
    m_milOn = milOn_;
}
void DTC::setSystem(const std::string& system_){
    m_system = system_;
}
void DTC::setOrigin(const std::string& origin_){
    m_origin = origin_;
}
// set severity using int values --> if not valid set to INFO --> using MAX_SEVRITY to validate 
void DTC::setSeverity(int level_){
    if(level_<=0 || level_ > m_maxSeverity) {m_severityLevel = static_cast<SeverityLevel>(0);}
    else {m_severityLevel = static_cast<SeverityLevel>(level_);}
}
// set severity using string value --> INFO if string not matches value 
void DTC::setSeverity(const std::string& name_){
    if(name_ == "Crit") {m_severityLevel = SeverityLevel::CRIT;} 
    else if(name_ == "Warn") {m_severityLevel = SeverityLevel::WARN;} 
    else {m_severityLevel = SeverityLevel::INFO;}
}
// default argument setter method
void DTC::markActive(bool state_){
    m_active = state_;
}

// member functions

// set active attribute to true
void DTC::activate(){
    m_active = true;
}

// set active attribute to false
void DTC::deActivate(){
    m_active = false;
}

// increment occurance count by 1
void DTC::incrementOccurence(){
    m_occurenceCount ++;
}

// printing information
void DTC::printDTCInfo() const{
   std::cout<<"Code: "<<m_code<<std::endl;
   std::cout<<"Description: "<<m_description<<std::endl;
   std::cout<<"Activation status: "<<((m_active) ? "Active": "Inactive" )<<std::endl;
   std::cout<<"Occurance Count: "<<m_occurenceCount<<std::endl;
   std::cout<<"Last Occurance Time: "<<std::ctime(&m_lastOccurenceTime);
   std::cout<<"Severity Level: "<<getSeverityString()<<std::endl;
   std::cout<<"Detection Confirmed: "<<((m_confirmed) ? "True" : "False")<<std::endl;
   std::cout<<"Is pending confirmation: "<<((m_pending) ? "Yes": "False")<<std::endl;
   std::cout<<"Malfunction Indicator light on: "<<((m_milOn) ? "Yes" : "No")<<std::endl;
   std::cout<<"Affected Subsystem: "<<m_system<<std::endl;
   std::cout<<"DTC Origin: "<<m_origin<<std::endl;
}

// toggle mil -> if on make it off --> if off make it on
void DTC::toggleMIL(){
    if (m_milOn) {m_milOn = false;}
    else {m_milOn = true;}
}

// Mark confirm function
void DTC::markConfirmed(){
    m_confirmed = true;
    m_pending = false;
}

// additional function to get string value of severity level
std::string DTC::getSeverityString() const{

    switch (m_severityLevel)
    {
        case SeverityLevel::CRIT:{
            return "Critical";
            break;
        }
        case SeverityLevel::INFO:{
            return "Normal";
            break;
        }
        case SeverityLevel::WARN:{
            return "Warning";
            break;
        }

        default:{
            return "UNKONWN";
        }
    }
}

