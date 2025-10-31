#include"Sensor.h"
#include<stdexcept>
#include<iostream>
#include<string>

// constructor --> default
Sensor::Sensor(): Sensor(0,"",INACTIVE,0.0,0){};

//constructor --> parameterized
Sensor::Sensor(int sensorId_, const std::string& sensorType_, SensorStatus status_, double detectionRange_, int capacity_){
    m_sensorId = sensorId_;
    m_sensorType = sensorType_;
    m_status = status_;
    
    // validating detection range
    if(detectionRange_<0) {throw std::invalid_argument("InvalidDetectionRangeException: Detection range can never be -ve");}
    else {m_detectionRange = detectionRange_;}

    // validating capacity
    if(capacity_<0) {throw std::invalid_argument("InvalidCapacityException: Capacity can never be -ve");}
    else {m_capacity = capacity_;}

    // creating new dynamic array
    m_dataPoints = new int[m_capacity];
    m_dataCount = 0; // initially no datapoint 
}

// constructor --> copy
Sensor::Sensor(const Sensor& other){
    delete[] m_dataPoints; // as no need of previous data points
    m_sensorId = other.m_sensorId;
    m_sensorType = other.m_sensorType;
    m_status = other.m_status;
    m_detectionRange = other.m_detectionRange;
    m_capacity = other.m_capacity;
    m_dataPoints = new int[m_capacity];
    m_dataCount = other.m_dataCount;
    for(int i=0;i<m_dataCount;i++){
        m_dataPoints[i] = other.m_dataPoints[i];
    }
}

// getters
int Sensor::getSensorId() const{
    return m_sensorId;
}
std::string Sensor:: getSensorType() const{
    return m_sensorType;
}
SensorStatus Sensor::getStatus() const{
    return m_status;
}
double Sensor::getDetectionRange() const{
    return m_detectionRange;
}
int* Sensor::getDataPoints() const{
    return m_dataPoints;
}
int Sensor::getDataCount() const{
    return m_dataCount;
}
int Sensor::getCapacity() const{
    return m_capacity;
}

// Setters
void Sensor::setSensorId(int sensorId_){
    m_sensorId = sensorId_;
}
void Sensor::setSensorType(const std::string& sensorType_){
    m_sensorType = sensorType_;
}
void Sensor::setStatus(SensorStatus status_){
    m_status = status_;
}
void Sensor::setDetectionRange(double detectionRange_){
    if(detectionRange_<0) {throw std::invalid_argument("InvalidDetectionRangeException: Detection range can never be -ve");}
    else {m_detectionRange = detectionRange_;}
}

// updateStatus(SensorStatus)  --> to update sensors operational status
void Sensor::updateStatus(SensorStatus status_){
    m_status = status_;
}

// recordData(int) --> adding new reading data
void Sensor::recordData(int data_){
    if(m_dataCount == m_capacity) {throw std::out_of_range("MemoryFullException: Memory is full .. cannot add new datapoint...");}
    else {
        m_dataPoints[m_dataCount] = data_;
        m_dataCount++;
    }
}

// getAverageReading() --> get average reading value
double Sensor::getAverageReading() const{
    double sumOfReadings=0;
    for(int i=0;i<m_dataCount;i++){
        sumOfReadings += m_dataPoints[i];
    }
    return (sumOfReadings/m_dataCount);
}

// getStatusAsString() --> getting string value of status
std::string Sensor::getStatusAsString() const{
    switch (m_status)
    {
        case INACTIVE:{
            return "InActive";
            break;
        }
        
        case INITIALIZING:{
            return "Initializing";
            break;
        }
        case ACTIVE:{
            return "Active";
            break;
        }
        case FAULT:{
            return "Fault";
            break;
        }
        case CALIBRATING:{
            return "Calibrating";
            break;
        }
        default:{
            return "Unknown";
            break;
        }
            
    }
}

// displaySensorInfo() --> to display all sensor info
void Sensor::displaySensorInfo() const{
    std::cout<<"\nSensor ID: "<<m_sensorId<<std::endl;
    std::cout<<"Sensor Type: "<<m_sensorType<<std::endl;
    std::cout<<"Sensor Status: "<<getStatusAsString()<<std::endl;
    std::cout<<"Sensor Detection Range: "<<m_detectionRange<<std::endl;
    std::cout<<"Max Readings Capacity: "<<m_capacity<<std::endl;
    std::cout<<"Current readings count: "<<m_dataCount<<std::endl;
    std::cout<<"Readings: ";
    for(int i=0;i<m_dataCount;i++){
        std::cout<<m_dataPoints[i]<<" ";
    }
    std::cout<<std::endl;
}

// destructor
Sensor::~Sensor(){
    delete[] m_dataPoints;
}