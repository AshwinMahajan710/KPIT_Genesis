
// Vehicle .h file

#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"VehicleType.h"

constexpr int MAX_TESTS_COUNT = 5;

// class vehicle
class Vehicle{
    private:
        int* m_testScores;
        unsigned int m_numberOfTestRuns;
        char* m_vehicleID;
        VehicleType m_type;
    
    public:
        
        // constructors
        Vehicle();
        Vehicle(unsigned int n_);
        Vehicle(const Vehicle& other_);

        // desctructor
        ~Vehicle();

        // Operators to overload
        bool operator==(const Vehicle& other_) const;
        Vehicle& operator=(const Vehicle& other_);
        int operator[](int index_) const;
        friend std::ostream& operator<<(std::ostream& out, const Vehicle& other_);
        friend std::istream& operator>>(std::istream& in, Vehicle& other_);

        // getters
        unsigned int getNumberOfTestRuns() const;
        const int* getTestScores() const ;
        VehicleType getVehicleType() const;
        
        // HELPER FUNCTION: to get string val of enum type
        std::string getVehicleTypeString() const;
};

#endif // VEHICLE_H
