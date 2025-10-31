#include"Global.h"
#include"Vehicle.h"
#include<iostream>
#include<string>

// finding vehicle having higher mileage
void compareOdometer(Vehicle v1, Vehicle v2){
    if(v1.getOdometer() > v2.getOdometer()){
        std::cout<<"\nVehicle 1 has higher mileage..."<<std::endl;
    }
    else{
        std::cout<<"\nVehicle 2 has higher mileage..."<<std::endl;
    }
}