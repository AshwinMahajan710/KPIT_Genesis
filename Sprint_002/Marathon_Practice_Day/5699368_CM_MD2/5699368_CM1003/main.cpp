#include"VehicleState.h"
#include"Engine.h"
#include<string>
#include"FleetVehicle.h"
#include<vector>
#include"Garage.h"
#include"Fleet.h"
#include<iostream>

int  main(){

    // creating objects 
    Garage garage("plant A");
    FleetVehicle vehicle("F123",150);
    garage.addVehicle(std::move(vehicle));
    
    // creating fleet and adding garage
    Fleet fleet;
    fleet.addGarage(std::move(garage));

    // TC1 
    std::cout<<"\nTotal vehicles are: "<<fleet.totalVehicles()<<std::endl;

    // TC2
    std::cout<<vehicle.display()<<std::endl;
    
    // TC3 
    vehicle.setState(VehicleState::INTRANSIT);
    std::cout<<vehicle.display()<<std::endl;
    

    return 0;
}