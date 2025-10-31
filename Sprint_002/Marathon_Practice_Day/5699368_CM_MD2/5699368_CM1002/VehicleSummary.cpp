#include"VehicleSummary.h"
#include<string>

// constructor
VehicleSummary::VehicleSummary(VIN vin_){
    m_vin = vin_;
}

// returning the string with info
std::string VehicleSummary::brief() const noexcept{
    return ("\nVIN: " + m_vin);
}