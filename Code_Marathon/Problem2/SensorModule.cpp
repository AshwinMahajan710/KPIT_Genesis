#include"EngineModule.h"
#include"EngineType.h"
#include"SensorModule.h"
#include<iostream>

//constructors --> (base pointer and this member value)
SensorModule::SensorModule(EngineModule* modulePtr, float temperature_): EngineModule(modulePtr->getId(), modulePtr->getRpm(), modulePtr->getTemperature(), modulePtr->getEfficiency(), modulePtr->getType()) , m_ambientTemperatureInC(temperature_){};

//constructors --> (all member values)
SensorModule::SensorModule(int id, float rpm, float temperature, float efficiency, EngineType type, float ambientTemp): EngineModule(id,rpm,temperature,efficiency,type), m_ambientTemperatureInC(ambientTemp){}

// checking is module critical
bool SensorModule::isModuleCritical() const{
    if(calculatePowerOutput() == 0){
        return true;
    }
    else {
        return false;
    }
}

// overrides base method to print details
void SensorModule::displayDetails() const{
    EngineModule::displayDetails();
    std::cout<<"Ambient Temperature: "<<m_ambientTemperatureInC<<std::endl;
}

 //– Applies temperature loss factor: EngineModule::calculatePowerOutput() × LossFactor
float SensorModule::calculatePowerOutput() const{
    float factor = 0.0f;

    // getting factor for PETROL type
    if(getType() == EngineType::PETROL){
        float lowTemp = -10.0;
        float highTemp = 120.0;
        factor = getFactor(lowTemp,highTemp,m_ambientTemperatureInC);
    }

    // getting factor for DIESEL type
    else if(getType() == EngineType::DIESEL){
        float lowTemp = -20.0;
        float highTemp = 130.0;
        factor = getFactor(lowTemp,highTemp,m_ambientTemperatureInC);
    }

    // getting factor for HYBRID type
    else{
        float lowTemp = 0.0;
        float highTemp = 140.0;
        factor = getFactor(lowTemp,highTemp,m_ambientTemperatureInC);
    }
    return (EngineModule::calculatePowerOutput() * factor);
}

// helper --> to get factor value by low temp and high temp
float SensorModule::getFactor(float lowTemp, float highTemp, float T) const{
    if(T <= lowTemp) {return 1.0f;}
    else if(lowTemp < T < highTemp) {return 1.0 - (T - lowTemp)/(highTemp - lowTemp);}
    else {return 0.0f;}
}

// destructor
SensorModule::~SensorModule(){};