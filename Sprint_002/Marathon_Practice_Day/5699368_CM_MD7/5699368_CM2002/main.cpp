#include<string>
#include<vector>
#include<functional>
#include<unordered_map>
#include<memory>
#include"Sensor.h"
#include<iostream>
#include"SensorManager.h"

int main(){

    // TC1 --> instantiating sensorManager
    SensorManager manager;
    manager.registerSensor("TempSensor");
    manager.registerSensor("MotionSensor");

    // TC2--> adding listners
    manager.registerListener("TempSensor",[](const std::string& message_)->void{std::cout<<message_<<std::endl;});
    manager.registerListener("TempSensor",[](const std::string& message_)->void{std::cout<<message_<<std::endl;});

    return 0;
}