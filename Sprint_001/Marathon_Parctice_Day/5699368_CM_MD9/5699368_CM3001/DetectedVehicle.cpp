#include"DetectedVehicle.h"
#include<iostream>
#include<stdexcept>
#include<string>

// constructor --> default
DetectedVehicle::DetectedVehicle(){
    m_id = -1;
    m_distanceMeters = 0.0F;
    m_relativeSpeedMps = 0.0F;
    m_isBreaking = false;
}

// constructor --> parametrized
DetectedVehicle::DetectedVehicle(int id_, float distanceMeters_, float relativeSpeed_, bool isBreaking_){
    
    // validate ID
    if(id_ < 0) {throw std::invalid_argument("InvalidIDException: Id can never be -ve..");}
    else {m_id = id_;}

    // distance  if -ve cap to 0;
    m_distanceMeters = (distanceMeters_ < 0) ? 0.0 : distanceMeters_;
    m_relativeSpeedMps = relativeSpeed_;

    m_isBreaking = isBreaking_;
}

// all getters
int DetectedVehicle::getId() const{
    return m_id;
}
float DetectedVehicle::getDistanceMeters() const{
    return m_distanceMeters;
}
float DetectedVehicle::getRelativeSpeedMps() const{
    return m_relativeSpeedMps;
}
bool DetectedVehicle::getIsBreaking() const{
    return m_isBreaking;
}

// All setters
void DetectedVehicle::setId(int id_){ // should not accept non-negative values : exception
       // validate ID
    if(id_ < 0) {throw std::invalid_argument("InvalidIDException: Id can never be -ve..");}
    else {m_id = id_;}

} 
void DetectedVehicle::setDistanceMeters(float distanceMeters_){ // if negative set to 0.0 : cap
     m_distanceMeters = (distanceMeters_ < 0) ? 0.0 : distanceMeters_;
} 

void DetectedVehicle::setRelativeSpeedMps(float relativeSpeed_){// if negative set to 0.0 : cap
    m_relativeSpeedMps = relativeSpeed_;
}
void DetectedVehicle::setIsBreaking(bool isBreaking_) {
    m_isBreaking = isBreaking_;
}