#include"VehicleState.h"
#include"Engine.h"
#include<string>
#include"FleetVehicle.h"
#include<vector>
#include"Garage.h"

//  constructor --> parameterized
Garage::Garage(const std::string& location_){
    m_location = location_;
}

// function to add vehicle
void Garage::addVehicle(FleetVehicle&& vehicle){
    m_vehicles.push_back(vehicle);
}

// function to get vehicles count
int Garage::getVehiclesCount() const noexcept{
    return m_vehicles.size();
}