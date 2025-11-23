#include<string>
#include"5699368_MD4_Task2_State.h"
#include"5699368_MD4_Task2_Sensor.h"
#include<iostream>

// constructor --> patrameterized
Sensor::Sensor(int id_, const std::string & type_, float gain_, float offset_, State state_): m_id(id_), m_gain(gain_), m_type(type_), m_offset(offset_), m_state(state_){}

// member functions
void Sensor::applyCallibration(float gain_, float offset_){
    m_gain = gain_;
}

// print function
void Sensor::print() const{
    std::cout<<"ID: "<<m_id<<std::endl;
    std::cout<<"Type: "<<m_type<<std::endl;
    std::cout<<"Gain: "<<m_gain<<std::endl;
    std::cout<<"Offset: "<<m_offset<<std::endl;
    std::cout<<"Status: "<<getStateName()<<std::endl;
}

// getters
float Sensor::getGain() const{
    return m_gain;
}
State Sensor::getState() const{
    return m_state;
}

void Sensor::setState(State&& state_){
    m_state = state_;
}

// helper --> get state name
std::string Sensor::getStateName() const{
    if(m_state == State::CALIBRATED) {return "Calibrated";}
    else if(m_state == State::ERROR) {return "ERROR";}
    else {return "Uncalibrated";}
}