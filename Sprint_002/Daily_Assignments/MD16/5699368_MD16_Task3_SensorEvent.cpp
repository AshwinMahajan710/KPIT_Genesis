#include<string>
#include<iostream>
#include"5699368_MD16_Task3_SensorEvent.h"

// constructor --> parameterized
SensorEvent::SensorEvent(const std::string& id_, double value_, const std::string& description_): m_id(id_), m_description(description_), m_value(value_) {}

// move constructor
SensorEvent::SensorEvent(SensorEvent&& other) noexcept : m_value(other.m_value){
    m_id = std::move(other.m_id);
    m_description = std::move(other.m_description);
}

// move assignment
SensorEvent& SensorEvent:: operator=(SensorEvent&& other) noexcept{
    m_id = std::move(other.m_id);
    m_description = std::move(other.m_description);
    m_value = other.m_value;
    return *this;
}

// getters
std::string SensorEvent:: getId() const{
    return m_id;
}
double SensorEvent::getValue() const{
    return m_value;
}
std::string SensorEvent::getDescription() const{
    return m_description;
}

// to print details
void SensorEvent::print() const{
    std::cout<<"Id: "<<m_id<<std::endl;
    std::cout<<"Value: "<<m_value<<std::endl;
    std::cout<<"Description: "<<m_description<<std::endl;
}