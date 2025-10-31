#include<iostream>
#include<string>
#include<stdexcept>
#include"ECU.h"
#include"EngineState.h"

//constructor --> default
ECU::ECU() : ECU(0,EngineState::OFF,0,0.0,0){};

//constructor --> Parameterized
ECU::ECU(int ecuId_, EngineState state_, int rpm_, double coolantTemp_, int totalFaultCodes_){
    m_ecuId = ecuId_;
    m_engineState = state_;

    //validating rpm
    if(rpm_<0) {throw std::invalid_argument("InvalidRPMException: RPM Can never be -ve");}
    else {m_rpm = rpm_;}

    m_coolantTemp = coolantTemp_;
    m_totalFaultCodes = totalFaultCodes_; // total capacity of faults

    // dynamically allocate memory for fault codes
    m_faultCodes = new int[totalFaultCodes_];
    m_faultCount = 0; // initially no faults
    m_throttlePosition = 0; // intially no throttle
}

//constructor --> Copy
ECU::ECU(const ECU& other){
    // perform a deep copy of dynamic members
    m_ecuId = other.m_ecuId;
    m_engineState = other.m_engineState;
    m_rpm = other.m_rpm;
    m_coolantTemp = other.m_coolantTemp;
    m_throttlePosition = other.m_throttlePosition;
    m_totalFaultCodes = other.m_totalFaultCodes;
    m_faultCount = other.m_faultCount;
    m_faultCodes = nullptr;
    if(m_totalFaultCodes > 0){
        m_faultCodes = new int[m_totalFaultCodes];
        for(int i=0;i<m_faultCount;i++){
            m_faultCodes[i] = other.m_faultCodes[i];
        }
        // initialize remaining slots (optional)
        for(int i=m_faultCount;i<m_totalFaultCodes;i++){
            m_faultCodes[i] = 0;
        }
    }
}

// Destructor
ECU::~ECU(){
    delete[] m_faultCodes;
    m_faultCodes = nullptr;
}

// copy assignment operator
ECU& ECU::operator=(const ECU& other){
    if(this == &other) return *this;

    // copy simple members
    m_ecuId = other.m_ecuId;
    m_engineState = other.m_engineState;
    m_rpm = other.m_rpm;
    m_coolantTemp = other.m_coolantTemp;
    m_throttlePosition = other.m_throttlePosition;
    // reallocate fault array if needed
    if(m_totalFaultCodes != other.m_totalFaultCodes){
        delete[] m_faultCodes;
        m_faultCodes = nullptr;
        m_totalFaultCodes = other.m_totalFaultCodes;
        if(m_totalFaultCodes > 0){
            m_faultCodes = new int[m_totalFaultCodes];
        }
    }
    m_faultCount = other.m_faultCount;
    if(m_faultCodes && other.m_faultCodes){
        for(int i=0;i<m_faultCount;i++){
            m_faultCodes[i] = other.m_faultCodes[i];
        }
        for(int i=m_faultCount;i<m_totalFaultCodes;i++) m_faultCodes[i]=0;
    }
    return *this;
}

// Getters
int ECU::getECUId() const{
    return m_ecuId; 
}
EngineState ECU::getEngineState() const{
    return m_engineState;
}
int ECU::getRPM() const{
    return m_rpm; 
}
double ECU::getCoolantTemp() const{
    return m_coolantTemp;
}
double ECU::getThrottlePsition() const{
    return m_throttlePosition;
}
int* ECU::getFaultCodes() const{
    return m_faultCodes;
}
int ECU::getFaultCount() const{
    return m_faultCount;
}
int ECU::getTotalFaultCount() const{
    return m_totalFaultCodes;
}

// Setters
void ECU::setECUId(int ecuId_){
    m_ecuId = ecuId_;
}
void ECU::setEngineState(EngineState state_){
    m_engineState = state_;
}
void ECU::setRPM(int rpm_){
    m_rpm = rpm_;
}
void ECU::setCoolantTemp(double coolantTemp_){
    m_coolantTemp = coolantTemp_;
}

// startEngine() --> Transitions state from OFF → CRANKING → IDLE 
void ECU::startEngine(){
    m_engineState = EngineState::CRANKING;
    std::cout<<"\nSet to Cranking.."<<std::endl;
    m_engineState = EngineState::IDLE;
    std::cout<<"Set to IDLE.."<<std::endl;
}

// accelerate(double throttle) --> Updates throttle and RPM (RPM = throttle × 60)
void ECU::accelerate(double throttle_){
    if(throttle_<0 || throttle_ > 100) {throw std::invalid_argument("InvalidThrottleException: Throttle values should be in range of 0 - 100");}
    else {
        m_throttlePosition = throttle_;
        m_rpm = 60 * m_throttlePosition;
    }
}

// addFaultCode(int code) --> Adds fault code dynamically
void ECU::addFaultCode(int code_){
    if(m_faultCount == m_totalFaultCodes) {throw std::out_of_range("MemoryFullException: Cannot store more faults as memory is already full...");}
    else{
        m_faultCodes[m_faultCount] = code_;
        m_faultCount++;
    }
}

// checkOverheating(): Sets state to OVERHEATING if coolantTemp > 105
void ECU::checkOverheating(){
    if(m_coolantTemp > 105.0) {
        m_engineState = EngineState::OVERHEATING;
        std::cout<<"\nEngine new state is overheating..."<<std::endl;
    }
}