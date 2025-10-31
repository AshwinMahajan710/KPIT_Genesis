#ifndef GARAGE_H
#define GARAGE_H

#include"VehicleState.h"
#include"Engine.h"
#include<string>
#include"FleetVehicle.h"
#include<vector>

class Garage{
    private:
        std::string m_location;
        std::vector<FleetVehicle> m_vehicles;
    public:

        // constructors 
        Garage() = default;
        Garage(const std::string& location_);

        // function to add vehicle
        void addVehicle(FleetVehicle&& vehicle);

        // function to get vehicles count
        int getVehiclesCount() const noexcept;

};

#endif // GARAGE_H
