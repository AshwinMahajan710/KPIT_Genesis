#include"ElectricMotor.h"
#include<iostream>
#include<stdexcept>
#include<string>

// constructor --> default
ElectricMotor::ElectricMotor() : ElectricMotor(0.0,0){};

// constructor --> parametrized
ElectricMotor::ElectricMotor(float maxPower_, int maxTorque_){
    if(maxPower_ < 0) {throw std::invalid_argument("InvalidMaxPowerException: \"Max power can never be -ve");}
    else {this->m_maxPower = maxPower_;}
    if(maxTorque_ < 0) {throw std::invalid_argument("InvalidMaxTorqueException: \"Max Torque can never be -ve");}
    else {this->m_maxTorque = maxTorque_;}
}

// getters
float ElectricMotor::getMaxPower() const{
    return m_maxPower;
}
int ElectricMotor::getMaxTorque() const{
    return m_maxTorque;
}

// setters
void ElectricMotor::setMaxPower(float maxPower_){
    if(maxPower_ < 0) {throw std::invalid_argument("InvalidMaxPowerException: \"Max power can never be -ve");}
    else {this->m_maxPower = maxPower_;}
}
void ElectricMotor::setMaxTorque(float maxTorque_){
    if(maxTorque_ < 0) {throw std::invalid_argument("InvalidMaxTorqueException: \"Max Torque can never be -ve");}
    else {this->m_maxTorque = maxTorque_;}
}

// overloading << operator to display details
std::ostream& operator << (std::ostream& out, const ElectricMotor& other){
    std::cout<<"Max Power: "<<other.m_maxPower<<std::endl;
    std::cout<<"Max Torque: "<<other.m_maxTorque<<std::endl;
    return out;
}