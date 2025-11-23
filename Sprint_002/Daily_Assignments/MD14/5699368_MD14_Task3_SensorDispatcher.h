#ifndef INC_5699368_MD14_TASK3_SENSORDISPATCHER_H
#define INC_5699368_MD14_TASK3_SENSORDISPATCHER_H

#include<variant>
#include<string>
#include"5699368_MD14_Task3_Sensor.h"
#include"5699368_MD14_Task3_PressureSensor.h"
#include"5699368_MD14_Task3_TemperatureSensor.h"
#include"5699368_MD14_Task3_SpeedSensor.h"
#include<vector>
#include<memory>
#include<functional>

class SensorDispatcher{
    private:
        std::vector<std::function<void()>> m_tasks; // stores scheduled task to be executed on dispatch
        std::vector<std::unique_ptr<Sensor>> m_sensors;
    public:
        SensorDispatcher() = default;
        SensorDispatcher(const SensorDispatcher&) = delete;
        SensorDispatcher& operator =(const SensorDispatcher&) = delete;
        SensorDispatcher(SensorDispatcher&&) = delete;
        SensorDispatcher& operator =(SensorDispatcher&&) = delete;
        ~SensorDispatcher() = default;
        
        // method to add sensor in sensors list
        void addSensor(std::unique_ptr<Sensor>&& sensor);

    // adding task to list
    // take task by value so temporaries (lambdas) can be passed
    void scheduleTask(std::function<void ()> task); 

        // for dispatching function
        void dispatchAll() ;

        // getting all stored sensor
        const std::vector<std::unique_ptr<Sensor>>& getSensors() const;
};

#endif // INC_5699368_MD14_TASK3_SENSORDISPATCHER_H
