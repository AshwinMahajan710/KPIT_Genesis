#ifndef VEHICLE_H
#define VEHICLE_H

#include"VehicleType.h"
#include<iostream>

class Vehicle{
    private:
        int m_id;
        bool m_isElectric;
        double m_mileage;
        VehicleType m_vehicleType;
        
    public:

        // all constructors
        Vehicle();
        Vehicle(int id_, bool isElectric_, double mileage_, VehicleType vehicleType_);
        Vehicle(const Vehicle& other);

        // getters
        int getId() const;
        bool getIsElectric() const;
        double getMileage() const;
        VehicleType getVehicleType() const;

        // setters
        void setID(int id_);
        void setIsElectric( bool isElectric_);
        void setMileage(double mileage_) ;
        void setVehicleType(VehicleType type);
        
        // Operator overloading
        Vehicle operator+ (const Vehicle& other);
        friend std::ostream& operator<<(std::ostream& out, const Vehicle& other);

        // getting string value to display for VehicleType
        std::string getStringVehicleType() const;
};
#endif
