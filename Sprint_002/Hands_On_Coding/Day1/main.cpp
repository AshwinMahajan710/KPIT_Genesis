// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// main.cpp

#include <string>
#include<vector>
#include<memory>
#include<functional>
#include"SmartDevice.h"
#include"Light.h"
#include"Thermostat.h"
#include"SmartHomeController.h"
#include<iostream>

int main(){
  	
  	// creating object of smarthome controller
  	SmartHomeController controller;
  	
  	// adding one light and thermostat
  	std::unique_ptr<Light> light1 = std::make_unique<Light>("LED",98);
  	std::unique_ptr<Thermostat> thermostat1 = std::make_unique<Thermostat>("Coil",101.1);
  	
  	// creating custom callbacks
  	auto lambda1 = [](){std::cout<<"[LOG] Light activation logged"<<std::endl;};
  	auto lambda2 = [](){std::cout<<"[ALERT] Thermostat adjusted"<<std::endl;};
  	
  	// adding to controller
  	controller.addDevice(std::move(light1), lambda1);
  	controller.addDevice(std::move(thermostat1), lambda2);
  	
  	// activating all
  	controller.activateAll();
  
  	return 0;
}