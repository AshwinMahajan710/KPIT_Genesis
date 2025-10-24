#include"ElectricMotor.h"
#include"ElectricVehicle.h"
#include"Functionalities.h"
#include<iostream>
#include<string>
#include<stdexcept>

int main(){


    // TC1 --> Getting input from user about size and creating dynamic array of that size
    int size = 0;
    std::cout<<"Enter the size of array: "<<std::endl;
    std::cin>>size;
    ElectricVehicle* vehicles = new ElectricVehicle[size]; // creating array of dynamic pointers
    int vehiclesCount = 0; // To keep track of the vehicles count inside array

    // TC2 --> Adding the vehicles using addVehicle function
    addVehicle(vehicles,size,vehiclesCount);
    addVehicle(vehicles,size,vehiclesCount);
    std::cout<<"Current vehicles count in memory: "<<vehiclesCount<<std::endl;

    // TC3 --> calculating the sum of battery capacities of two objects input from user
    std::cout<<"\nTotal Battery capacity for two objects is: "<<(vehicles[0]+vehicles[1])<<std::endl;

    // TC4 --> Finding maxtroque for vehicle id "v2"
    try
    {
        std::cout<<"\nMax torque for vehicle id \"v2\" is: "<<findMaxTorque(vehicles,vehiclesCount,"v2");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // TC5 --> Finding maxtroque for vehicle id "v8" --> WILL THROW EXCEPTION
    try
    {
        std::cout<<"\nMax torque for vehicle id \"v8\" is: "<<findMaxTorque(vehicles,vehiclesCount,"v8");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    // TC6 --> Checking for battery discharge percentage
    std::cout<<"\nFollowing are the battery discharge percentage for each Vehicle: "<<std::endl;
    batteryDischargePercentage(vehicles,vehiclesCount);
    
    // Additional --> TC7 --> printing all details
    // for(int i=0;i<vehiclesCount;i++){
        // std::cout<<vehicles[i]<<std::endl;
    // }

    return 0;

}