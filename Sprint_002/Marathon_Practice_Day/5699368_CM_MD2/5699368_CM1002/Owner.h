#ifndef OWNER_H
#define OWNER_H

#include<string>
#include"VehicleSummary.h"
#include<vector>

class Owner{
    private:
        std::string m_name;
        std::vector<VehicleSummary*> m_vehicles;

    public:
        Owner() = delete;
        Owner(const std::string& name_);
        Owner(const Owner& other) = delete;
        Owner& operator =(const Owner& other) = delete;
        Owner(Owner&& ) = delete;

        void addVehicle(VehicleSummary *vehicle);
        std::vector<std::string> lisVehicles() const noexcept;

        // getter
        const std::string& getName() const noexcept; 
};
#endif // OWNER_H
