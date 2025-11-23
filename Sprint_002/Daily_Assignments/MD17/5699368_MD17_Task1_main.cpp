#include<string>
#include"5699368_MD17_Task1_SensorData.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include"5699368_MD17_Task1_Global.h"
#include<algorithm>
#include<iostream>

int main(){

    // creating 6 readings of sensor
    std::vector<Sensordata> readings = {
        {"Brake", 100.0, true},
        {"Engine", 200.0, true},
        {"Pedal", 300.0, false},
        {"ECU", 400.0, true},
        {"OIL", 500.0, false},
        {"Engine", 600.0, true},
    };

    std::cout<<"\nTotal Readings count: "<<readings.size()<<std::endl;
    
    // filtering valid readings
    std::vector<Sensordata> validReadings = copyValidReadings(readings);
    std::cout<<"\nTotal Valid Readings count: "<<validReadings.size()<<std::endl;
    
    // copying fIrst 3 readings
    std::vector<Sensordata> first3Readings = copyFirstNReadings(readings,3);
    std::cout<<"\nTotal Valid Readings count: "<<first3Readings.size()<<std::endl;
    
    // copying all readings
    std::vector<Sensordata> allReadings = copyAllReadings(readings);
    std::cout<<"\nTotal Readings count: "<<allReadings.size()<<std::endl;
    
    // copying readings above threshold
    std::vector<Sensordata> readingsAboveThreshold = copyReadingsAboveThreshold(readings,300);
    std::cout<<"\nTotal Readings count above threshold: "<<readingsAboveThreshold.size()<<std::endl;

    // copying readings from "Engine" module
    std::vector<Sensordata> EngineReadingCount = copyModuleReadings(readings,"Engine");
    std::cout<<"\nTotal Valid Readings in Engine Module: "<<EngineReadingCount.size()<<std::endl;

    return 0;
}