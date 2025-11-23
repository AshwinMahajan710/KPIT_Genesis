// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Thermostat.cpp
#include <string>
#include<stdexcept>
#include"SmartDevice.h"
#include"Thermostat.h"
#include<iostream>

// constructor --> parameterized
Thermostat::Thermostat(const std::string& name_, double temperature_){
  m_name = name_;
  m_temperature = temperature_;
}	

// activate function
void Thermostat::activate() const{
    std::cout<<"\nThermostat "<<m_name<<" set to "<<m_temperature<<"C"<<std::endl;
}

// returnging name function
std::string Thermostat::getName() const{
  return m_name;
}
