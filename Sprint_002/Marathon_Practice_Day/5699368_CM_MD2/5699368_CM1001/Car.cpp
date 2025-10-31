#include<string>
#include"VehicleType.h"
#include"Vehicle.h"
#include"Car.h"

// constructor --> parameterized
Car::Car(const std::string& vin_, int seatCount_): Vehicle(vin_, VehicleType::CAR){
    m_seatCount = seatCount_;    
}


// description overrided function
std::string Car::description() const {
    return (static_cast<std::string>("Car --> Vin: ") + getVin() + "  Seat Count: " + std::to_string(m_seatCount));
}

