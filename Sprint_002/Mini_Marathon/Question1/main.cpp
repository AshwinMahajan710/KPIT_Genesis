#include<string>
#include"SensorType.h"
#include"Sensor.h"
#include"ADASModule.h"
#include<memory>
#include<vector>
#include<iostream>
#include"Vehicle.h"
#include"Global.h"

int main(){

    // TC1 --> creating sensor s1 and s2 using constructor delegation
    Sensor s1(SensorType::RADAR,150.0,"720P");
    Sensor s2(SensorType::CAMERA,100.0,"1080P");

    // TC2 --> creating ADAS modules with delegated constructor
    std::shared_ptr<ADASModule> m1 = std::make_shared<ADASModule>("Lane Assist","1.2",s1);
    std::shared_ptr<ADASModule> m2 = std::make_shared<ADASModule>("Collsion detection","2.0",s2);

    // TC3 --> creating vehicle obj using delegated constructor
    Vehicle v1("Tesla","Model S", 2022);
    Vehicle v2("BMW ","X5", 2023);

    // TC4 --> Assigning modules to vehicles using shared pointers'
    v1.addModules(m1);
    v1.addModules(m2);
    v2.addModules(m1);

    // creating vector of vehicles 
    std::vector<Vehicle> vehicles;
    vehicles.emplace_back(v1);
    vehicles.emplace_back(v2);

    // TC5 --> printing all vehicles info
    printAllVehicles(vehicles);

    // TC6 --> Finding vehicles with "Lane assist"
    findVehiclesWithModule(vehicles, "Lane Assist");

    // TC7 --> printing vehicles with << --> already done in printAllVehicles function

    return 0;
}