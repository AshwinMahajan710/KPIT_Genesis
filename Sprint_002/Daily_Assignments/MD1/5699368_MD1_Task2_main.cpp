#include<string>
#include<iostream>
#include"5699368_MD1_Task2_ActuatorType.h"
#include"5699368_MD1_Task2_Actuator.h"
#include"5699368_MD1_Task2_SensorType.h"
#include"5699368_MD1_Task2_Sensor.h"
#include"5699368_MD1_Task2_ECU.h"

int main(){

    // creating objects
    ECU ecu(SensorType::TEMPERATURE);

    // cheking if nullptr actuator what it shows
    ecu.showStatus();

    // connecting motor actuator and then checking 
    Actuator* actuator = new Actuator(ActuatorType::MOTOR);
    ecu.ConnectActuator(actuator);

    // check after connceting actuator
    ecu.showStatus();

    return 0;
}