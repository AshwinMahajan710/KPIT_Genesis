#include"Registration.h"

// parameterized constructor
Registration::Registration(float licenseFee_, float titleFee_): m_licenseFee(licenseFee_), m_titleFee(titleFee_){}

// getters
float Registration::getLicenseFee() const{
    return m_licenseFee;
}
float Registration::getTitleFee() const{
    return m_titleFee;
}

// setters
void Registration::setLicenseFee(float licenseFee_){
    m_licenseFee = licenseFee_;
}
void Registration::setTitleFee(float titleFee_){
    m_titleFee = titleFee_;
}