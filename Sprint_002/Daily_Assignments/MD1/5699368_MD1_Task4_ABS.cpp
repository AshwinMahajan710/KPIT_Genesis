
#include"5699368_MD1_Task4_ABS.h"
#include"5699368_MD1_Task4_SafetyFeature.h"
#include<iostream>
#include<string>

// constructor
ABS::ABS(const std::string& featureName_, bool isEnabled_, double wheelSpeedSensorAcccuracy_): SafetyFeature(featureName_, isEnabled_) ,m_wheelSpeedSensorAccuracy(wheelSpeedSensorAcccuracy_){};

void ABS::activated(){
    std::cout<<"\nActivating ABS"<<std::endl;
}

void ABS::show(){
    SafetyFeature::show();
    std::cout<<"\nWheel Speed sensor accuracy: "<<m_wheelSpeedSensorAccuracy<<std::endl;
}