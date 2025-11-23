// < = = = = = = = = = =  Device.cpp  = = = = = = = = = = >
#include <iostream>
#include<string>
#include"Device.h"
#include"Status.h"
// constructor --> parametrized
Device::Device(int id_, const std::string& name_, Status status_): m_id(id_), m_name(name_), m_status(status_){};

// move constructor and move assignment implementation
Device::Device(Device&& other){
  this->m_name = std::move(other.m_name);
  this-> m_id = other.m_id;
  this->m_status = other.m_status;
}

Device& Device::operator =(Device&& other){
  this->m_name = std::move(other.m_name);
  this-> m_id = other.m_id;
  this->m_status = other.m_status;
  return *this;
}

// display method to display details
void Device::display() const{
  std::cout<<"\nID: "<<m_id<<std::endl;
  std::cout<<"Name: "<<m_name<<std::endl;
  std::cout<<"Status: "<<statusString()<<std::endl;
}

// Helper --> statusString() to display status string
std::string Device::statusString() const{
  if(m_status == Status::ACTIVE){
    return "Active";
  }
  else {
    return "InActive";
  }
}

// getters for string
std::string Device::getName() const{
  return m_name;
}

// getter for status
Status Device::getStatus() const{
  return m_status;
}

// setter for status
void Device::setStatus(Status status){
  m_status = status;
}
