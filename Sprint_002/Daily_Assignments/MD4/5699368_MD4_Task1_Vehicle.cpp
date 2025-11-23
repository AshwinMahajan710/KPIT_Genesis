#include<iostream>
#include<string>
#include"5699368_MD4_Task1_Vehicle.h"
#include"5699368_MD4_Task1_Status.h"

// constructor --> parametrized
Vehicle::Vehicle(int id_,const std::string& model_, double temperature_, double voltage_, Status status_) :m_id(id_), m_model(model_), m_status(status_), m_temperature(temperature_), m_voltage(voltage_){ }

// setters
void Vehicle::updateTemperature(double temp_){
    m_temperature = temp_;
}
void Vehicle::updateVoltage(double voltage_){
    m_voltage = voltage_;
}
void Vehicle::setStatus(Status&& status_){
    m_status = status_;
}

// print function
void Vehicle::print() const{
    std::cout<<"ID: "<<m_id<<std::endl;
    std::cout<<"Model: "<<m_model<<std::endl;
    std::cout<<"Temperature: "<<m_temperature<<std::endl;
    std::cout<<"Voltage: "<<m_voltage<<std::endl;
    std::cout<<"Status: "<<getStatusString()<<std::endl;
}

// get string of status
std::string Vehicle::getStatusString() const{
    if(m_status == Status::FAIL){return "Fail";}
    else if(m_status == Status::OK){return "Ok";}
    else {return "WARN";}
}