#include<iostream>
#include<string>
#include<stdexcept>
#include"Vehicle.h"

// initializing the static variable
double Vehicle::s_averageFuelPrice = 0.0;

int main(){
    
    // TC1 --> Create the obj for vehicle
    Vehicle vehicle("V123", "Gasoline", 25.0);

    // TC2 --> Tracking fuel consumption
    vehicle.trackFuelConsumption(10.0, 250.0);

    // TC3 --> Calculate the fuel economy
    std::cout<<"\nVehicle's current fuel economy: "<<vehicle.calculateFuelEconomy()<<std::endl;

    // TC4 --> updating average fuel price 
    vehicle.updateAverageFuelPrice(2.75);

    // TC5 --> calculating total cost
    std::cout<<"\nTotal fuel cost: "<<vehicle.calculateTotalFuelCost(500)<<"$.."<<std::endl;

    // TC6 --> displaying all details
    std::cout<<"\nAll details of vehicle: ";
    vehicle.displayVehicleInfo();

    return 0;
}