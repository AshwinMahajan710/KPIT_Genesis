#include<vector>
#include"SmartDevice.h"
#include"Light.h"
#include"Thermostat.h"
#include<string>
#include<memory>
#include<unordered_map>
#include<functional>
#include"SmartHomeController.h"

// pushing objs in function
void SmartHomeController::registerDevice(std::unique_ptr<SmartDevice> device, std::function<void()> onActivate){
    m_devices.push_back(std::move(device));
    m_callbacks[device->getName()] = onActivate;
}

// to activate with particular names
void SmartHomeController::activateDevice(const std::string& name){
    if(m_callbacks.find(name)!= m_callbacks.end()){
        m_callbacks[name]();
    }
}

// activate all devices and its callbacks
void SmartHomeController::activateAll(){
    for(auto &i : m_callbacks){
        i.second();   // call the stored callback
    }
}