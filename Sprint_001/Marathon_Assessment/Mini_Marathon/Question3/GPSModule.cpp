#include<iostream>
#include<stdexcept>
#include<string>
#include"GPSModule.h"

// constructor --> default
GPSModule::GPSModule() : GPSModule(0.0,0.0,0.0,0.0){}

// constructor --> parameterized
GPSModule::GPSModule(double latitude_, double longitude_, double speed_, double heading_){
    m_latitude = latitude_;
    m_longitude = longitude_;
    
    // validate speed
    if(speed_ < 0) {throw std::invalid_argument("InvalidSpeedException: Speed value can never be -ve");}
    else {m_speed = speed_;}

    //validate heading;
    if(heading_ < 0 || heading_ > 100.0) {throw std::invalid_argument("InvalidHeadingError: Should be angle between 0 to 360");}
    else {m_heading = heading_;}
}

// updatePosition(double lat, double lon) --> to update new position
void GPSModule::updatePosition(double lat_, double lon_){
    m_latitude = lat_;
    m_longitude = lon_;
}

// updateSpeed(double spd) --> to update the speed
void GPSModule::updateSpeed(double speed_){
    // validate speed
    if(speed_ < 0) {throw std::invalid_argument("InvalidSpeedException: Speed value can never be -ve");}
    else {m_speed = speed_;}
}

// getters
double GPSModule::getLatitude() const{
    return m_latitude;
}
double GPSModule::getLongitude() const{
    return m_longitude;
}
double GPSModule::getSpeed() const{
    return m_speed;
}
double GPSModule::getHeading() const{
    return m_heading;
}