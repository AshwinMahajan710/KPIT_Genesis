#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include<string>
#include<vector>
#include<functional>
#include<unordered_map>
#include<memory>
#include"Sensor.h"

class SensorManager{
    private:
        std::unordered_map<std::string, std::shared_ptr<Sensor>> m_sensors;
    public:
        SensorManager() = default;
        void registerSensor(const std::string& id_); // create and store new sensor using std::make_shared<>
        void registerListener(const std::string& sensorId_, std::function<void (const std::string& )> func_); // adds a listner to specified sensor
        void broadcast(const std::string& sensorId_, const std::string& message_); // triggers event on specified sensor
};

#endif // SENSORMANAGER_H
