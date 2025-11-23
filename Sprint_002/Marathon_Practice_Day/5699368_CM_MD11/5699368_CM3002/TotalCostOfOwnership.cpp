#include"Vehicle.h"
#include"Registration.h"
#include"Maintainance.h"
#include"Insuarance.h"
#include"TotalCostOfOwnership.h"

// paramaterized constructor
TotalCostOfOwnership::TotalCostOfOwnership(Vehicle vehicle_,Registration registration_,Maintainance maintainance_,Insuarance insuarance_): m_insuarance(insuarance_), m_vehicle(vehicle_), m_registration(registration_), m_maintainance(maintainance_){}

// getters
const Vehicle& TotalCostOfOwnership:: getVehicle() const{
    return m_vehicle;
}
const Registration& TotalCostOfOwnership:: getRegistration () const{
    return m_registration;
}
const Maintainance& TotalCostOfOwnership:: geMtaintainance () const{
    return m_maintainance;
}
const Insuarance& TotalCostOfOwnership:: getInsuarance () const{
    return m_insuarance;
}   

//setters
void TotalCostOfOwnership:: setVehicle(Vehicle vehicle_){
    m_vehicle = vehicle_;
}
void TotalCostOfOwnership:: setRegistration(Registration registration_){
    m_registration = registration_;
}
void TotalCostOfOwnership:: setMaintainance(Maintainance maintainance_){
    m_maintainance = maintainance_;
}
void TotalCostOfOwnership:: setInsuarance(Insuarance insuarance_){
    m_insuarance = insuarance_;
}