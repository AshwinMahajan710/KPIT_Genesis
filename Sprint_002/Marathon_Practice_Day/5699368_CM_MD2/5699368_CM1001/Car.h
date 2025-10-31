#ifndef CAR_H
#define CAR_H

#include<string>
#include"VehicleType.h"
#include"Vehicle.h"

class Car final: public Vehicle{
    private:
        int m_seatCount;
    
    public:
        // constructor
        Car() = delete; //default constructor is deleted
        Car(const std::string& vin_, int seatCount_);
        Car(const Car& other) = delete; // copy constructor is deleted

        // description overrided function
        std::string description() const override;

};

#endif // CAR_H
