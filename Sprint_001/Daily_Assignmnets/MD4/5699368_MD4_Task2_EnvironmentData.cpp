#include<iostream>
#include"5699368_MD4_Task2_EnvironmentData.h"

// constructor
EnvironmentData::EnvironmentData(float ambientTemp_, float altitude_, float humidity_): m_ambientTemperature(ambientTemp_), m_altitude(altitude_), m_humidity(humidity_){};

// printing info
void EnvironmentData::printEnvironmentData() const{
    std::cout<<"Ambient Temp: "<<m_ambientTemperature<<std::endl;
    std::cout<<"Altitude: "<<m_altitude<<std::endl;
    std::cout<<"Humidity: "<<m_humidity<<std::endl;
}