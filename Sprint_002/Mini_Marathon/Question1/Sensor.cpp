#include<string>
#include"SensorType.h"
#include"Sensor.h"

// constructor --> delegated to parametrized
Sensor::Sensor() : Sensor(SensorType::CAMERA, 0.0, ""){};

// constructor --> Parameterized 
Sensor::Sensor(SensorType type_, double range_, const std::string& resolution_): m_range(range_), m_resolution(resolution_), m_sensorType(type_){}

// getting sensor name
std::string Sensor:: getSensorName() const{
    if(m_sensorType == SensorType::CAMERA){return "Camera";}
    else {return "Radar";}
}