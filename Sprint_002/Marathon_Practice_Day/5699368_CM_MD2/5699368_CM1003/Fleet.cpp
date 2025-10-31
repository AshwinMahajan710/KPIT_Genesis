#include"VehicleState.h"
#include"Engine.h"
#include<string>
#include"FleetVehicle.h"
#include<vector>
#include"Garage.h"
#include"Fleet.h"

// function to add garage
void Fleet::addGarage(Garage&& garage_){
    m_garages.push_back(std::move(garage_));
}

// function to calculate total vehicles in all garages
int Fleet::totalVehicles() const noexcept{
    int vehiclesCount = 0;
    for(auto i : m_garages){
        vehiclesCount += i.getVehiclesCount();
    }
    return vehiclesCount;
}
