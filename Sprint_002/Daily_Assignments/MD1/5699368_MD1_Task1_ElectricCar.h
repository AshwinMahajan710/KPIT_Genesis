#ifndef INC_5699368_MD1_TASK1_ELECTRICCAR_H
#define INC_5699368_MD1_TASK1_ELECTRICCAR_H

#include"5699368_MD1_Task1_Vehicle.h"

class ElectricCar: public Vehicle{
    private:
        double m_batteryHealth;
    
    public:
        // constructors
        ElectricCar() = default;
        ElectricCar(const std::string& vin_, int year_, int batterHealth_);

        void runDiagnostics() const override final;
        void displayInfo() const override;
};

#endif // INC_5699368_MD1_TASK1_ELECTRICCAR_H
