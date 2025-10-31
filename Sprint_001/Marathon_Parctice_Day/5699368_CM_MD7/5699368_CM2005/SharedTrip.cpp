#include"Ride.h"
#include"Trip.h"
#include"SharedTrip.h"
#include<stdexcept>
#include<string>
#include<iostream>

// constructors
SharedTrip::SharedTrip() : SharedTrip("",0,0,0, 0){};

// Paremetrized constructor
SharedTrip::SharedTrip(const std::string& tripId_, int tripDistance_, int tripRating_,int tripVehicleType_, int sharedPassesngers_): Trip(tripId_,  tripDistance_, tripRating_, tripVehicleType_){
    if(sharedPassesngers_ < 0) {throw std::invalid_argument("InvalidPassengersException: \"Shared passenger number can never be -ve\"");}
    else {m_sharedTripPassengers = sharedPassesngers_;}
}

// Getters
int SharedTrip::getSharedTripPassengers() const{
    return m_sharedTripPassengers;
}

//setters
void SharedTrip::setSharedTripPassengers(int passengers_) {
    if(passengers_ < 0) {throw std::invalid_argument("InvalidPassengersException: \"Shared passenger number can never be -ve\"");}
    else {m_sharedTripPassengers = passengers_;}
}

// calculate fare 
float SharedTrip::calculateFare() const {
    int factor = (getTripVehicleType() == Ride::REGULAR) ? 25 : 30;
    int passengerFactor = (getTripVehicleType() == Ride::REGULAR) ? 5 : 10;
    float baseFare = getTripDistance() * factor;
    float sharedCost = m_sharedTripPassengers * passengerFactor;
    return (baseFare + sharedCost);
}

// checking is trip as per standard
bool SharedTrip::isTripAsPerStandard() const{
    if((getTripVehicleType() == Ride::REGULAR) && (getTripRating()>=3) ) {return true;}
    else if((getTripVehicleType() == Ride::COMFORT) && (getTripRating()>=4)) {return true;}
    return false;
}

// overloading operator <<
std::ostream& operator <<(std::ostream& out, const SharedTrip& other){
    out<<"Trip ID: "<<other.getTripId()<<std::endl;
    out<<"Trip Distance: "<<other.getTripDistance()<<std::endl;
    out<<"Trip Rating: "<<other.getTripRating()<<std::endl;
    out<<"Trip Ride Type: "<<other.getRideString()<<std::endl;
    out<<"No of shared trip passengers: "<<other.m_sharedTripPassengers<<std::endl;
    return out;
}
