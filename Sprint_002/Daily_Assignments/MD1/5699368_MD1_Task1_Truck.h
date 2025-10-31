#ifndef INC_5699368_MD1_TASK1_TRUCK_H
#define INC_5699368_MD1_TASK1_TRUCK_H

#include"5699368_MD1_Task1_Vehicle.h"

class Truck: public Vehicle{
    private:
        double m_payloadCapacity;
    
    public:
        // constructors
        Truck() = default;
        Truck(const std::string& vin_, int year_, double payloadCapacity_);

        void runDiagnostics() const override;
        void displayInfo() const override;
};


#endif // INC_5699368_MD1_TASK1_TRUCK_H
