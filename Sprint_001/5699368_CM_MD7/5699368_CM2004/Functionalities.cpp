#include"ElectricMotor.h"
#include"ElectricVehicle.h"
#include<limits>
#include<iostream>
#include<string>
#include<stdexcept>

// Function to add vehicle in array
void addVehicle(ElectricVehicle vehicles_[], int size_, int& count_){
    if(count_ == size_) {throw std::out_of_range("MemoryFullException: \"Memory is full so cannot allocate new obj\"");}
    
    std::string id,model;
    float capacity, power;
    int torque;

    std::cout<<"\nEnter vehicleId, VehicleModel, BatteryCapacity, Max Power and Max Torque one by one: "<<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize> :: max(), '\n'); // to remove any \n characters
    getline(std::cin,id); // get user input for id
    getline(std::cin,model); // get user input for model
    std::cin>> capacity; // get user input for capacity
    std::cin>> power; // get user input for maxPower 
    std::cin>> torque; // get user input for maxTorque 

    // As exceptions are handled can directly create object
    vehicles_[count_++] = ElectricVehicle(id,model,capacity,ElectricMotor(power,torque));
    std::cout<<"Vehicle Added successfully...."<<std::endl;
}

// function to find maxTorque of vehicle wit respective id
double findMaxTorque(ElectricVehicle vehicles_[], const int& count_, const std::string& id_){
    bool isFound = false; // Keeps track of vehicle found or not
    for(int i=0;i<count_;i++){
        if(vehicles_[i].getVehicleId() == id_ && vehicles_[i].getBatteryCapacity()>30.5){
            return vehicles_[i].getElectricMotor().getMaxTorque();
        }
        else if(vehicles_[i].getVehicleId() == id_){
            isFound = true;
        }
    }
    if(isFound) {throw std::invalid_argument("LessBatteryCapacityException: \"Vehicle found but batterycapacity is too less to get maxTorque\"");}
    else {throw std::out_of_range("NoVehicleFoundException: \"Vehicle not found \"");}
}

// function to dispkay battery discharge percentage for each vehicle 
void batteryDischargePercentage(ElectricVehicle vehicles_[], const int& count_){
    for(int i=0;i<count_;i++){
        std::cout<<"Vehicle Id: "<<vehicles_[i].getVehicleId()<<" , Battery Discharge rate: "<<(vehicles_[i].getBatteryCapacity()/10) <<std::endl;
    }
}