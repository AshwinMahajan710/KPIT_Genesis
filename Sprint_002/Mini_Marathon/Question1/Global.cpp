#include<string>
#include"SensorType.h"
#include"Sensor.h"
#include"ADASModule.h"
#include<memory>
#include<vector>
#include<iostream>
#include"Vehicle.h"
#include"Global.h"

// for printing deatils of all vehicles
void printAllVehicles(const std::vector<Vehicle>& vehicles){
    for(auto& vehicle: vehicles){
        std::cout<<vehicle;
    }
}

// for finding vehicles based on module name
void findVehiclesWithModule(const std::vector<Vehicle>& vehicles, const std::string& moduleName){
    bool found = false;
    for(auto& vehicle: vehicles){
        for(auto& module: vehicle.m_modules){
            if(module->m_moduleName == moduleName){
                found = true;
                std::cout<<"\nModule found: "<<std::endl;
                std::cout<<"Module Name: "<<module->m_moduleName<<std::endl;
                std::cout<<"Version Name: "<<module->m_version<<std::endl;
                std::cout<<"Sensor Name: "<<(module->m_sensor).m_range<<std::endl;
                std::cout<<"Sensor Resolution: "<<(module->m_sensor).m_resolution<<std::endl;
                std::cout<<"Sensor Type: "<<(module->m_sensor).getSensorName()<<std::endl;
            }
            found = true;
        }
    }
    if(!found){
        std::cout<<"No module with that name found.."<<std::endl;
    }
}