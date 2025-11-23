#ifndef GLOBAL_H
#define GLOBAL_H

#include<string>
#include"SensorType.h"
#include"Sensor.h"
#include"ADASModule.h"
#include<memory>
#include<vector>
#include<iostream>
#include"Vehicle.h"

// for printing deatils of all vehicles
void printAllVehicles(const std::vector<Vehicle>& vehicles);

// for finding vehicles based on module name
void findVehiclesWithModule(const std::vector<Vehicle>& vehicles, const std::string& moduleName);

#endif // GLOBAL_H
