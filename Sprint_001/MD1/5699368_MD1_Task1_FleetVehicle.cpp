
// FleetVehicle cpp file

#include<iostream>
#include<string>
#include"5699368_MD1_Task1_FleetVehicle.h"

// default contructor
FleetVehicle::FleetVehicle(){
    m_vehicleID = 0;
    m_fuelLevel = 50.0;
    m_distanceTravelled = 0.0;
    m_status = 'A';
    m_isAvailable = true;
    m_driverName = "Unassigned";
}

// Parameterized contructor
FleetVehicle::FleetVehicle(const int vehicleID_, const float fuelLevel_,const double distanceTravelled_,const char status_,const bool isAvailable_,const std::string driverName_){
    m_vehicleID = vehicleID_;
    m_fuelLevel = fuelLevel_;
    m_distanceTravelled = distanceTravelled_;
    m_status = status_;
    m_isAvailable = isAvailable_;
    m_driverName = driverName_;

    updateStatus(); // In case of inconsistency in status value
}

// destructor
FleetVehicle::~FleetVehicle(){
    std::cout<<"Destructor called for vehicle ID: "<<m_vehicleID<<std::endl;
}


// All getters
int FleetVehicle:: getVehicleID() const { return m_vehicleID; }
float FleetVehicle::getFuelLevel() const { return m_fuelLevel; }
double FleetVehicle::getDistanceTravelled()const { return m_distanceTravelled; }
char FleetVehicle::getStatus()const { return m_status; }
bool FleetVehicle::getIsAvailable()const { return m_isAvailable; }
std::string FleetVehicle::getDriverName()const { return m_driverName; }

// All setters
void FleetVehicle::setVehicleID(int vehicleID_) { m_vehicleID = vehicleID_; }
void FleetVehicle::setFuelLevel(float fuelLevel_){  m_fuelLevel = fuelLevel_; }
void FleetVehicle::setDistanceTravelled(double distanceTravelled_){ m_distanceTravelled = distanceTravelled_;}
void FleetVehicle::setStatus(char status_){ m_status = status_; }
void FleetVehicle::setIsAvailable(bool isAvailable_){m_isAvailable = isAvailable_;}
void FleetVehicle::setDriverName(std::string driverName_){ m_driverName = driverName_;}

// Update Status info
void FleetVehicle::updateStatus(){
    if (m_fuelLevel < 10.0 || !m_isAvailable){
        m_status = 'I';
    }
    else{
        m_status = 'A';
    }
}

// Display information function
void FleetVehicle::displayInfo(){

    std::string is_vehicle_available = (m_isAvailable) ? "Yes" : "No"; // to print the availability of vehicle in readable format
    std::string current_status = (m_status == 'A') ? "Active" : "Inactive"; // to print status in readable format

    std::cout<<"\n * * * * * * * * * * * * * * * * * * * * * * "<<std::endl;
    std::cout<<"Vehicle ID: "<<m_vehicleID<<std::endl;
    std::cout<<"Fuel Level: "<<m_fuelLevel<<std::endl;
    std::cout<<"Distance Travelled: "<<m_distanceTravelled<<std::endl;
    std::cout<<"Status: "<<current_status<<std::endl;
    std::cout<<"Vehicle Availability: "<<is_vehicle_available<<std::endl;
    std::cout<<"Driver Name: "<<m_driverName<<std::endl;
    std::cout<<" * * * * * * * * * * * * * * * * * * * * * * "<<std::endl;
}