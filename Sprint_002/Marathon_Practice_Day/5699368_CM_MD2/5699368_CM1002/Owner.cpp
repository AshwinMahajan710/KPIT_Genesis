#include<string>
#include"VehicleSummary.h"
#include<vector>
#include"Owner.h"

Owner::Owner(const std::string& name_){
    m_name = name_;
}

void Owner::addVehicle(VehicleSummary *vehicle){
    if(vehicle!=nullptr){
        m_vehicles.push_back(vehicle);
    }
}

std::vector<std::string> Owner::lisVehicles() const noexcept{
    std::vector<std::string> breifs;

    for(auto i : m_vehicles){
        breifs.push_back(i->brief());
    }
    return breifs;
}

const std::string& Owner::getName() const noexcept{
    return m_name;
}