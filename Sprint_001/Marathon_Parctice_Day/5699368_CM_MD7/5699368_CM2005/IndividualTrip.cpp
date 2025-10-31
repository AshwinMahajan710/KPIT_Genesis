#include"Trip.h"
#include"Ride.h"
#include"IndividualTrip.h"
#include<stdexcept>
#include<iostream>

// constructors
IndividualTrip::IndividualTrip() : IndividualTrip("",0,0,0, 0){}

// Parameterized constructor
IndividualTrip::IndividualTrip(const std::string& tripId_ ,int tripDistance_, int tripRating_, int tripVehicleType_, int duration_): Trip(tripId_, tripDistance_, tripRating_,tripVehicleType_) {
    
    // duration edge cases handling
    if(duration_ < 0 ) {throw std::invalid_argument("InvalidDurationException: \"Trip Duration can never be -ve\"");}
    else {this->m_individualTripDuration = duration_;}
} 

// getters
int IndividualTrip:: getIndividualTripDuration() const{
    return m_individualTripDuration;
}

// setters
void IndividualTrip::getIndividualTripDuration(int duration_){
        // duration edge cases handling
    if(duration_ < 0 ) {throw std::invalid_argument("InvalidDurationException: \"Trip Duration can never be -ve\"");}
    else {this->m_individualTripDuration = duration_;}
}

// calculating fare
float IndividualTrip::calculateFare()const{
    int factor = (getTripVehicleType() == Ride::REGULAR) ? 25 : 30 ;
    float baseFare = getTripDistance() * factor;
    return baseFare;
}

// checking is Trip as per standards
bool IndividualTrip::isTripAsPerStandard() const{
    if((getTripVehicleType() == Ride::REGULAR) && (getTripRating()>=3) && (m_individualTripDuration)<= (3*getTripDistance())) {return true;}
    else if((getTripVehicleType() == Ride::COMFORT) && (getTripRating()>=4) && (m_individualTripDuration)<= (3*getTripDistance())) {return true;}
    return false;
}

// overloading operator <<
std::ostream& operator <<(std::ostream& out, const IndividualTrip& other){
    out<<"Trip ID: "<<other.getTripId()<<std::endl;
    out<<"Trip Distance: "<<other.getTripDistance()<<std::endl;
    out<<"Trip Rating: "<<other.getTripRating()<<std::endl;
    out<<"Trip Ride Type: "<<other.getRideString()<<std::endl;
    out<<"Individual Trip Duration: "<<other.m_individualTripDuration<<std::endl;
    return out;
}

