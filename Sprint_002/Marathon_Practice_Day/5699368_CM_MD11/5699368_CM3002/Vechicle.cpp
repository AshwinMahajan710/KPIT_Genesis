#include<string>
#include"VEHICLE_TYPE.h"
#include"TRANSMISSION_TYPE.h"
#include"FUEL_TYPE.h"
#include"Vehicle.h"
#include<iostream>

// constructor --> parameterized
Vehicle::Vehicle(const std::string& make_, const std::string& model_, int year_, VEHICLE_TYPE type_, FUEL_TYPE fuelType_, TRANSMISSION_TYPE transmissionType_, float price_): m_make(make_), m_model(model_), m_year(year_), m_type(type_), m_fuelType(fuelType_), m_transmissionType(transmissionType_), m_purchasePrice(price_) {};

// getters
std::string Vehicle::getMake() const{
    return m_make;
}

std::string Vehicle::getModel() const{
    return m_model;
}

int Vehicle::getYear() const{
    return m_year;
}
VEHICLE_TYPE Vehicle::getType () const{
    return m_type;
}
FUEL_TYPE Vehicle::getFuelType() const{
    return m_fuelType;
}
TRANSMISSION_TYPE Vehicle::geTransmissionType() const{
    return m_transmissionType;
}
float Vehicle::getPurchasePrice() const{
    return m_purchasePrice;
}

// setters
void Vehicle::setMake(const std::string& make_) {
    m_make = make_;
}
void Vehicle::setModel(const std::string& model_) {
    m_model = model_;
}
void Vehicle::setYear(int year_) {
    m_year = year_;
}
void Vehicle::setType (VEHICLE_TYPE type_) {
    m_type = type_;
}
void Vehicle::setFuelType(FUEL_TYPE fuelType_) {
    m_fuelType = fuelType_;
}
void Vehicle::seTransmissionType(TRANSMISSION_TYPE transmissionType_) {
    m_transmissionType = transmissionType_;
}
void Vehicle::setPurchasePrice(float price_){
    m_purchasePrice = price_;
}

// helper --> het vehicleType string
std::string Vehicle::getVehicleTypeName() const{
    if(m_type == VEHICLE_TYPE::SEDAN){return "Sedan";}
    else if(m_type == VEHICLE_TYPE::SUV){return "SUV";}
    else{return "Truck";}
}

// helper --> het fuelType string
std::string Vehicle::getFuelTypeName() const{
    if(m_fuelType==FUEL_TYPE::DIESEL){return "Diesel";}
    if(m_fuelType==FUEL_TYPE::ELECTRIC){return "Electric";}
    else{return "Gasoline";} 
}
// helper --> het transmissionType string
std::string Vehicle::getTransmissionTypeString() const{
    if(m_transmissionType == TRANSMISSION_TYPE::AUTOMATIC){return "Automatic";}
    else{return "Manual";}
}

// function to display details of vehicle
void Vehicle::display() const{
    std::cout<<"\nMake: "<<m_make<<std::endl;
    std::cout<<"Model: "<<m_model<<std::endl;
    std::cout<<"Year: "<<m_year<<std::endl;
    std::cout<<"Vehicle Type Name: "<<getVehicleTypeName()<<std::endl;
    std::cout<<"Transmission Type: "<<getTransmissionTypeString()<<std::endl;
    std::cout<<"Fuel Type: "<< getFuelTypeName()<<std::endl;
    std::cout<<"Base Price: "<<m_purchasePrice<<std::endl;
}