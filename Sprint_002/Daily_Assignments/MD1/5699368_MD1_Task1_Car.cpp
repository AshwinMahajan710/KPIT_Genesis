#include<iostream>
#include<string>
#include"5699368_MD1_Task1_Vehicle.h"
#include"5699368_MD1_Task1_Car.h"

// constructor
Car::Car(const std::string& vin_, int year_, int numDoors_): Vehicle(vin_, year_), m_numDoors(numDoors_){} 

// overided function
void Car::runDiagnostics() const {
    std::cout<<"\nRunning Car Diagnostics.."<<std::endl;
}

void Car::displayInfo() const{
    Vehicle::displayInfo();
    std::cout<<"\nNo of doors: "<<m_numDoors<<std::endl;
}