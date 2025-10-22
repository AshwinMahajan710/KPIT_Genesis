#include"Ride.h"
#include"Trip.h"
#include<stdexcept>
#include<string>
#include<iostream>

// default consutructor
Trip::Trip() : Trip("","",0,0,Ride::REGULAR) {}

// Parameterized constructor
Trip::Trip(const std::string& tripId_, const std::string& tripDriver_, int tripDistance_, int tripRating_, Ride tripVehicleType_) : m_tripDriver(tripDriver_), m_tripId(tripId_), m_tripVehicleType(tripVehicleType_) {
    
    // checkning edge cases for distance
    if(tripDistance_ < 0 ) {throw std::invalid_argument("Exception: \"Trip Distance can never be -ve\"");}
    else {this->m_tripDistance = tripDistance_;}

    // checking edge values for rating
    if(tripRating_ >=1 && tripRating_<=5) {this->m_tripRating = tripRating_;}
    else {throw std::invalid_argument("Exception: \"Rating should be in range of 1 - 5\"");}
}

//getters
std::string Trip::getTripID() const{
    return m_tripId;
}
std::string Trip::getTripDriver() const{
    return m_tripDriver;
}
int Trip::getTripDistance() const{
    return m_tripDistance;
}
int Trip::getTripRating() const{
    return m_tripRating;
}
Ride Trip::getTripVehicleType() const{
    return m_tripVehicleType;
}

// Setters
void Trip::setTripID(const std::string& id_){
    this->m_tripId = id_;
}
void Trip::setTripDriver(const std::string& driver_){
    this->m_tripDriver = driver_;
}
void Trip::setTripDistance(int distance_){
    if(distance_ < 0 ) {throw std::invalid_argument("Exception: \"Trip Distance can never be -ve\"");}
    else {this->m_tripDistance = distance_;}
}
void Trip::setTripRating(int rating_){
    if(rating_ >=1 && rating_<=5) {this->m_tripRating = rating_;}
    else {throw std::invalid_argument("Exception: \"Rating should be in range of 1 - 5\"");}
}
void Trip::setTripVehicleType(Ride type_){
    this->m_tripVehicleType = type_;
}

// Helper function
void Trip::printDetails() const{
    std::cout<<"Trip ID: "<<m_tripId<<std::endl;
    std::cout<<"Driver Name: "<<m_tripDriver<<std::endl;
    std::cout<<"Trip Distance: "<<m_tripDistance<<std::endl;
    std::cout<<"Trip Rating: "<<m_tripRating<<std::endl;
    std::cout<<"Trip Type: "<<getTripTypeName()<<std::endl;
}   

// getting Ride as string
std::string Trip::getTripTypeName() const{
    if(m_tripVehicleType == Ride::REGULAR) {return "Regular";}
    else {return "Premium";}
}