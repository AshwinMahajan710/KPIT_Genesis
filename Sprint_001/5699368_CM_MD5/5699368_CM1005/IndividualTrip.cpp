#include"Trip.h"
#include"Ride.h"
#include"IndividualTrip.h"
#include<stdexcept>
#include<iostream>

// constructors
IndividualTrip::IndividualTrip() : IndividualTrip("","",0,0,Ride::REGULAR, 0){}

// Parameterized constructor
IndividualTrip::IndividualTrip(const std::string& tripId_, const std::string& tripDriver_, int tripDistance_, int tripRating_, Ride tripVehicleType_, int duration_): Trip(tripId_, tripDriver_, tripDistance_, tripRating_,tripVehicleType_) {
    
    // duration edge cases handling
    if(duration_ < 0 ) {throw std::invalid_argument("Exception: \"Trip Duration can never be -ve\"");}
    else {this->m_individualTripDuration = duration_;}
} 

// getters
int IndividualTrip:: getIndividualTripDuration() const{
    return m_individualTripDuration;
}

// setters
void IndividualTrip::getIndividualTripDuration(int duration_){
        // duration edge cases handling
    if(duration_ < 0 ) {throw std::invalid_argument("Exception: \"Trip Duration can never be -ve\"");}
    else {this->m_individualTripDuration = duration_;}
}

// calculating fare
float IndividualTrip::calculateFare()const{
    int factor = (getTripVehicleType() == Ride::REGULAR) ? 25 : 50 ;
    float baseFare = getTripDistance() * factor;
    float tax = (18*baseFare)/100;
    return (baseFare + tax);  
}

// fare with surcharge
float IndividualTrip::calculateFare(float surcharge_) const{
    int factor = (getTripVehicleType() == Ride::REGULAR) ? 25 : 50 ;
    float baseFare = getTripDistance() * factor;
    float totalBaseFare = baseFare + (surcharge_*this->m_individualTripDuration);
    float tax = (18*totalBaseFare)/100;
    return (totalBaseFare + tax);
} 

// checking is Trip as per standards
bool IndividualTrip::isTripAsPerStandard() const{
    if((getTripVehicleType() == Ride::REGULAR) && (getTripRating()>=3) && (m_individualTripDuration)<= (3*getTripDistance())) {return true;}
    else if((getTripVehicleType() == Ride::PREMIUM) && (getTripRating()>=4) && (m_individualTripDuration)<= (4*getTripDistance())) {return true;}
    return false;
}

// overrided function
void IndividualTrip::printDetails() const{
    Trip::printDetails();
    std::cout<<"Individual trip duration: "<<m_individualTripDuration<<std::endl;
}