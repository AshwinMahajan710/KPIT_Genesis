#ifndef SENSORMODULE_H
#define SENSORMODULE_H

#include"EngineModule.h"
#include"EngineType.h"

class VehicleFleet;// forward declaration

class SensorModule: public EngineModule{
    private:
        float m_ambientTemperatureInC{};
        
    public:
        //constructors
        SensorModule() = default;
        SensorModule(EngineModule* modulePtr_, float temperature_);
        SensorModule(int id, float rpm, float temperature, float efficiency, EngineType type, float ambientTemp);

        bool isModuleCritical() const; // – Returns true if output is 0
        void displayDetails() const override; // – Overrides base method to include ambient temperature
        float calculatePowerOutput() const override ; //– Applies temperature loss factor: EngineModule::calculatePowerOutput() × LossFactor
        
        // helper --> to get factor via low temp and high temp
        float getFactor(float lowTemp, float highTemp, float temp) const;
        
        // destructor
        ~SensorModule();

        // creating vehicleFleet class as base
        friend class VehicleFleet;
};

#endif // SENSORMODULE_H
