#include<iostream>
#include<string>
#include<stdexcept>
#include"Vehicle.h"

constexpr double MAX_FUEL_CAPACITY = 60.0;

// constructor --> default
Vehicle::Vehicle() : Vehicle(0,"","",0.0,0.0,false){};

// constructor --> parameterized
Vehicle::Vehicle(int vehicleId_, const std::string& manufacturer_, const std::string& model_, double fuelLevel_,double odometer_, bool isAvailable_){
    // first validate fuelLevel and only after that do the assignment
    if(fuelLevel_ <0 || fuelLevel_ > MAX_FUEL_CAPACITY) {throw std::invalid_argument("InvalidFuelLevelException: Fuel level should be in range of 0 - 60");}
    else {m_fuelLevel = fuelLevel_;}

    // now remaining assignments
    m_vehicleId = vehicleId_;
    m_manufacturer = manufacturer_;
    m_model = model_;
    m_odometer = odometer_;
    m_isAvailable = isAvailable_;
}

// getters
int Vehicle::getVehicleId() const{
    return m_vehicleId;
}
std::string Vehicle::getManufacturer() const{
    return m_manufacturer;
}
std::string Vehicle::getModel() const{
    return m_model;
}
double Vehicle::getFuelLevel() const{
    return m_fuelLevel;
}
double Vehicle::getOdometer() const{
    return m_odometer;
}
bool Vehicle::getIsAvailable() const{
    return m_isAvailable;
}

// setters
void Vehicle::setVehicleId(int vehicleId_) {
    m_vehicleId = vehicleId_;
}
void Vehicle::setManufacturer(const std::string& manufacturer_) {
    m_manufacturer = manufacturer_;
}
void Vehicle::setModel(const std::string& model_) {
    m_model = model_;
}
void Vehicle::setFuelLevel(double fuelLevel_) {
    if(fuelLevel_ <0 || fuelLevel_ > MAX_FUEL_CAPACITY) {throw std::invalid_argument("InvalidFuelLevelException: Fuel level should be in range of 0 - 60");}
    else {m_fuelLevel = fuelLevel_;}
}
void Vehicle::setOdometer(double odometer_) {
    m_odometer = odometer_;
}
void Vehicle::setIsAvailable(bool isAvailable_){
    m_isAvailable = isAvailable_;
}

// drive(double distance) --> Increases odometer by distance and decreases fuelLevel by considering fuel consumption as 15 km/liter
void Vehicle::drive(double distance_){

    // handle condition of -ve distance
    if(distance_ < 0) {throw std::invalid_argument("InvalidDistanceValueException: Distance can never be -ve");}

    // calculating the fuel consumption
    double fuelComsumption = distance_ / 15.0;
    if((m_fuelLevel - fuelComsumption)<0) {throw std::invalid_argument("InvalidDistanceException: Vehicle not able to cover that much distance as fuel level is too low");}

    // else --> do the assignment as there is enogh fuel to cover the distance
    m_odometer += distance_;
    m_fuelLevel -= fuelComsumption;
}

// refuel(double liters) --> Adds fuel without exceeding tank capacity (60 liters)
void Vehicle::refuel(double liters_){

    // handle the condition of -ve fuel
    if(liters_ < 0) {throw std::invalid_argument("InvalidRefuleValueException: Vehicle Refule value can never be -ve");}

    // new fuel value
    double newFuelLevel = m_fuelLevel + liters_;
    m_fuelLevel = (newFuelLevel<MAX_FUEL_CAPACITY) ? newFuelLevel : 60.0 ; // as max capacity is 60.0
}

// displayInfo() --> Displays all vehicle information
void Vehicle::displayInfo() const{
    std::cout<<"Vehicle ID: "<<m_vehicleId<<std::endl;
    std::cout<<"Vehicle Manufacturer: "<<m_manufacturer<<std::endl;
    std::cout<<"Vehicle Model: "<<m_model<<std::endl;
    std::cout<<"Vehicle Fuel Level: "<<m_fuelLevel<<std::endl;
    std::cout<<"Vehicle Odometer: "<<m_odometer<<std::endl;
    std::cout<<"Vehicle Availability: "<<((m_isAvailable) ? "Yes":"NO")<<std::endl;
}