#include <iostream>
#include <string>
#include "5699368_MD1_Task1_Refactored_FleetVehicle.h"

// Default constructor (explicit initialization list preferred)
FleetVehicle::FleetVehicle() noexcept
    : m_vehicleID(0),
      m_fuelLevel(50.0F),
      m_distanceTravelled(0.0),
      m_status('A'),
      m_isAvailable(true),
      m_driverName("Unassigned")
{
    // No body logic needed; initialization list is sufficient
}

// Parameterized constructor
FleetVehicle::FleetVehicle(int vehicleID_,
                           float fuelLevel_,
                           double distanceTravelled_,
                           char status_,
                           bool isAvailable_,
                           const std::string& driverName_) noexcept
    : m_vehicleID(vehicleID_),
      m_fuelLevel(fuelLevel_),
      m_distanceTravelled(distanceTravelled_),
      m_status(status_),
      m_isAvailable(isAvailable_),
      m_driverName(driverName_)
{
    updateStatus();  // ensure internal consistency
}

// Virtual destructor
FleetVehicle::~FleetVehicle() noexcept
{
    std::cout << "Destructor called for vehicle ID: " << m_vehicleID << std::endl;
}

// Getters (const + noexcept)
int FleetVehicle::getVehicleID() const noexcept { return m_vehicleID; }
float FleetVehicle::getFuelLevel() const noexcept { return m_fuelLevel; }
double FleetVehicle::getDistanceTravelled() const noexcept { return m_distanceTravelled; }
char FleetVehicle::getStatus() const noexcept { return m_status; }
bool FleetVehicle::isAvailable() const noexcept { return m_isAvailable; }
std::string FleetVehicle::getDriverName() const { return m_driverName; }

// Setters
void FleetVehicle::setVehicleID(int vehicleID_) noexcept { m_vehicleID = vehicleID_; }
void FleetVehicle::setFuelLevel(float fuelLevel_) noexcept { m_fuelLevel = fuelLevel_; }
void FleetVehicle::setDistanceTravelled(double distanceTravelled_) noexcept { m_distanceTravelled = distanceTravelled_; }
void FleetVehicle::setStatus(char status_) noexcept { m_status = status_; }
void FleetVehicle::setIsAvailable(bool isAvailable_) noexcept { m_isAvailable = isAvailable_; }
void FleetVehicle::setDriverName(const std::string& driverName_) { m_driverName = driverName_; }

// Update Status
void FleetVehicle::updateStatus() noexcept
{
    if ((m_fuelLevel < 10.0F) || (!m_isAvailable))
    {
        m_status = 'I';
    }
    else
    {
        m_status = 'A';
    }
}

// Display information
void FleetVehicle::displayInfo() const
{
    const std::string isVehicleAvailable = (m_isAvailable ? "Yes" : "No");
    const std::string currentStatus = (m_status == 'A') ? "Active" : "Inactive";

    std::cout << "\n***************************************\n";
    std::cout << "Vehicle ID: " << m_vehicleID << '\n';
    std::cout << "Fuel Level: " << m_fuelLevel << '\n';
    std::cout << "Distance Travelled: " << m_distanceTravelled << '\n';
    std::cout << "Status: " << currentStatus << '\n';
    std::cout << "Vehicle Availability: " << isVehicleAvailable << '\n';
    std::cout << "Driver Name: " << m_driverName << '\n';
    std::cout << "***************************************\n";
}
