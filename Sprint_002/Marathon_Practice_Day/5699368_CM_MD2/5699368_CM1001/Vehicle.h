#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
#include"VehicleType.h"

class Vehicle{
    private:
        std::string m_vin;
        VehicleType m_type;
    public:

        // constructors 
        Vehicle(); // will do delegation to parameterized constructor
        Vehicle(const std::string& vin_,VehicleType type_);
        Vehicle(const Vehicle& other) = delete;

        virtual std::string description() const = 0; // pure virtual function

        // getters
        VehicleType getType() const  noexcept;
        const std::string& getVin() const  noexcept;

        // destructor
        virtual ~Vehicle() = default; // defaulted virtual destructor
};

#endif // VEHICLE_H
