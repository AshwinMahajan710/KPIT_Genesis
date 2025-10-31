#include<iostream>
#include<string>
#include"5699368_MD1_Task1_Vehicle.h"
#include"5699368_MD1_Task1_Truck.h"

// constructor
Truck::Truck(const std::string& vin_, int year_, double payloadCapacity_): Vehicle(vin_, year_), m_payloadCapacity(payloadCapacity_){} 

// overided function
void Truck::runDiagnostics() const {
    std::cout<<"\nRunning Truck Diagnostics.."<<std::endl;
}

void Truck::displayInfo() const{
    Vehicle::displayInfo();
    std::cout<<"\nPayload Capacity: "<<m_payloadCapacity<<std::endl;
}