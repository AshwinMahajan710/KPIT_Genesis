#include"Global.h"
#include"Sensor.h"
#include<iostream>
#include<string>
#include<stdexcept>

// Compares detection ranges and returns which sensor has greater range.
std::string compareSensorRanges(const Sensor* s1, const Sensor* s2){
    if(s1->getDetectionRange() > s2->getDetectionRange()) {return s1->getSensorType();}
    if(s1->getDetectionRange() < s2->getDetectionRange()) {return s2->getSensorType();}
    else {return "Both have same range";}
}

// Returns true if sensor is ACTIVE and average reading ≥ threshold.
bool isSensorReliable(const Sensor& sensor, double threshold){
    return ((sensor.getStatus() == ACTIVE) && (sensor.getAverageReading() > 75.0));
}

// Displays details of all sensors in an array.
void displaySensorArray(Sensor* sensors[], int size){
    for(int i=0;i<size;i++){
        std::cout<<"\nDisplaying details for sensor "<<i+1;
        sensors[i]->displaySensorInfo();
    }
}