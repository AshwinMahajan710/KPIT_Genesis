#include<iostream>
#include<string>
#include"5699368_MD1_Task1_Vehicle.h"

// constructors --> parameterized
Vehicle::Vehicle(const std::string& vin_, int year_){
    m_vin = vin_;
    m_year = year_;
}

// function to display info
void Vehicle::displayInfo() const{
    std::cout<<"\nVIN: "<<m_vin<<std::endl;
    std::cout<<"\nYear: "<<m_year<<std::endl;
}

void Vehicle::runDiagnostics() const{
    std::cout<<"\nRunning generic diagnostics.."<<std::endl;
}