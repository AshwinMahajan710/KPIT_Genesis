#include<iostream>
#include<string>
#include"5699368_MD1_Task1_Vehicle.h"
#include"5699368_MD1_Task1_ElectricCar.h"

// constructor
ElectricCar::ElectricCar(const std::string& vin_, int year_, int batterHealth_): Vehicle(vin_, year_), m_batteryHealth(batterHealth_){} 

// overided function
void ElectricCar::runDiagnostics() const {
    std::cout<<"\nRunning ElectricCar Diagnostics.."<<std::endl;
}

void ElectricCar::displayInfo() const{
    Vehicle::displayInfo();
    std::cout<<"\nBattery Health: "<<m_batteryHealth<<std::endl;
}