#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>

class Vehicle{
    private:
        std::string m_vehicleID;
        std::string m_fuelType;
        double m_fuelEfficiency;
        double m_totalDistanceTravelled;
        double m_totalFuelConsumed;
        static double s_averageFuelPrice; // static variable

    public:
        Vehicle();
        Vehicle(const std::string& vehicleID_, const std::string& fuelType_, double fuelEfficiency_);
        void trackFuelConsumption(double fuelConsumed_, double distanceTravelled_);
        double calculateFuelEconomy() const;
        void displayVehicleInfo() const;
        static void updateAverageFuelPrice(double newPrice_);
        static void updateAverageFuelPrice();
        double calculateTotalFuelCost(double distanceToTravel_) const;
};

#endif // VEHICLE_H
