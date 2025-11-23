#include<string>
#include"5699368_MD17_Task1_SensorData.h"
#include<stdexcept>
#include<iostream>
// constructor --> parameterized
Sensordata::Sensordata(const std::string& moduleName_, double value_, bool isValid_): m_isValid(isValid_){
    
    // validate moduleName
    if(moduleName_.length() != 0) {m_moduleName = moduleName_;}
    else {throw std::runtime_error("ModuleNameEmptyException");}

    // validate value
    if(value_ < 0) {throw std::runtime_error("-ve Value Exception. ");}
    else {m_value = value_;}
}

// getters
std::string Sensordata:: getModuleName() const{
    return m_moduleName;
};
double Sensordata:: getValue() const{
    return m_value;
};
bool Sensordata:: isValidReading() const{
    return m_isValid;
};