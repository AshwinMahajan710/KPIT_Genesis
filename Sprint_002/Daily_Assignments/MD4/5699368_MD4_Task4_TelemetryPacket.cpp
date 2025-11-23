#include<string>
#include"5699368_MD4_Task4_Level.h"
#include"5699368_MD4_Task4_TelemetryPacket.h"
#include<iostream>

// constructor : member list initialization
TelemetryPacket::TelemetryPacket(int id_, const std::string& tag_, std::uint64_t timestamp_): m_id(id_), m_tag(tag_), m_timeStamp(timestamp_){} 

// move constructor
TelemetryPacket::TelemetryPacket(TelemetryPacket&& other_) noexcept: m_id(other_.m_id), m_level(other_.m_level), m_payloadSize(other_.m_payloadSize), m_pressure(other_.m_pressure), m_tag(std::move(other_.m_tag)), m_temperature(other_.m_temperature), m_timeStamp(other_.m_timeStamp){}

// move assignment 
TelemetryPacket& TelemetryPacket:: operator =(TelemetryPacket&& other_) noexcept{
    if(this!=&other_){
        m_id = other_.m_id;
        m_level = other_.m_level;
        m_payloadSize = other_.m_payloadSize;
        m_pressure = other_.m_pressure;
        m_tag = std::move(other_.m_tag);
        m_temperature = other_.m_temperature;
        m_timeStamp = other_.m_timeStamp;
    }
    return *this;
}

// member functions 
void TelemetryPacket::setReadings(double temp_, double pres_){
    m_temperature = temp_;
    m_pressure = pres_;
}

// setting level
void TelemetryPacket::setLevel(Level&& lvl_){
    m_level = lvl_;
}

// print
void TelemetryPacket::print() const{
    std::cout<<"ID: "<<m_id<<std::endl;
    std::cout<<"Tag: "<<m_tag<<std::endl;
    std::cout<<"Time Stamp: "<<m_timeStamp<<std::endl;
    std::cout<<"Temperature: "<<m_temperature<<std::endl;
    std::cout<<"Pressure: "<<m_pressure<<std::endl;
    std::cout<<"Level: "<<getLevelName()<<std::endl;
    std::cout<<"Payload Size: "<<m_payloadSize<<std::endl;
}

// helper function --> getting level name
std::string TelemetryPacket::getLevelName() const{
    if(m_level == Level::CRITICAL){return "Critical";}
    else if(m_level == Level::OK){return "Ok";}
    else {return "Warn";}

}