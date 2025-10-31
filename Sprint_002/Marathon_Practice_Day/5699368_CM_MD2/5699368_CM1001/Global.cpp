#include"Vehicle.h"
#include<iostream>

// function to print info using vehicle pointer
void printVehicleInfo(Vehicle* vehicle){
    if(vehicle!=nullptr){
        std::cout<<vehicle->description()<<std::endl;
    }
    else{
        std::cout<<"No vehicle"<<std::endl;
    }
}