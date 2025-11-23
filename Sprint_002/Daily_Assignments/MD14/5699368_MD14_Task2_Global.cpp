#include<string>
#include<variant>
#include"5699368_MD14_Task2_SensorReading.h"
#include"5699368_MD14_Task2_Global.h"
#include<iostream>

// function to print sensor info
void printSensorReading(const SensorReading& sensor){
    std::cout<<"\nSensor name: "<<sensor.getName()<<std::endl;
    std::cout<<"value is: "<<sensor.getValueAsString()<<std::endl;
}