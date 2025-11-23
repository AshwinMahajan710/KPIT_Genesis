#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
#include"SensorType.h"
#include"Sensor.h"
#include"ADASModule.h"
#include<memory>
#include<vector>
#include<iostream>

class Vehicle{
    public:
        std::string m_make{};
        std::string m_model{};
        int m_year{};
        std::vector<std::shared_ptr<ADASModule>> m_modules;
        
        // Constructors
        Vehicle();
        Vehicle(const std::string& make_, const std::string& model_, int year_);

        // method to add ADAS modules
        void addModules(std::shared_ptr<ADASModule>& module);
        friend std::ostream& operator<< (std::ostream& out, const Vehicle& other);
};

#endif // VEHICLE_H
