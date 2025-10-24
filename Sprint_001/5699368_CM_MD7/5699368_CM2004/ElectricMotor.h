#ifndef ELECTRICMOTOR_H
#define ELECTRICMOTOR_H

#include<iostream>

class ElectricMotor{
    private:
        float m_maxPower;
        int m_maxTorque;
    
    public:

        // constructors
        ElectricMotor();
        ElectricMotor(float maxPower_, int maxTorque_);

        // getters
        float getMaxPower() const;
        int getMaxTorque() const;

        // setters
        void setMaxPower(float maxPower_);
        void setMaxTorque(float maxTorque_);

        // overloading << operator to display details
        friend std::ostream& operator << (std::ostream& out, const ElectricMotor& other);
};

#endif // ELECTRICMOTOR_H
