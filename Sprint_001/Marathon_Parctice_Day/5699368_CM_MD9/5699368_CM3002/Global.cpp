#include"HeapSensor.h"
#include"Global.h"
#include<float.h>

// function to calculate maxVoltage
float computeMaxVoltage(const HeapSensor* arr_[], int count_){
    float maxVoltage = FLT_MIN;
    for(int i=0;i<count_;i++){
        if((arr_[i]!=nullptr) && (arr_[i]->getId() >= 0) && (arr_[i]->getVoltageV() > maxVoltage)){
            maxVoltage = arr_[i]->getVoltageV();
        }
    }
    return ((maxVoltage == FLT_MIN) ? -1.0f : maxVoltage);
}

// function to adjust temperature in particular range
void adjustTemperaturesToRange(HeapSensor* arr_[], int count_, float minAllowed_, float maxAllowed_){
    for(int i=0;i<count_;i++){
        if((arr_[i]!=nullptr) && (arr_[i]->getId() >= 0)){
            if(arr_[i]->getTemperatureC() < minAllowed_){
                arr_[i]->setTemperatureC(minAllowed_);
            }
            else if(arr_[i]->getTemperatureC() > maxAllowed_){
                arr_[i]->setTemperatureC(maxAllowed_);
            }
        }
    }
}

// getting average temperatur
float computeAverageTemperature(const HeapSensor* arr_[], int count_){
    float sumOfTemperature = 0.0f;
    int count = 0;
    for(int i=0;i<count_;i++){
        if((arr_[i]!=nullptr) && (arr_[i]->getId() >= 0)){
            sumOfTemperature += arr_[i]->getTemperatureC();
            count++;
        }
    }
    return ( sumOfTemperature==0.0 ? -1.0f : (sumOfTemperature/count));
}