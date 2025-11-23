#include"EngineModule.h"
#include"EngineType.h"
#include<iostream>
#include<stdexcept>

// constructor --> parametrized
EngineModule::EngineModule(int id_, float rpm_, float temperature_, float value_, EngineType type_){

    m_type = type_; // assign type first for validation

    // validate efficiency
    if(m_type == EngineType::PETROL || m_type == EngineType::DIESEL){
        if(value_ > 80.0f){
            m_efficiency = 80.0f;
            throw std::range_error("MAX Efficiency is 80%.. capping value to 80");
        } 
        else if(value_<0.0){
            m_efficiency = 0.0f;
            throw std::range_error("MIN Efficiency is 0%.. capping value to 0");
        }    
        else{
            m_efficiency = value_;
        }
    }
    else{
        if(value_ > 100.0){
            m_efficiency = 100.0f;
            throw std::range_error("MAX Efficiency is 100%.. capping value to 100");
        }
        else if(value_<0.0){
            m_efficiency = 0.0f;
            throw std::range_error("MIN Efficiency is 0%.. capping value to 0");
        }    
        else{
            m_efficiency = value_;
        }
    }

    // after validation intialize remaining attaributes
    m_id = id_;
    m_rpm = rpm_;
    m_temperature = temperature_;
}

// Destructor
EngineModule::~EngineModule(){
    std::cout<<"Object with id "<<m_id<<" Destroyed..."<<std::endl;
}

// getters
int EngineModule::getId() const{
    return m_id;
}
float EngineModule::getRpm() const{
    return m_rpm;
}
float EngineModule::getTemperature() const{
    return m_temperature;
}
float EngineModule::getEfficiency() const{
    return m_efficiency;
}
EngineType EngineModule::getType() const{
    return m_type;
}

// setters
void EngineModule::setId(int id_){
    m_id = id_;
}
void EngineModule::setRpm(float rpm_){
    m_rpm = rpm_;
}
void EngineModule::setTemperature(float temperature_){
    m_temperature = temperature_;
}
void EngineModule::setEfficiency(float value_){
    // validate efficiency
    if(m_type == EngineType::PETROL || m_type == EngineType::DIESEL){
        if(value_ > 80.0f){
            m_efficiency = 80.0f;
            throw std::range_error("MAX Efficiency is 80%.. capping value to 80");
        } 
        else if(value_<0.0){
            m_efficiency = 0.0f;
            throw std::range_error("MIN Efficiency is 0%.. capping value to 0");
        }    
        else{
            m_efficiency = value_;
        }
    }
    else{
        if(value_ > 100.0){
            m_efficiency = 100.0f;
            throw std::range_error("MAX Efficiency is 100%.. capping value to 100");
        }
        else if(value_<0.0){
            m_efficiency = 0.0f;
            throw std::range_error("MIN Efficiency is 0%.. capping value to 0");
        }    
        else{
            m_efficiency = value_;
        }
    }
}
void EngineModule::setType(EngineType type_){
    m_type = type_;
}

// display details --> for engine module
void EngineModule::displayDetails() const{
    std::cout<<"Engine Id: "<<m_id<<std::endl;
    std::cout<<"Engine RPM: "<<m_rpm<<std::endl;
    std::cout<<"Engine Temperature: "<<m_temperature<<std::endl;
    std::cout<<"Engine Efficiency: "<<m_efficiency<<std::endl;
    std::cout<<"Engine Type: "<<getEngineTypeName()<<std::endl;
}

// to update efficiency --> Throw std::range_error if value is outside [0, 100] --> For PETROL and DIESEL, cap efficiency at 80% and throw if exceeded
void EngineModule::updateEfficiency(float value_){
    // validate efficiency
    if(m_type == EngineType::PETROL || m_type == EngineType::DIESEL){
        if(value_ > 80.0f){
            m_efficiency = 80.0f;
            throw std::range_error("MAX Efficiency is 80%.. capping value to 80");
        } 
        else if(value_<0.0){
            m_efficiency = 0.0f;
            throw std::range_error("MIN Efficiency is 0%.. capping value to 0");
        }    
        else{
            m_efficiency = value_;
        }
    }
    else{
        if(value_ > 100.0){
            m_efficiency = 100.0f;
            throw std::range_error("MAX Efficiency is 100%.. capping value to 100");
        }
        else if(value_<0.0){
            m_efficiency = 0.0f;
            throw std::range_error("MIN Efficiency is 0%.. capping value to 0");
        }    
        else{
            m_efficiency = value_;
        }
    }
}

// to calculate power --> rpm × efficiency × 0.01
float EngineModule::calculatePowerOutput() const{
    return (m_rpm * m_efficiency * 0.01);
}

// helper --> to get EngineType name
std::string EngineModule::getEngineTypeName() const{
    switch (m_type)
    {
        case EngineType::DIESEL:{
            return "DIESEL";
            break;
        }
        case EngineType::PETROL:{
            return "PETROL";
            break;
        }
        case EngineType::HYBRID:{
            return "HYBRID";
            break;
        }
        default:{
            return "NONE";
            break;
        }
    }
}