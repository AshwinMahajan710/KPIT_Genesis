// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// SmartHomeController.cpp

#include <string>
#include<vector>
#include<memory>
#include<functional>
#include"SmartDevice.h"
#include"Light.h"
#include"Thermostat.h"
#include"SmartHomeController.h"
#include<iostream>

// function to add devices and callbacks
void SmartHomeController:: addDevice(std::unique_ptr<SmartDevice> device, std::function<void()> onActivate){
  devices.push_back(std::move(device));
  callbacks.push_back(onActivate);
}

// function for activating devices
void SmartHomeController::activateAll(){
    std::cout<<"\nActivating all smart devices.."<<std::endl;
    for(auto i = 0; i<devices.size(); i++){
      std::cout<<"\n";
      devices[i]->activate();
      callbacks[i]();
    }
}
