#include"5699368_MD4_Task3_SignalBuffer.h"
#include<string>
#include"5699368_MD4_Task3_Status.h"
#include<iostream>

// constructor --> parametrized
SignalBuffer::SignalBuffer(int id_, const std::string& source_, float strength_, std::uint64_t timeStamp_, Status status_): m_id(id_), m_source(source_),m_status(status_), m_strength(strength_), m_timeStamp(timeStamp_){}

// member functions
void SignalBuffer::updateStrength(float stregth_){
    m_strength = stregth_;
}

void SignalBuffer::setStatus(Status&& status_){
    m_status = status_;
}

// function to print details
void SignalBuffer::print() const{
    std::cout<<"ID: "<<m_id<<std::endl;
    std::cout<<"Source: "<<m_source<<std::endl;
    std::cout<<"Strength: "<<m_strength<<std::endl;
    std::cout<<"TimeStamp: "<<m_timeStamp<<std::endl;
    std::cout<<"Status: "<<getStatusName()<<std::endl;
}

// getters
float SignalBuffer::getStrength() const{
    return m_strength;
}

Status SignalBuffer::getStatus() const{
    return m_status;
}

// helper --> to get status as string
std::string SignalBuffer::getStatusName() const{
    if(m_status == Status::LOST){return "Lost";}
    else if(m_status == Status::VALID){return "Valid";}
    else {return "Weak";}
}

// move constructor and move assignment
SignalBuffer::SignalBuffer(SignalBuffer&& other)noexcept : m_id(other.m_id), m_source(std::move(other.m_source)),m_status(other.m_status), m_strength(other.m_strength), m_timeStamp(other.m_timeStamp) {}

SignalBuffer& SignalBuffer:: operator= (SignalBuffer&& other) noexcept{
    if(this!=&other){
        m_id = other.m_id; 
        m_source = std::move(other.m_source); 
        m_strength = other.m_strength; 
        m_status = other.m_status; 
        m_timeStamp = other.m_timeStamp; 
    }
    return *this;
};