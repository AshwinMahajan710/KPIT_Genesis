#ifndef TRIP_H
#define TRIP_H

#include"Ride.h"
#include<string>
#include<iostream>

class Trip{
    private:
        std::string m_tripId;
        int m_tripDistance;
        int m_tripRating;
        Ride m_tripVehicleType;
    
    public:

        // constructors
        Trip();
        Trip(const std::string& tripId_, int tripDistance_, int tripRating_, int tripVehicleType_);

        // getters
        std::string getTripId() const;
        int getTripDistance() const;
        int getTripRating() const;
        Ride getTripVehicleType() const;

        //setters
        void setTripId(const std::string& tripId_);
        void setTripDistance(int tripDistance_);
        void setTripRating(int tripRating_);
        void setTripVehicleType(int tripVehicleType_);

        // overloading << to display details 
        friend std::ostream& operator<<(std::ostream& out,const Trip& other);
        
        // pure virtual function calculate fare
        virtual float calculateFare() const = 0;

        // Helper function --> get string of Ride type
        std::string getRideString() const;
};

#endif // TRIP_H
