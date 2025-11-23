#include<variant>
#include<string>
#include"5699368_MD14_Task3_Sensor.h"
#include"5699368_MD14_Task3_PressureSensor.h"
#include"5699368_MD14_Task3_TemperatureSensor.h"
#include"5699368_MD14_Task3_SpeedSensor.h"
#include<vector>
#include<memory>
#include<functional>
#include"5699368_MD14_Task3_SensorDispatcher.h"
#include<iostream>

void processSensorData(const Sensor& sensor) {
    auto data = sensor.readData();

    std::visit([&](auto&& value){
        std::cout << "Processing " << sensor.getType() 
                  << ": " << value << std::endl;
    }, data);
}

int main() {

    SensorDispatcher dispatcher;

    dispatcher.addSensor(std::make_unique<TemperatureSensor>());
    dispatcher.addSensor(std::make_unique<PressureSensor>());
    dispatcher.addSensor(std::make_unique<SpeedSensor>());

    // manual dispathc
    for(const auto& sensor: dispatcher.getSensors()){
        processSensorData(*sensor);
    }
    
    // Schedule dispatch task
    dispatcher.scheduleTask([&](){
    for (const auto& sensor : dispatcher.getSensors()) {

        auto data = sensor->readData();

        std::visit([&](const auto& value){
            std::cout << "Dispatching "
                      << sensor->getType()
                      << ": " << value << std::endl;
        }, data);
    }
    
    });

    dispatcher.dispatchAll();
}