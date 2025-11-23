#include<string>
#include<vector>
#include<functional>
#include<unordered_map>
#include<memory>
#include"Sensor.h"
#include<iostream>
#include"SensorManager.h"

// create and store new sensor using std::make_shared<>
void SensorManager::registerSensor(const std::string& id_){
    std::shared_ptr<Sensor> newSensor = std::make_shared<Sensor>(id_);
    m_sensors[id_] = newSensor;
    std::cout<<"\nRegsistered sensor: "<<id_<<std::endl;
}

// adds a listner to specified sensor
void SensorManager::registerListener(const std::string& sensorId_, std::function<void (const std::string& )> func_){
    if(m_sensors.find(sensorId_)!= m_sensors.end()){
        m_sensors[sensorId_]->addListeners(func_);
        std::cout<<"\nListener added successfully.."<<std::endl;
    }
    else{
        std::cout<<"\nSensor with particular name not found.."<<std::endl;
    }
}

// triggers event pn specified sensor
void SensorManager::broadcast(const std::string& sensorId_, const std::string& message_){
    if(m_sensors.find(sensorId_)!= m_sensors.end()){
        m_sensors[sensorId_]->triggerMessage(message_);
    }
    else{
        std::cout<<"\nSensor with particular name not found.."<<std::endl;
    }
}
