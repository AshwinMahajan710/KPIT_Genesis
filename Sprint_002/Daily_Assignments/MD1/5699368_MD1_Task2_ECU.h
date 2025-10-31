#ifndef INC_5699368_MD1_TASK2_ECU_H
#define INC_5699368_MD1_TASK2_ECU_H

#include<string>
#include<iostream>
#include"5699368_MD1_Task2_ActuatorType.h"
#include"5699368_MD1_Task2_Actuator.h"
#include"5699368_MD1_Task2_SensorType.h"
#include"5699368_MD1_Task2_Sensor.h"

class ECU{
    private:
        Sensor m_sensor;
        Actuator* m_actuator;
    public:
        ECU() = default;
        ECU(Sensor sensor_);
        void ConnectActuator(Actuator* actuator_);

        void showStatus() const;
        ~ECU();
};

#endif // INC_5699368_MD1_TASK2_ECU_H
