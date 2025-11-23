// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Light.cpp
#include <string>
#include<stdexcept>
#include"SmartDevice.h"
#include"Light.h"
#include<iostream>

// constructor --> parametrized with validation
Light::Light(const std::string& name_, int brightness_){
    m_name = name_;

    // validating brightness
    if(brightness_<0 || brightness_ > 100){throw std::invalid_argument("brightness value out of range..");}
    else {m_brightness = brightness_; }
}

// activate function
void Light::activate() const{
    std::cout<<"\nLight "<<m_name<<" turned on at "<<m_brightness<<"%"<<std::endl;
}

// getName function
std::string Light::getName() const{
  return m_name;
}
