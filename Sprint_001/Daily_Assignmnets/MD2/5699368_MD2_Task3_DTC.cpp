#include"5699368_MD2_Task3_SeverityLevel.h"
#include"5699368_MD2_Task3_DTC.h"
#include<iostream>
#include<ctime>
#include<string>

// Default constructors --> using the concept of constructor delegation
DTC::DTC() : DTC("","",false,0,0,SeverityLevel::INFO,false,false,false,"","") {}

// Parameterized constructor --> using the initializer list
DTC::DTC(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_):m_code(code_), m_description(description_), m_active(active_), m_occurenceCount(occurenceCount_), m_lastOccurenceTime(lastOccurenceTime_),m_severityLevel(severityLevel_),m_confirmed(confirmed_),m_pending(pending_),m_milOn(milOn_),m_system(system_),m_origin(origin_) {
    s_DTCCount++; // incrementing DTC count
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
    m_code = code_;
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
// set severity using int values --> if not valid set to INFO
void DTC::setSeverity(int level_){
    if(level_==1 || level_ == 2) {m_severityLevel = static_cast<SeverityLevel>(level_);}
    else {m_severityLevel = static_cast<SeverityLevel>(0);}
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
void DTC::printDTCInfo(){
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
std::string DTC::getSeverityString(){

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


// ComputeRiskScore --> will return score between 0.0 to 100.0 based upon severity, occurances, recency, MIL Status
double DTC::computeRiskScore() const{
    double totalScore_ = 0.0;
    
    //Analyzing severity and adding the scores
    double severityComponent_ = 0.0; 
    if(m_severityLevel == SeverityLevel::INFO) {severityComponent_ = 10.0;}
    else if(m_severityLevel == SeverityLevel::WARN) {severityComponent_ = 40.0;}
    else if(m_severityLevel == SeverityLevel::CRIT){severityComponent_= 80.0;}
    else {severityComponent_ = 10.0;}

    // Analyzing and adding score as per occurence component
    double occurenceComponent_ = 0.0;
    if(m_occurenceCount < 0 ) {occurenceComponent_ = 0.0;}
    else {occurenceComponent_ = ((m_occurenceCount*5.0) > 50.0) ? 50.0 : (m_occurenceCount*5.0);}; 
    
    // Analyzing the age component and adding score as per it
    std::time_t now = std::time(nullptr); // current time
    double ageComponent_ = 0.0;
    if(m_lastOccurenceTime==0 || m_lastOccurenceTime>now) {ageComponent_ = 0.0;}
    else if(now - m_lastOccurenceTime <= 3600 ) {ageComponent_ = 20.0;}
    else if (now - m_lastOccurenceTime < 30 * 24 * 3600) {
        double ratio = ((now - m_lastOccurenceTime) - 3600.0) / ((30.0 * 24 * 3600.0) - 3600.0);
        ageComponent_ = 20.0 * (1.0 - ratio);
    }
    else {ageComponent_ = 0.0;}

    // Analyzing and adding score as per MIL
    double MIL_multiplier = severityComponent_ + occurenceComponent_ + ageComponent_;
    if(m_milOn) {totalScore_ = MIL_multiplier * 1.25;}
    else {totalScore_ = MIL_multiplier;}

    // cap total score and return it
    totalScore_ = (totalScore_<0) ? 0 : ((totalScore_ >100) ? 100 : totalScore_);
    return totalScore_;
}

// recommend action function
std::string DTC::recommendAction() const{
    double score = computeRiskScore();
    if(getConfirmed() && score > 75.0) {return "Immediate Attention: isolate system and stop is unsafe..";}
    else if(getConfirmed() && score > 45.0 ) {return "Scheduled urgent repair..";}
    else if(getMilOn() && score>20.0) {return "Drive Restricted: visit service soon";}
    else if(score>20.0) {return "Monitor: record and re-evaluate";}
    else {return "Informational: no immediate reaction";}
}

bool DTC::mergeIfSameCode(const DTC& other){
    // condition for successful merging
    if((getCode() == other.getCode()) && (getSystem() == other.getSystem())){

        // set new occurence
        long newOccurenceCount =static_cast<long>( this->getOccurenceCount()) +static_cast<long>( other.getOccurenceCount());
        this->setOccurenceCount(std::min(newOccurenceCount,static_cast<long>(INT32_MAX)));

        // set new last occurance time
        this->setLastOccurenceTime(std::max(this->getLastOccurenceTime(), other.getLastOccurenceTime()));

        //set new confirmed
        this->setConfirmed(this->getConfirmed() || other.getConfirmed());

        //set new pending
        this->setPending(this->getPending() || other.getPending());

        //set new milon
        this->setMilOn(this->getMilOn() || other.getMilOn());

        //set origin
        if(this->getOrigin().length() == 0 && other.getOrigin().length() != 0) {this->setOrigin(other.getOrigin());}

        // set description
        if(this->getDescription().length() == 0 && other.getDescription().length() != 0) {this->setDescription(other.getDescription());}

        // set active
        this->setActive(this->getActive() || other.getActive());

        // return true as condition fullfilled for successful merging
        return true;
    }
    else{
        return false;
    }
}