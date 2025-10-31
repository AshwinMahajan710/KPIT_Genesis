#ifndef INC_5699368_MD1_TASK2_VEHICLE_H
#define INC_5699368_MD1_TASK2_VEHICLE_H

#include<string>

class Vehicle{
    private:
        std::string m_vin;
        int m_year;
    
    public:
        //constructors
        Vehicle();
        Vehicle(const std::string& vin_, int year_);
        void show() const; // printing basic info
};

#endif // INC_5699368_MD1_TASK1_VEHICLE_H
