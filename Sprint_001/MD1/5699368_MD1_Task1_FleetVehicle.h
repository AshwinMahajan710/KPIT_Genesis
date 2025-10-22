
// Fleet vehicle header file

#ifndef FLEET_VEHICLE_H
#define FLEET_VEHICLE_H

#include <string>

class FleetVehicle{
    private:
        int m_vehicleID;
        float m_fuelLevel;
        double m_distanceTravelled;
        char m_status; // 'A' for active 'I' for Inactive 
        bool m_isAvailable;
        std::string m_driverName;

    public:

        // constructors
        FleetVehicle();
        FleetVehicle(const int vehicleID,const float fuelLevel,const double distanceTravelled,const char status,const bool isAvailable,const std::string driverName);

        // Destructor
        ~FleetVehicle();

        // Getters 
        int getVehicleID() const;
        float getFuelLevel() const;
        double getDistanceTravelled()const;
        char getStatus()const;
        bool getIsAvailable()const;
        std::string getDriverName()const;

        // setters
        void setVehicleID(int vehicleID_);
        void setFuelLevel(float fuelLevel_);
        void setDistanceTravelled(double distanceTravelled_);
        void setStatus(char status_);
        void setIsAvailable(bool isAvailable_);
        void setDriverName(std::string driverName_);

        // updatestatus function
        void updateStatus();
        
        // Display Details
        void displayInfo();
};

#endif