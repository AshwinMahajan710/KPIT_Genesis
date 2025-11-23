#include<string>
#include<functional>
#include"5699368_MD5_Task1_Sensor.h"

// constructor --> parameterized
Sensor::Sensor(int id_, const std::string& type_, double value_, double threshold_): m_id(id_), m_type(type_), m_value(value_), m_threshold(threshold_){}

// update function
void Sensor::update(double value_){
    m_value = value_;
    if(m_value>m_threshold){
        f_onTrigger(m_id, m_value);
    }
}

// setting the handler function
void Sensor::setHandler(std::function<void(int,double)> handler_){
    f_onTrigger = handler_;
}

// getting threshold
double Sensor::getThreshold() const{
    return m_threshold;
}