#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
#include"VEHICLE_TYPE.h"
#include"TRANSMISSION_TYPE.h"
#include"FUEL_TYPE.h"

class Vehicle{
    private:
        std::string m_make{};
        std::string m_model{};
        int m_year{};
        VEHICLE_TYPE m_type {} ;
        FUEL_TYPE m_fuelType{};
        TRANSMISSION_TYPE m_transmissionType{};
        float m_purchasePrice{};

    public:
        Vehicle() = default;
        Vehicle(const std::string& make_, const std::string& model_, int year_, VEHICLE_TYPE type_, FUEL_TYPE fuelType_, TRANSMISSION_TYPE transmissionType_, float price_);

        // getters
        std::string getMake() const;
        std::string getModel() const;
        int getYear() const;
        VEHICLE_TYPE getType () const;
        FUEL_TYPE getFuelType() const;
        TRANSMISSION_TYPE geTransmissionType() const;
        float getPurchasePrice() const;
        
        // setters
        void setMake(const std::string& make_) ;
        void setModel(const std::string& model_) ;
        void setYear(int year_) ;
        void setType (VEHICLE_TYPE type_) ;
        void setFuelType(FUEL_TYPE fuelType_) ;
        void seTransmissionType(TRANSMISSION_TYPE transmissionType_) ;
        void setPurchasePrice(float price_) ;

        // helper --> het vehicleType string
        std::string getVehicleTypeName() const;
        // helper --> het fuelType string
        std::string getFuelTypeName() const;
        // helper --> het transmissionType string
        std::string getTransmissionTypeString() const;

        // helper display details function
        void display() const;

};

#endif // VEHICLE_H
