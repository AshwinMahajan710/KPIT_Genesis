#include"Maintainance.h"

// constructor --> parametrized
Maintainance::Maintainance(float oilCost_, float tireCost_, float repairCost_): m_oilChangeCost(oilCost_), m_repairCost(repairCost_), m_tireRotationCost(tireCost_){}

// getters
float Maintainance::getOilChangeCost() const{
    return m_oilChangeCost;
}
float Maintainance::getTireRotationCost() const{
    return m_tireRotationCost;
}
float Maintainance::getRepairCost() const{
    return m_repairCost;
}

// setters
void Maintainance::setOilChangeCost(float oilCost_){
    m_oilChangeCost = oilCost_;
}
void Maintainance::setTireRotationCost(float tireCost_){
    m_tireRotationCost = tireCost_;
}
void Maintainance::setRepairCost(float repairCost_){
    m_repairCost = repairCost_;
}