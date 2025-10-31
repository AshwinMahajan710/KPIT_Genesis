#ifndef VEHICLESUMMARY_H
#define VEHICLESUMMARY_H

#include<string>

using VIN = std::string ;

class VehicleSummary{
    private:   
        VIN m_vin;
    
    public:
        VehicleSummary() = default; // setting defaul constructor to default
        VehicleSummary(VIN vin_);
        std::string brief() const noexcept;
};

#endif // VEHICLESUMMARY_H
