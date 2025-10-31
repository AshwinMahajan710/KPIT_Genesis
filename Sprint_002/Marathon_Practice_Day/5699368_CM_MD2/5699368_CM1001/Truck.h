#ifndef TRUCK_H
#define TRUCK_H

#include<string>
#include"VehicleType.h"
#include"Vehicle.h"

class Truck final: public Vehicle{
    private:
        double m_payloadTons;
    
    public:
        // constructor
        Truck() = delete; //default constructor is deleted
        Truck(const std::string& vin_, double payloadTons_);
        Truck(const Truck& other) = delete; // copy constructor is deleted

        // description overrided function
        std::string description() const override;

};

#endif // TRUCK_H
