#ifndef FLEET_VEHICLE_H
#define FLEET_VEHICLE_H

#include <string>

class FleetVehicle
{
private:
    int m_vehicleID;
    float m_fuelLevel;
    double m_distanceTravelled;
    char m_status;           // 'A' for Active, 'I' for Inactive
    bool m_isAvailable;
    std::string m_driverName;

public:
    // Constructors
    FleetVehicle();
    FleetVehicle(int vehicleID,
                 float fuelLevel,
                 double distanceTravelled,
                 char status,
                 bool isAvailable,
                 const std::string& driverName);

    // Destructor (should be virtual if class may be inherited)
    virtual ~FleetVehicle();

    // Getters (const-correct and noexcept)
    int getVehicleID() const noexcept;
    float getFuelLevel() const noexcept;
    double getDistanceTravelled() const noexcept;
    char getStatus() const noexcept;
    bool isAvailable() const noexcept;
    std::string getDriverName() const;

    // Setters (use const reference where applicable)
    void setVehicleID(int vehicleID_) noexcept;
    void setFuelLevel(float fuelLevel_) noexcept;
    void setDistanceTravelled(double distanceTravelled_) noexcept;
    void setStatus(char status_) noexcept;
    void setIsAvailable(bool isAvailable_) noexcept;
    void setDriverName(const std::string& driverName_);

    // Update status
    void updateStatus() noexcept;

    // Display information
    void displayInfo() const;
};

#endif // FLEET_VEHICLE_H
