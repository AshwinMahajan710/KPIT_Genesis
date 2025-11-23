#include<string>
#include"SmartDevice.h"

// constructor --> parameterized
SmartDevice:: SmartDevice(const std::string& name_): m_name(name_){};

// getname --> virtual function
std::string SmartDevice::getName() const{
    return m_name;
}

// virtual destructor
SmartDevice::~SmartDevice(){};
