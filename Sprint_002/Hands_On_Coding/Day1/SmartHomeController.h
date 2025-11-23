// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// SmartHomeController.h

#ifndef SMARTHOMECONTROLLER_H	//SMARTHOMECONTROLLER_H
#define SMARTHOMECONTROLLER_H

#include <string>
#include<vector>
#include<memory>
#include<functional>
#include"SmartDevice.h"
#include"Light.h"
#include"Thermostat.h"

class SmartHomeController{
  	private:
  		std::vector<std::unique_ptr<SmartDevice>> devices;
  		std::vector<std::function<void()>> callbacks;
  	public:
        SmartHomeController() = default;
  		
  		// for adding device and callback
  		void addDevice(std::unique_ptr<SmartDevice> device, std::function<void()> onActivate);
  		
  		SmartHomeController(SmartHomeController&&) = default; // defaulted move constructor
        SmartHomeController& operator = (SmartHomeController&&) = default; // defaulted move assignment
        SmartHomeController(const SmartHomeController&) = delete; // deleted copy constructor
        SmartHomeController& operator = (const SmartHomeController&) = delete; // deleted copy assignment operator
        
  		// activating devices
  		void activateAll();
};	

#endif