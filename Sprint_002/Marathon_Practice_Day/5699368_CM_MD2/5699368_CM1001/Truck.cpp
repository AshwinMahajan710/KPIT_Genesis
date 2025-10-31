#include<string>
#include"VehicleType.h"
#include"Vehicle.h"
#include"Truck.h"

// constructor --> parameterized
Truck::Truck(const std::string& vin_, double payloadTons_): Vehicle(vin_, VehicleType::TRUCK){
    m_payloadTons = payloadTons_;    
}


// description overrided function
std::string Truck::description() const {
    return (static_cast<std::string>("Truck --> Vin: ") + getVin() + "  Payload Capacity: " + std::to_string(m_payloadTons));
}

