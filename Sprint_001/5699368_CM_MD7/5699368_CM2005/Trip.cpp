#include"Ride.h"
#include"Trip.h"
#include<iostream>
#include<stdexcept>
#include<string>

constexpr int MIN_RATING = 1;
constexpr int MAX_RATING = 5;
constexpr int MAX_RIDE = 1;
constexpr int MIN_RIDE = 0;

// constructor --> default values
Trip::Trip() : Trip("",0,1,0) {};

// constructor --> parametrized
Trip::Trip(const std::string& tripId_, int tripDistance_, int tripRating_, int tripVehicleType_){
    
    //validating tripRating
    if(tripRating_<MIN_RATING || tripRating_ > MAX_RATING) {throw std::invalid_argument("InvalidRatingException: \"Rating value can only be in range of 1 - 5\"");}
    else {m_tripRating = tripRating_;}
    
    // validating tripDistance
    if(tripDistance_<0) {throw std::invalid_argument("InvalidDistanceException: \"Distance can never be -ve\"");}
    else {m_tripDistance = tripDistance_;}

    // validating vehicle type
    if(tripVehicleType_>MAX_RIDE || tripVehicleType_< MIN_RIDE) {throw std::invalid_argument("InvalidTripVehicleTypeException: \"Vehicle type can only be in range of 0 - 1\"");}
    else {m_tripVehicleType = static_cast<Ride>(tripVehicleType_);}

    // initializing trip id
    this->m_tripId = tripId_;
}

// getters
std::string Trip::getTripId() const{
    return m_tripId;
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

//setters
void Trip::setTripId(const std::string& tripId_){
    m_tripId = tripId_;  
}
void Trip::setTripDistance(int tripDistance_){
    // validating tripDistance
    if(tripDistance_<0) {throw std::invalid_argument("InvalidDistanceException: \"Distance can never be -ve\"");}
    else {m_tripDistance = tripDistance_;}
}
void Trip::setTripRating(int tripRating_){
    //validating tripRating
    if(tripRating_<MIN_RATING || tripRating_ > MAX_RATING) {throw std::invalid_argument("InvalidRatingException: \"Rating value can only be in range of 1 - 5\"");}
    else {m_tripRating = tripRating_;}
}
void Trip::setTripVehicleType(int tripVehicleType_){
    // validating vehicle type
    if(tripVehicleType_>MAX_RIDE || tripVehicleType_< MIN_RIDE) {throw std::invalid_argument("InvalidTripVehicleTypeException: \"Vehicle type can only be in range of 0 - 1\"");}
    else {m_tripVehicleType = static_cast<Ride>(tripVehicleType_);}
}

// overloading << to display details 
std::ostream& operator<<(std::ostream& out,const Trip& other){
    out<<"Trip ID: "<<other.m_tripId<<std::endl;
    out<<"Trip Distance: "<<other.m_tripDistance<<std::endl;
    out<<"Trip Rating: "<<other.m_tripRating<<std::endl;
    out<<"Trip Ride Type: "<<other.getRideString()<<std::endl;
    return out;
}

// get string value of enum
std::string Trip::getRideString() const{
    if(m_tripVehicleType == Ride::COMFORT) {return "Comfort";}
    else {return "Regular";}
}