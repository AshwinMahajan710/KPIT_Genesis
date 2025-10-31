#include<iostream>
#include<string>
#include"5699368_MD1_Task3_Vehicle.h"

// constructor -->default
Vehicle::Vehicle(): Vehicle("Generic", 2020){};

// constructors --> parameterized
Vehicle::Vehicle(const std::string& vin_, int year_){
    m_vin = vin_;
    m_year = year_;
}

// function to display info
void Vehicle::show() const{
    std::cout<<"\nVIN: "<<m_vin<<std::endl;
    std::cout<<"\nYear: "<<m_year<<std::endl;
}
