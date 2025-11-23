#include"5699368_MD4_Task1_Vehicle.h"
#include"5699368_MD4_Task1_Global.h"
#include"5699368_MD4_Task1_Status.h"
#include<string>
#include<iostream>

int main(){

    // Intializing objects via inclass initialization
    Vehicle v1;

    // via initializer list
    Vehicle v2(101,"Sedan",85.0,12.5,Status::OK);
    Vehicle v3(102,"SUV",95.0,11.8,Status::WARN);
    Vehicle v4(103,"Coupe",105.0,12.8,Status::FAIL);

    // updating temeperature and voltage
    v2.updateTemperature(12.0);
    v2.updateVoltage(123);

    // setting status via rvalue reference
    v2.setStatus(Status::WARN);

    // calling all 4 types
    logVehicleByValue(v2);
    logVehicleByRef(v2);
    logVehicleByRRef(std::move(v2));
    logVehicleByPtr(&v2);

    // uisng lambda to filter out vehicles with temperature > 90 and voltage < 12
    auto vehicle = [](Vehicle& vehicle){ return (vehicle.m_temperature > 90 && vehicle.m_voltage > 12);};

    // storing the results in array and storing them
    Vehicle* arr[4] = {&v1,&v2,&v3,&v4};
    for(auto &i: arr){
        if(!vehicle(*i)){
            i = nullptr;
        }
    }

    std::cout<<"Following are the details of filetres objects: "<<std::endl;
    // printing 
    for(auto &i: arr){
        if(i!=nullptr){
            std::cout<<std::endl;
            i->print();

        }
    }
    return 0;
}
