#ifndef VEHICLEFLEET_H
#define VEHICLEFLEET_H

#include"EngineModule.h"
#include"EngineType.h"
#include"SensorModule.h"

class VehicleFleet{
    private:
        SensorModule* m_modules[100];
        int m_size{0};
    
    public: 
        //constructor
        VehicleFleet() = default;
        VehicleFleet(SensorModule& m, int size);
        
        // Replace modules with efficiency == 0 or ambientTemp > 140°C
        bool replaceFaultyModules(SensorModule* m);

        // getting average ambient temp
        float averageAmbientTemperature() const;

        // Add/Append new module to existing fleet
        void operator+=(SensorModule* m);

        // destructor   
        ~VehicleFleet();
    
};

#endif // VEHICLEFLEET_H
