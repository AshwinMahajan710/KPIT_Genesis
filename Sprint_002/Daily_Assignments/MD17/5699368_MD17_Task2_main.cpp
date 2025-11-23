#include<string>
#include"5699368_MD17_Task2_SensorReading.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include"5699368_MD17_Task2_Global.h"
#include<algorithm>

int main(){

    // creating 6 readings of sensor
    std::vector<SensorReading> readings = {
        {"Engine", 200.0, false},
        {"Pedal", 300.0, false},
        {"ECU", 400.0, false},
        {"OIL", 500.0, false},
        {"Engine", 600.0, false},
    };

    // chekced for any faulty readings
    std::cout<<"\nAre Any faulty readings: "<<(hasAnyFaultyReadings(readings) ? "Yes": "No")<<std::endl;

    // check all readings are valid
    std::cout<<"\nAre All readings valid: "<<(areAllReadingsValid(readings) ? "Yes": "No")<<std::endl;

    // check for absence of  "Brake" Module
    std::cout<<"\nIs Break Module missing: "<<(noneFromModule(readings,"Brake") ? "Yes": "No")<<std::endl;

    // check for readings above 75.0
    std::cout<<"\nAre there any Readings above 75.0: "<<(isAnyReadingAbove(readings, 75.0) ? "Yes": "No")<<std::endl;
    
    // check if all readings are named
    std::cout<<"\nAre all modules named: "<<(areAllModulesNamed(readings) ? "Yes": "No")<<std::endl;

    
    return 0;
}