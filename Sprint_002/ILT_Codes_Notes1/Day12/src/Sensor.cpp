#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include"Sensor.h"

// constructor --> parameterized
Sensor::Sensor(const std::string& name_, int priority_, double reading_): m_name(name_), m_priority(priority_), m_reading(reading_){};

// getters
std::string Sensor::getName() const{return m_name;};
int Sensor::getPriority() const{return m_priority;};
double Sensor::getReading() const{return m_reading;};

// display function 
void Sensor::display() const{
    std::cout<<"\nname: "<<m_name<<std::endl;
    std::cout<<"\npriority: "<<m_priority<<std::endl;
    std::cout<<"\nreading: "<<m_reading<<std::endl;
}