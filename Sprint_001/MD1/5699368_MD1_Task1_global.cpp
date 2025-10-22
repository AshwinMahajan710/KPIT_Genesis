
// Global function cpp file

#include"5699368_MD1_Task1_FleetVehicle.h"
#include"5699368_MD1_Task1_global.h"
#include<iostream>
#include<string>

// Asssign new driver 
void assignDriver(FleetVehicle& vehicle_, std::string name_){
    std::cout<<"Previous Driver: "<<vehicle_.getDriverName()<<std::endl;
    vehicle_.setDriverName(name_);
    std::cout<<"New Driver: "<<vehicle_.getDriverName()<<std::endl;
}

// Refule the vehicle
void refuelVehicle(FleetVehicle& vehicle_, float fuelAmmount_){
    if(fuelAmmount_ <=0 ) {throw std::invalid_argument("ERROR:: Refule value can never be negative or zero.....");}
    else {vehicle_.setFuelLevel(vehicle_.getFuelLevel() + fuelAmmount_); } // get old fuel ammount and add new fuel ammount in it 
}