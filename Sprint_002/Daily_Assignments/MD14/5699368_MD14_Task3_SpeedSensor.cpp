#include<vector>
#include<string>
#include"5699368_MD14_Task3_Sensor.h"
#include"5699368_MD14_Task3_SpeedSensor.h"

// funtion to return double val
std::variant<int, double, std::string> SpeedSensor:: readData() const{
    return "55 KM/H";
}

std::string SpeedSensor:: getType() const {
    return "Speed Sensor";
}