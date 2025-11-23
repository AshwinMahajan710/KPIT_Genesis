// < = = = = = = = = = =  Global.cpp  = = = = = = = = = = >
#include<memory>
#include<vector>
#include"Device.h"
#include"Status.h"
#include"Global.h"
#include<iostream>
#include<string>

// function to create and return vector of unique_ptr<Device> with smaple data
std::vector<std::unique_ptr<Device>> createDevices(){
  std::vector<std::unique_ptr<Device>> devices;
  devices.emplace_back(std::make_unique<Device>(1,"Engine",Status::ACTIVE));
  devices.emplace_back(std::make_unique<Device>(2,"Brake",Status::INACTIVE));
  devices.emplace_back(std::make_unique<Device>(3,"Mirror",Status::INACTIVE));
  devices.emplace_back(std::make_unique<Device>(4,"Sensor",Status::ACTIVE));
  devices.emplace_back(std::make_unique<Device>(5,"ECU",Status::INACTIVE));
  return devices;
}

// function to search particular device from vector of devices
Device* searchDevice(std::vector<std::unique_ptr<Device>>& devices, const std::string& name){
  for(auto &device: devices){
    if(device->getName() == name){
      return device.get();
    }
  }
  return nullptr;
}
