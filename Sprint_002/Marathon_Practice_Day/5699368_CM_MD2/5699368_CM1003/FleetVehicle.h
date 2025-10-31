#ifndef FLEETVEHICLE_H
#define FLEETVEHICLE_H

#include"VehicleState.h"
#include"Engine.h"
#include<string>

class FleetVehicle{
    private:
        std::string m_id;
        VehicleState m_state;
        Engine m_engine;

    public:

        // constructor
        FleetVehicle() = default;
        FleetVehicle(const std::string& id_, int horsePower_);
        FleetVehicle(const std::string& id_, Engine&& engine_);

        // to display
        std::string display();

        // setter
        void setState(VehicleState&& state_);

        // getter
        int getHP() const noexcept;

        // helper to get enum state as string
        std::string getStateName() const; 
};

#endif // FLEETVEHICLE_H
