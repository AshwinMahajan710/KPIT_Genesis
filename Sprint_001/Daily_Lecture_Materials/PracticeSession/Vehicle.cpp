#include<iostream>
#include<string>
#include"VehicleType.h"
#include"Vehicle.h"

// Constructors
Vehicle::Vehicle() : Vehicle(0,false,0,VehicleType::CAR){};
Vehicle::Vehicle(int id_, bool isElectric_, double mileage_, VehicleType vehicleType_): m_id(id_), m_isElectric(isElectric_),m_mileage(mileage_),m_vehicleType(vehicleType_) {}
Vehicle::Vehicle(const Vehicle& other):Vehicle(other.m_id, other.m_isElectric, other.m_mileage, other.m_vehicleType) {}

// All getters
int Vehicle::getId() const{
    return m_id;
}

bool Vehicle::getIsElectric() const{
    return m_isElectric;
}
double Vehicle::getMileage() const{
    return m_mileage;
}
VehicleType Vehicle::getVehicleType() const{
    return m_vehicleType;
}

// setters --> pending
void Vehicle::setID(int id_){
    this->m_id = id_;
}
void Vehicle::setIsElectric( bool isElectric_){
    this->m_isElectric = isElectric_;
}
void Vehicle::setMileage(double mileage_) {
    this->m_mileage = mileage_;
}
void Vehicle::setVehicleType(VehicleType type_){
    this->m_vehicleType = type_;
}

// overloading operator +
Vehicle Vehicle::operator+ (const Vehicle& other){
    Vehicle tempVehicle;
    tempVehicle.setID(this->m_id);
    tempVehicle.setIsElectric(this->m_isElectric);
    tempVehicle.setVehicleType(this->m_vehicleType);
    tempVehicle.setMileage(this->m_mileage + other.m_mileage);
    return tempVehicle;
} 

// operator overloading of <<
std::ostream& operator<<(std::ostream& out, const Vehicle& other){
    out<<"Vehicle ID: "<<other.m_id<<std::endl;
    out<<"Is Vehicle Electric: "<<(other.m_isElectric ? "YES":"NO")<<std::endl;
    out<<"Vehicle Mileage: "<<other.m_mileage<<std::endl;
    out<<"Vehicle Type: "<<other.getStringVehicleType()<<std::endl;
}

// getting string representation to print vehicle type
std::string Vehicle::getStringVehicleType() const{ 
    switch (this->m_vehicleType)
    {
        case VehicleType::CAR:{
            return "Car";
            break;
        }
        case VehicleType::TRUCK:{
            return "Truck";
            break;
        }
        case VehicleType::MOTORCYCLE:{
            return "MotorCycle";
            break;
        }
        default:{
            return "Unknown";
            break;
        }
    }
}