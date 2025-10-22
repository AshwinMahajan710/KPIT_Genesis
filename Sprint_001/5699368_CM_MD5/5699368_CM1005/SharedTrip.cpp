#include"Ride.h"
#include"Trip.h"
#include"SharedTrip.h"
#include<stdexcept>
#include<string>
#include<iostream>

// constructors
SharedTrip::SharedTrip() : SharedTrip("","",0,0,Ride::REGULAR, 0){};

// Paremetrized constructor
SharedTrip::SharedTrip(const std::string& tripId_, const std::string& tripDriver_, int tripDistance_, int tripRating_, Ride tripVehicleType_, int sharedPassesngers_): Trip(tripId_, tripDriver_, tripDistance_, tripRating_, tripVehicleType_){
    if(sharedPassesngers_ < 0) {throw std::invalid_argument("Exception: \"Shared passenger number can never be -ve\"");}
    else {m_sharedTripPassengers = sharedPassesngers_;}
}

// Getters
int SharedTrip::getSharedTripPassengers() const{
    return m_sharedTripPassengers;
}

//setters
void SharedTrip::setSharedTripPassengers(int passengers_) {
    if(passengers_ < 0) {throw std::invalid_argument("Exception: \"Shared passenger number can never be -ve\"");}
    else {m_sharedTripPassengers = passengers_;}
}

// calculate fare 
float SharedTrip::calculateFare() const {
    int factor = (getTripVehicleType() == Ride::REGULAR) ? 25 : 50;
    int passengerFactor = (getTripVehicleType() == Ride::REGULAR) ? 5 : 20;
    float baseFare = getTripDistance() * factor;
    float sharedCost = m_sharedTripPassengers * passengerFactor;
    float tax = (18*(baseFare+sharedCost))/100.0;
    return (sharedCost + baseFare + tax);
}

// checking is trip as per standard
bool SharedTrip::isTripAsPerStandard() const{
    if((getTripVehicleType() == Ride::REGULAR) && (getTripRating()>=3) ) {return true;}
    else if((getTripVehicleType() == Ride::PREMIUM) && (getTripRating()>=4)) {return true;}
    return false;
}

// overrided function
void SharedTrip::printDetails() const{
    Trip::printDetails();
    std::cout<<"Shared Passengers in trip: "<<m_sharedTripPassengers<<std::endl;
}