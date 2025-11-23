#include<variant>
#include<string>
#include<iostream>
#include"5699368_MD14_Task2_SensorData.h"

// display function --> global
void displaySensorInfo(const Sensordata& sensor){
    std::cout<<"\nSensor ID: "<<sensor.getId()<<std::endl;
    std::cout<<"Sensor Holding Val: ";
    if(sensor.isFloat()){std::cout<<"Float"<<std::endl;}
    else if(sensor.isInt()){std::cout<<"Int"<<std::endl;}
    else {std::cout<<"String"<<std::endl;}
    sensor.processReading();
}

int main(){

    // declaring the things
    Sensordata data1("Engine","23");
    Sensordata data2("Brake",std::variant<int, float, std::string>(23.4f));
    Sensordata data3("Gear",34.7f);

    // displaying sensor info
    displaySensorInfo(data1);
    displaySensorInfo(data2);
    displaySensorInfo(data3);
    
    return 0;
}