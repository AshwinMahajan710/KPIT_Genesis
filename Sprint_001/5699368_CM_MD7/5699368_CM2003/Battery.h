#ifndef BATTERY_H
#define BATTERY_H

#include<string>
#include<iostream>

class Battery{
    private:
        int m_batteryId;
        std::string m_batteryType;
        std::string m_manufacturer;
        double m_capacity;
        double m_voltage;
    
    public:

        // parameterized constructor
        Battery(int batteryId_, const std::string& batteryType_, const std::string& manufacturer_, double capacity_, double voltage_);

        // getters
        int getBatteryId() const;
        std::string getBatteryType() const;
        std::string getManufacturer() const;
        double getCapacity() const;
        double getVoltage() const;

        // setters
        void setBatteryId(int batteryId_);
        void setBatteryType(const std::string& batteryType_);
        void setManufacturer(const std::string& manufacturer_);
        void setCapacity(double capacity_);
        void setVoltage(double voltage_);

        // overloading << operator to print battery details
        friend std::ostream& operator <<(std::ostream& out, const Battery& other);
};

#endif // BATTERY_H
