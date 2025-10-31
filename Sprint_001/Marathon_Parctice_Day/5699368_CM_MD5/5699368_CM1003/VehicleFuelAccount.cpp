#include<stdexcept>
#include<iostream>
#include"VehicleFuelAccount.h"

// constructor
VehicleFuelAccount::VehicleFuelAccount(double fuelBalance_){
    if(fuelBalance_>=0) {this->m_fuelBalance = fuelBalance_;}
    else{throw std::invalid_argument("Exception: Fuel value can never be negative..");}
}

// calculateMothlyBalance Function --> 
void VehicleFuelAccount::calculateMonthlyBonus(){
    if(s_fleetEfficiencyRate < 0) {throw std::invalid_argument("Fleet Efficiency Rate can never be -ve..");}
    else {m_fuelBalance += ((s_fleetEfficiencyRate*m_fuelBalance/100.0)/ 12.0);} // modified formulae for adding monthly bonus
}

//display function --> will display details of object
void VehicleFuelAccount::display() const{
    std::cout<<"Current Fuel Balance: "<<m_fuelBalance<<std::endl;
}

// getFuelBalance function --> will return current fuel balance
double VehicleFuelAccount::getFuelBalance() const{
    return m_fuelBalance;
}

// function to update fuel efficiency rate
void VehicleFuelAccount::modifyEfficiencyRate(double newRate_){
    if(newRate_ < 0 ) {throw std::invalid_argument("Fuel Efficiency can never ne negative");}
    else {s_fleetEfficiencyRate = newRate_;} 
}