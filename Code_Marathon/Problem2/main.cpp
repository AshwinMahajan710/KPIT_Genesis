#include"EngineModule.h"
#include"EngineType.h"
#include<stdexcept>
#include<iostream>
#include"Global.h"
#include"SensorModule.h"
#include"VehicleFleet.h"

int main(){

    // TC1 --> creating EngineModule object using sample data1
    EngineModule module(0,3000,90,50,EngineType::PETROL);

    // TC2 --> creating sensormodule* array using sampledata2
    SensorModule sensor1(1, 3000, 90, 50, EngineType::PETROL, 30);
    SensorModule sensor2(2,1500,85,75,EngineType::DIESEL, -20);
    SensorModule sensor3(3,4000,95,25,EngineType::HYBRID, 120);
    SensorModule sensor4(4,1500,85,75,EngineType::DIESEL, -30);
    SensorModule sensor5(5,4000,95,25,EngineType::HYBRID, 150);
    
    // TC3 --> creating vehicleFleet array using id 1
    VehicleFleet vehicleFleet(sensor1,1);
    std::cout<<"\nAverage Temperatutre of the sensors in fleet is: "<<vehicleFleet.averageAmbientTemperature()<<std::endl;

    // TC4 --> appending modules with id 2,3,4,5
    vehicleFleet += &sensor3;
    vehicleFleet += &sensor4;
    vehicleFleet += &sensor5;

    // TC5 --> displaying average temperature
    std::cout<<"\nAverage Temperatutre of the sensors in fleet is: "<<vehicleFleet.averageAmbientTemperature()<<std::endl;
    
    // TC6 --> replacing faulty module with module 2
    vehicleFleet.replaceFaultyModules(&sensor2);
    
    // TC7 --> displaying average temperature
    std::cout<<"\nAverage Temperatutre of the sensors in fleet is: "<<vehicleFleet.averageAmbientTemperature()<<std::endl;

    std::cout<<std::endl;

    return 0;
}