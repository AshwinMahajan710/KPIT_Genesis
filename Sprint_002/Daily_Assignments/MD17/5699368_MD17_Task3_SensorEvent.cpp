#include<string>
#include"5699368_MD17_Task3_SensorEvent.h"
#include<stdexcept>
#include<iostream>

// constructor --> parameterized
SensorEvent::SensorEvent(const std::string& type_, double value_, bool isCritical_): m_isCritical(isCritical_){
    
    // validate moduleName
    if(type_.length() != 0) {m_type = type_;}
    else {throw std::runtime_error("TypeNameEmptyException");}

    // validate value
    if(value_ < 0) {throw std::runtime_error("-ve Value Exception. ");}
    else {m_value = value_;}
}

// getters
std::string SensorEvent:: getType() const{
    return m_type;
};
double SensorEvent:: getValue() const{
    return m_value;
};
bool SensorEvent:: getIsCriticalEvent() const{
    return m_isCritical;
};

// display helper function
void SensorEvent::display() const{
    std::cout<<"\nType Name: "<<m_type<<std::endl;
    std::cout<<"Value: "<<m_value<<std::endl;
    std::cout<<"Is Event Cirtical: "<<((m_isCritical) ? "Yes":"No")<<std::endl;
}