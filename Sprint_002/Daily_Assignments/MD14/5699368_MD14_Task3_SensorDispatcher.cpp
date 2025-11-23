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

// method to add sensor in sensors list
void SensorDispatcher::addSensor(std::unique_ptr<Sensor>&& sensor){
    m_sensors.emplace_back(std::move(sensor));
}

// adding task to list
void SensorDispatcher::scheduleTask(std::function<void ()> task){
    // take by value and move into container to accept temporaries
    m_tasks.push_back(std::move(task));
}
void SensorDispatcher::dispatchAll() {
    for(const auto& task : m_tasks) {
        task();
    }
    m_tasks.clear();
}

const std::vector<std::unique_ptr<Sensor>>& SensorDispatcher::getSensors() const {
    return m_sensors;
}