#include<string>
#include<iostream>
#include<stdexcept>
#include"Battery.h"

// parameterized constructor
Battery::Battery(int batteryId_, const std::string& batteryType_, const std::string& manufacturer_, double capacity_, double voltage_){
    
    // initializing all member variables with above parameters
    this->m_batteryId = batteryId_;
    this->m_batteryType = batteryType_;
    this->m_manufacturer = manufacturer_;
    this->m_voltage = voltage_;

    // Validation for capacity
    if(capacity_<0) {throw std::invalid_argument("InvalidCapacityException: \"Battery Capacity can never be -ve\"");}
    else {this->m_capacity = capacity_;}
}

// getters
int Battery::getBatteryId() const{
    return m_batteryId;
}
std::string Battery::getBatteryType() const{
    return m_batteryType;
}
std::string Battery::getManufacturer() const{
    return m_manufacturer;
}
double Battery::getCapacity() const{
    return m_capacity;
}
double Battery::getVoltage() const{
    return m_voltage;
}

// setters
void Battery::setBatteryId(int batteryId_){
    m_batteryId = batteryId_;
}
void Battery::setBatteryType(const std::string& batteryType_){
    m_batteryType = batteryType_;
}
void Battery::setManufacturer(const std::string& manufacturer_){
    m_manufacturer = manufacturer_;
}
void Battery::setCapacity(double capacity_){
    if(capacity_<0) {throw std::invalid_argument("InvalidCapacityException: \"Battery Capacity can never be -ve\"");}
    else {this->m_capacity = capacity_;}
}
void Battery::setVoltage(double voltage_){
    m_voltage = voltage_;
}

// overloading << operator to print battery details
std::ostream& operator <<(std::ostream& out, const Battery& other){
    out<<"Battery ID: "<<other.m_batteryId<<std::endl;
    out<<"Battery Type: "<<other.m_batteryType<<std::endl;
    out<<"Battery Manufacturer: "<<other.m_manufacturer<<std::endl;
    out<<"Battery Capacity: "<<other.m_capacity<<std::endl;
    out<<"Battery Voltage: "<<other.m_voltage<<std::endl;
    return out;
}