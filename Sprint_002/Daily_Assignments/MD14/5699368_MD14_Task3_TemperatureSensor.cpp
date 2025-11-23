#include<vector>
#include<string>
#include"5699368_MD14_Task3_Sensor.h"
#include"5699368_MD14_Task3_TemperatureSensor.h"

// funtion to return double val
std::variant<int, double, std::string> TemperatureSensor:: readData() const{
    return 36.5;
}

std::string TemperatureSensor:: getType() const {
    return "Temperature Sensor";
}