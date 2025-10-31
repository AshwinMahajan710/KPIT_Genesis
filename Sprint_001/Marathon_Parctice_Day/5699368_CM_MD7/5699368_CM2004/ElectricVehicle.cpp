#include"ElectricMotor.h"
#include"ElectricVehicle.h"
#include<iostream>
#include<string>
#include<stdexcept>

// default constructor
ElectricVehicle::ElectricVehicle(){
    m_batteryCapacity = 0;
    m_vehicleId = "";
    m_vehicleModel = "";
    m_electricMotor = ElectricMotor();
}

//parameterized constructor
ElectricVehicle::ElectricVehicle(const std::string& vehicleId_, const std::string& vehicleModel_, float batteryCapacity_, ElectricMotor electricMotor_){

    // validating battery capacity
    if(batteryCapacity_<0 || batteryCapacity_ > 80){throw std::invalid_argument("InvalidBatteryCapacityException: \"Battery Capacity can never be negative nor exceed 80\"");}
    else{m_batteryCapacity = batteryCapacity_;}

    // initialize remaining member variables
    m_vehicleId = vehicleId_;
    m_vehicleModel = vehicleModel_;
    m_batteryCapacity = batteryCapacity_;
    m_electricMotor = electricMotor_;
}

// getters
std::string ElectricVehicle:: getVehicleId() const{
    return m_vehicleId;
}
std::string ElectricVehicle:: getVehicleModel() const{
    return m_vehicleModel;
}
float ElectricVehicle::getBatteryCapacity() const{
    return m_batteryCapacity;
}
ElectricMotor ElectricVehicle:: getElectricMotor() const{
    return m_electricMotor;
}

// setters
void ElectricVehicle::getVehicleId(const std::string& vehicleId_){
    this->m_vehicleId = vehicleId_;
}
void ElectricVehicle::getVehicleModel(const std::string& vehicleModel_){
    m_vehicleModel = vehicleModel_;
}
void ElectricVehicle::getBatteryCapacity(float batteryCapacity_){
    if(batteryCapacity_<0 || batteryCapacity_>80){throw std::invalid_argument("InvalidBatteryCapacityException: \"Battery Capacity can never be negative nor exceed 80\"");}
    else{m_batteryCapacity = batteryCapacity_;}
}
void ElectricVehicle::getElectricMotor(ElectricMotor electricMotor_){
    m_electricMotor = electricMotor_;
}

// Overloading << operator to display vehicle details
std::ostream& operator<<(std::ostream& out, const ElectricVehicle& other){
    out<<"Vehicle ID: "<<other.m_vehicleId<<std::endl;
    out<<"Vehicle Model: "<<other.m_vehicleModel<<std::endl;
    out<<"Vehicle Battery Capacity: "<<other.m_batteryCapacity<<std::endl;
    out<<other.m_electricMotor<<std::endl;
    return out;
}

// overloading + operator which will return sum of batterycapacities of 2 vehicles
double ElectricVehicle:: operator +(const ElectricVehicle& other){
    return (this->m_batteryCapacity  +  other.m_batteryCapacity) ; 
}