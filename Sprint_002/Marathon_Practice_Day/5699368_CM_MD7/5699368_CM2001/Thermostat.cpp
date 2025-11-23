// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Thermostat.cpp
#include <string>
#include<stdexcept>
#include"SmartDevice.h"
#include"Thermostat.h"
#include<iostream>

// constructor --> parameterized
Thermostat::Thermostat(const std::string& name_, double temperature_):SmartDevice(name_), m_temperature(temperature_){}	

// activate function 
void Thermostat::activate(){
    std::string mode = (m_ecoMode) ? "on" : "off";
    std::cout<<"\nThermostat "<<getName()<<" set to "<<m_temperature<<"C"<< " [ECO mode: "<<mode<<" ]"<<std::endl;
}

// enabling ecomode
void Thermostat::enableEcoMode(bool mode_){
  m_ecoMode = mode_;
}