#include<iostream>
#include<string>
#include<stdexcept>
#include"Vehicle.h"

// defaut constructor
Vehicle::Vehicle() : Vehicle("", "",0){}

// Parametrized constructor
Vehicle::Vehicle(const std::string& vehicleID_, const std::string& fuelType_, double fuelEfficiency_){
    
    // Initializing member variables  
    this->m_vehicleID = vehicleID_;
    this->m_fuelType = fuelType_;
    this->m_totalDistanceTravelled = 0;
    this->m_totalFuelConsumed= 0;

    // Validate for fuelEfficiency
    if(fuelEfficiency_ < 0) {throw std::invalid_argument("InvalidFuelException: \"Fuel Efficiency can never be -ve\"");}
    else {this->m_fuelEfficiency = fuelEfficiency_;}
}

// function to track fuel consumption
void Vehicle::trackFuelConsumption(double fuelConsumed_, double distanceTravelled_){
    if(fuelConsumed_<0 || distanceTravelled_< 0) {throw std::invalid_argument("InvalidDistanceOrFuelException: \"Either of distance travelled or fuel consumption value is invalid..\"");}
    else{
        this->m_totalDistanceTravelled += distanceTravelled_;
        this->m_totalFuelConsumed += fuelConsumed_;
    }

    // update fuelEfficiency also
    this->m_fuelEfficiency = calculateFuelEconomy();
}

// function to track fuel economy
double Vehicle::calculateFuelEconomy() const{
    if(m_totalFuelConsumed == 0) {throw std::invalid_argument("InvalidEfficiencyException: \"As TotalFuelConsumed is 0 .. cannot calculate new FuelEfficiency..\"");}
    else {
        return (this->m_totalDistanceTravelled/ this->m_totalFuelConsumed); // basically mileage per litre
    }
}

// function to display vehicle details
void Vehicle::displayVehicleInfo() const{
    std::cout<<"\nVehicle ID: "<<this->m_vehicleID<<std::endl;
    std::cout<<"Vehicle Fuel Type: "<<this->m_fuelType<<std::endl;
    std::cout<<"Vehicle Fuel Efficiency: "<<this->m_fuelEfficiency<<std::endl;
    std::cout<<"Total Distance Travelled: "<<this->m_totalDistanceTravelled<<std::endl; 
}

// function to update average fuel Price --> with new price
void Vehicle::updateAverageFuelPrice(double newPrice_){
    s_averageFuelPrice = newPrice_;
}

// function to update average fuel Price --> with default value
void Vehicle::updateAverageFuelPrice(){
    s_averageFuelPrice += (s_averageFuelPrice)*0.10;
}

// function to calculate total fuel cost
double Vehicle::calculateTotalFuelCost(double distanceToTravel_) const{
    return ((distanceToTravel_ / m_fuelEfficiency) * s_averageFuelPrice);
}