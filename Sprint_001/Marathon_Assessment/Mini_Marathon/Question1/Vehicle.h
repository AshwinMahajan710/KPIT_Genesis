#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>

class Vehicle{
    private:
        int m_vehicleId;
        std::string m_manufacturer; 
        std::string m_model; 
        double m_fuelLevel; // specifically 0 - 60
        double m_odometer; 
        bool m_isAvailable;
    
    public:

    // constructors
    Vehicle();
    Vehicle(int vehicleId_, const std::string& manufacturer_, const std::string& model_, double fuelLevel_, double odometer_, bool isAvailable_);

    // getters
    int getVehicleId() const;
    std::string getManufacturer() const;
    std::string getModel() const;
    double getFuelLevel() const;
    double getOdometer() const;
    bool getIsAvailable() const;

    // setters
    void setVehicleId(int vehicleId_) ;
    void setManufacturer(const std::string& manufacturer_) ;
    void setModel(const std::string& model_) ;
    void setFuelLevel(double fuelLevel_) ;
    void setOdometer(double odometer_) ;
    void setIsAvailable(bool isAvailable_);

    // drive(double distance) --> Increases odometer by distance and decreases fuelLevel by considering fuel consumption as 15 km/liter
    void drive(double distance_);

    // refuel(double liters) --> Adds fuel without exceeding tank capacity (60 liters)
    void refuel(double liters_);

    // displayInfo() --> Displays all vehicle information
    void displayInfo() const;

};

#endif // VEHICLE_H
