#include"ElectricMotor.h"
#include"ElectricVehicle.h"
#include<iostream>
#include<string>
#include<stdexcept>

// funtion to add vehicle in array
void addVehicle(ElectricVehicle vehicles_[], int size_, int& count_);

// function to find maxTorque of vehicle wit respective id
double findMaxTorque(ElectricVehicle vehicles_[], const int& count_, const std::string& id_);

void batteryDischargePercentage(ElectricVehicle vehicles_[], const int& count_);