#include"EngineModule.h"
#include"EngineType.h"
#include<stdexcept>
#include<iostream>
#include"Global.h"
#include"SensorModule.h"

// function to update all modules efficiency
void updateAllModulesEfficiency(EngineModule* modules[], int size, float value){
    for(int i=0;i<size;i++){
        try
        {
            modules[i]->updateEfficiency(value);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

// function to calculate total power
void calculateTotalPowerOutput(EngineModule* modules[], int size){
    float totalPower = 0.0f;
    for(int i=0;i<size;i++){
        totalPower += modules[i]->calculatePowerOutput();
    }
    std::cout<<"\nTotal power output is: "<<totalPower<<std::endl;
}

// function to check sensor is critical or not
void isSensorCritical(SensorModule* sensors[], int size){
    for(auto i=0;i<size;i++){
        if(sensors[i]->isModuleCritical()){
            std::cout<<"\nModule "<< i+1<<" is Critical.."<<std::endl;
        }
    }
}