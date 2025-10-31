#include<string>
#include<iostream>
#include"VehicleType.h"
#include"Vehicle.h"

// constructor --> default
Vehicle::Vehicle() : Vehicle("",VehicleType::UNKONWN){};

// Constructor parameterized
Vehicle::Vehicle(const std::string& vin_,VehicleType type_){
    m_vin = vin_;
    m_type = type_;
}

// getters
VehicleType Vehicle::getType() const  noexcept{
    return m_type;
}
const std::string& Vehicle::getVin() const  noexcept{
    return m_vin;
}
