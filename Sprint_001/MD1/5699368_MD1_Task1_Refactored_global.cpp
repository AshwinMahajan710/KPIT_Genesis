#include <iostream>
#include <string>
#include <stdexcept>
#include "5699368_MD1_Task1_Refactored_FleetVehicle.h"
#include "5699368_MD1_Task1_Refactored_global.h"

// Assign a new driver to a vehicle
void assignDriver(FleetVehicle& vehicle, const std::string& name) noexcept
{
    std::cout << "Previous Driver: " << vehicle.getDriverName() << std::endl;
    vehicle.setDriverName(name);
    std::cout << "New Driver: " << vehicle.getDriverName() << std::endl;
}

// Refuel the vehicle safely
void refuelVehicle(FleetVehicle& vehicle, float fuelAmount)
{
    // Defensive check for invalid or excessive values
    if (fuelAmount <= 0.0F)
    {
        // MISRA discourages raw throw; ideally, handle via error code or logging
        throw std::invalid_argument("ERROR: Refuel amount must be greater than zero.");
    }

    const float newFuelLevel = vehicle.getFuelLevel() + fuelAmount;
    vehicle.setFuelLevel(newFuelLevel);

    std::cout << "Vehicle refueled successfully. New fuel level: "
              << vehicle.getFuelLevel() << std::endl;
}
