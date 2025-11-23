#include<variant>
#include<string>
#include<iostream>
#include"5699368_MD14_Task2_SensorData.h"

// constructor --> parameterized
Sensordata::Sensordata(const std::string& id_, const std::variant<int, float, std::string>& value): m_sensorID(id_), m_reading(value){}

// getters
std::string Sensordata:: getId() const{
    return m_sensorID;
}

bool Sensordata::isInt() const{
    if(std::holds_alternative<int>(m_reading)){
        return true;
    }else{
        return false;
    }
}
bool Sensordata::isString() const{
    if(std::holds_alternative<std::string>(m_reading)){
        return true;
    }else{
        return false;
    }
}
bool Sensordata::isFloat() const{
    if(std::holds_alternative<float>(m_reading)){
        return true;
    }else{
        return false;
    }
}

// getting the variant
std::variant<int , float, std::string> Sensordata::getVariant() const{
    return m_reading;
}

// printing the message in variant
void Sensordata:: processReading() const{
    std::visit([](const auto& variable){std::cout<<"Value is: "<<variable<<std::endl;},m_reading);
}