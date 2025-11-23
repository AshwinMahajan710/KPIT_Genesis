// < = = = = = = = = = =  Global.h  = = = = = = = = = = >
#ifndef GLOBAL_H
#define GLOBAL_H
#include<memory>
#include<vector>
#include"Device.h"
#include"Status.h"

// function to create and return vector of unique_ptr<Device> with smaple data
std::vector<std::unique_ptr<Device>> createDevices();

// function to search particular device from vector of devices
Device* searchDevice(std::vector<std::unique_ptr<Device>>& devices, const std::string& name);

#endif
