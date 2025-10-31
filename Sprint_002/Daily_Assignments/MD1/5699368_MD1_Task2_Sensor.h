#ifndef INC_5699368_MD1_TASK2_SENSOR_H
#define INC_5699368_MD1_TASK2_SENSOR_H

#include"5699368_MD1_Task2_SensorType.h"
#include<string>

class Sensor{
    private:
        SensorType m_sensorType;
    
    public:
        Sensor() = default;
        Sensor(SensorType type_);

        // show sensor function to check which sensor it is
        void showSensor() const;
};

#endif // INC_5699368_MD1_TASK2_SENSOR_H
