#include<string>
#include"Status.h"
#include"SmartAppliance.h"
#include<stdexcept>
#include<iostream>

// constructor --> parameterized
SmartAppliance::SmartAppliance(int id_, const std::string& name_, Status status_, double discount_): m_id(id_), m_name(name_), m_status(status_){
	if(discount_ <0.0 || discount_ > 25.0){ throw std::out_of_range("InvalidDiscountException: \"Discount value exceeded the given range\"");}
	else {m_discount = discount_;}
}

// move constructor and move assignment
SmartAppliance::SmartAppliance(SmartAppliance&& other):m_id(other.m_id), m_discount(other.m_discount), m_status(other.m_status){
	m_name = std::move(other.m_name);
}

SmartAppliance& SmartAppliance::operator=(SmartAppliance&& other){
	if(this!=&other){
			m_id = other.m_id;
			m_status = other.m_status;
			m_discount = other.m_discount;
			m_name = std::move(other.m_name);
	}
	return *this;
}

// display method to display values
void SmartAppliance::display() const{
	std::cout<<"\nAppliance ID: "<<m_id<<std::endl;
	std::cout<<"Appliance Name: "<<m_name<<std::endl;
	std::cout<<"Appliance Discount: "<<m_discount<<std::endl;
	std::cout<<"Appliance Status: "<<getStatusString()<<std::endl;
}

// getter for discount
double SmartAppliance::getDiscount() const{
	return m_discount;
}

// getter for name
std::string SmartAppliance::getName() const{
	return m_name;
}

// getter for status
Status SmartAppliance:: getStatus() const{
	return m_status;
}

// setter for discount
void SmartAppliance::setDiscount(double newDiscount){
	m_discount = (newDiscount > 25.0) ? 25.0 : ((newDiscount<0.0) ? 0.0 : newDiscount);
}

// helper --> get Status string
std::string SmartAppliance:: getStatusString() const{
	if(m_status == Status::OFF) {return "Off";}
	else {return "On";}
}

