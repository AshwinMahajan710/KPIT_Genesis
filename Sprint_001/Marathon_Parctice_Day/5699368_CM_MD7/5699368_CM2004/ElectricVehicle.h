#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include<string>
#include"ElectricMotor.h"
#include<iostream>

class ElectricVehicle{
    private:
        std::string m_vehicleId;
        std::string m_vehicleModel;
        float m_batteryCapacity;
        ElectricMotor m_electricMotor;
    
    public:

        //default constructor
        ElectricVehicle();
        
        //parameterized constructor
        ElectricVehicle(const std::string& vehicleId_, const std::string& vehicleModel_, float batteryCapacity_, ElectricMotor electricMotor_);

        // getters
        std::string getVehicleId() const;
        std::string getVehicleModel() const;
        float getBatteryCapacity() const;
        ElectricMotor getElectricMotor() const;

        // setters
        void getVehicleId(const std::string& vehicleId_);
        void getVehicleModel(const std::string& vehicleModel_);
        void getBatteryCapacity(float batteryCapacity_);
        void getElectricMotor(ElectricMotor electricMotor_);

        // Overloading << operator to display vehicle details
        friend std::ostream& operator<<(std::ostream& out, const ElectricVehicle& other);

        // overloading + operator which will return sum of batterycapacities of 2 vehicles
        double operator +(const ElectricVehicle& other);
};


#endif // ELECTRICVEHICLE_H
