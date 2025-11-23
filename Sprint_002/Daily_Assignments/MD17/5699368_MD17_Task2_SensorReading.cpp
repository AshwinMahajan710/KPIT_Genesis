#include<string>
#include"5699368_MD17_Task2_SensorReading.h"
#include<stdexcept>
#include<iostream>

// constructor --> parameterized
SensorReading::SensorReading(const std::string& moduleName_, double value_, bool isFaulty_): m_isfaulty(isFaulty_){
    
    // validate moduleName
    if(moduleName_.length() != 0) {m_moduleName = moduleName_;}
    else {throw std::runtime_error("ModuleNameEmptyException");}

    // validate value
    if(value_ < 0) {throw std::runtime_error("-ve Value Exception. ");}
    else {m_value = value_;}
}

// getters
std::string SensorReading:: getModuleName() const{
    return m_moduleName;
};
double SensorReading:: getValue() const{
    return m_value;
};
bool SensorReading:: isFaultyModule() const{
    return m_isfaulty;
};

// display helper function
void SensorReading::display() const{
    std::cout<<"\nModule Name: "<<m_moduleName<<std::endl;
    std::cout<<"Value: "<<m_value<<std::endl;
    std::cout<<"Is Module Faulty: "<<((m_isfaulty) ? "Yes":"No")<<std::endl;
}