#include <string>
#include<stdexcept>
#include"SmartDevice.h"
#include"Light.h"
#include<iostream>

// constructor --> parametrized with validation
Light::Light(const std::string& name_, int brightness_): SmartDevice(name_){

    // validating brightness
    if(brightness_<0 || brightness_ > 100){throw std::invalid_argument("brightness value out of range..");}
    else {m_brightness = brightness_; }
}

// activate function
void Light::activate() {
    m_isOn = (m_isOn) ? false : true; // toggle
    std::string status = (m_isOn)? "on" : "off";
    std::cout<<"\nLight "<<getName()<<"is now "<<m_brightness<<"%"<<std::endl;
}

// function to update brightness
void Light::setBrightness(int brightness_){
    // validating brightness
    if(brightness_<0 || brightness_ > 100){throw std::invalid_argument("brightness value out of range..");}
    else {m_brightness = brightness_;}
}

