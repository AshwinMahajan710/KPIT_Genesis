#include"Insuarance.h"

// constructor --> parametrized
Insuarance::Insuarance(float liability_, float collision_, float comprehensive_):m_collisionCoverage(collision_), m_liabilityCoverage(liability_), m_comprehensiveCoverage(comprehensive_){}

// getters
float Insuarance::getLiabilityCoverage() const{
    return m_liabilityCoverage;
}
float Insuarance::getCollisionCoverage() const{
    return m_collisionCoverage;
}
float Insuarance::getComprehensiveCoverage() const{
    return m_comprehensiveCoverage;
}

// setters
void Insuarance::setLiabilityCoverage(float liability_){
    m_liabilityCoverage = liability_;
}
void Insuarance::setCollisionCoverage( float collision_){
    m_collisionCoverage = collision_;
}
void Insuarance::setComprehensiveCoverage(float comprehensive_){
    m_comprehensiveCoverage = comprehensive_;
}