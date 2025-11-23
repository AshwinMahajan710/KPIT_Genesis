#include<vector>
#include<string>
#include"5699368_MD14_Task3_Sensor.h"
#include"5699368_MD14_Task3_PressureSensor.h"

// funtion to return double val
std::variant<int, double, std::string> PressureSensor:: readData() const{
    return 34;
}

std::string PressureSensor:: getType() const {
    return "Pressure Sensor";
}