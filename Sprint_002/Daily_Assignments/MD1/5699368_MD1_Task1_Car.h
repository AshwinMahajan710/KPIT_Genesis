#ifndef INC_5699368_MD1_TASK1_CAR_H
#define INC_5699368_MD1_TASK1_CAR_H

#include"5699368_MD1_Task1_Vehicle.h"

class Car: public Vehicle{
    private:
        int m_numDoors;
    
    public:
        // constructors
        Car() = default;
        Car(const std::string& vin_, int year_, int numDoors_);

        void runDiagnostics() const override;
        void displayInfo() const override;
};

#endif // INC_5699368_MD1_TASK1_CAR_H
