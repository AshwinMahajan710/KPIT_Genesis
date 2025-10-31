#include"VehicleState.h"
#include"Engine.h"
#include<string>
#include"FleetVehicle.h"
#include<iostream>

// constructor --> default
FleetVehicle::FleetVehicle(const std::string& id_, int horsePower_): FleetVehicle(id_, std::move(Engine(horsePower_))){}

// constructor --> parameterized
FleetVehicle::FleetVehicle(const std::string& id_, Engine&& engine_) : m_id(id_), m_engine(std::move(engine_)){};

// to display
std::string FleetVehicle:: display(){
    return (static_cast<std::string>("\nID: ") + m_id + "  State: " + getStateName() + "  HP: " + std::to_string(m_engine.getHP()));
}

// setter
void FleetVehicle::setState(VehicleState&& state_){
    m_state = state_;
}

// getter
int FleetVehicle::getHP() const noexcept{
    return m_engine.getHP();
}

std::string FleetVehicle::getStateName() const{
    switch (m_state)
    {
        case VehicleState::INTRANSIT:{
            return "Intransit";
            break;
        }
        case VehicleState::MAINTAINANCE:{
            return "Maintainance";
            break;
        }
        case VehicleState::PARKED:{
            return "Parked";
            break;
        }
    }
    return "";
}