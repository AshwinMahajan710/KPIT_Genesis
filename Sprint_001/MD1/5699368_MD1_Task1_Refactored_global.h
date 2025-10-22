#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H

#include <string>
#include "5699368_MD1_Task1_Refactored_FleetVehicle.h"

// Assign a driver to the given vehicle
void assignDriver(FleetVehicle& vehicle, const std::string& name) noexcept;

// Refuel the given vehicle by a specified amount
void refuelVehicle(FleetVehicle& vehicle, float fuelAmount) noexcept;

#endif // GLOBAL_FUNCTIONS_H