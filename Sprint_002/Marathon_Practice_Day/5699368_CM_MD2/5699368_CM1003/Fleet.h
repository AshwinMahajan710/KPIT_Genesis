#ifndef FLEET_H
#define FLEET_H
#include"VehicleState.h"
#include"Engine.h"
#include<string>
#include"FleetVehicle.h"
#include<vector>
#include"Garage.h"

class Fleet{
    private:
        std::vector<Garage> m_garages;
    public:
        Fleet() = default;

        // function to add garage
        void addGarage(Garage&& garage_);

        // function to calculate total vehicles in all garages
        int totalVehicles() const noexcept;

};

#endif // FLEET_H
