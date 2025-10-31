#ifndef INC_5699368_MD1_TASK1_VEHICLE_H
#define INC_5699368_MD1_TASK1_VEHICLE_H

#include<string>

class Vehicle{
    private:
        std::string m_vin;
        int m_year;
    
    public:
        //constructors
        Vehicle() = default;
        Vehicle(const std::string& vin_, int year_);
        virtual void displayInfo() const; // printing basic info

        // virtual function
        virtual void runDiagnostics() const;
};

#endif // INC_5699368_MD1_TASK1_VEHICLE_H
