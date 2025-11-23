#include"EngineModule.h"
#include"EngineType.h"
#include"SensorModule.h"
#include"VehicleFleet.h"
#include<iostream>

// constructor --> by sensor obj
VehicleFleet::VehicleFleet(SensorModule& m, int size){
    m_modules[0] = &m;
    m_size = 1;
}

// Replace modules with efficiency == 0 or ambientTemp > 140°C
bool VehicleFleet::replaceFaultyModules(SensorModule* m){
    for(int i=0;i<m_size;i++){
        if(m_modules[i]->m_ambientTemperatureInC > 140.0 || m_modules[i]->getEfficiency() == 0){
            m_modules[i] = m;
            std::cout<<"\nReplaced successfully..."<<std::endl;
            return true;
        }
    }
    std::cout<<"\nNot replaced..."<<std::endl;
    return false;
}

// getting average ambient temp
float VehicleFleet::averageAmbientTemperature() const{
    float totalTemperature = 0.0;
    for(int i=0;i<m_size;i++){
        totalTemperature += m_modules[i]->m_ambientTemperatureInC; 
    }
    return totalTemperature/m_size;
}

// Add/Append new module to existing fleet
void VehicleFleet::operator+=(SensorModule* m){
    m_modules[m_size++] = m;
}

// destructor   
VehicleFleet::~VehicleFleet(){};