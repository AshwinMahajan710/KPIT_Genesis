
#ifndef TRIP_H
#define TRIP_H

#include<string>
#include"Ride.h"

class Trip{
    private:
        std::string m_tripId;
        std::string m_tripDriver;
        int m_tripDistance;
        int m_tripRating;
        Ride m_tripVehicleType;
    
    public:
        
        // default constructor
        Trip();
        Trip(const std::string& tripId_,
        const std::string& tripDriver_,
        int tripDistance_,
        int tripRating_,
        Ride tripVehicleType_);

        // Getters
        std::string getTripID() const;  
        std::string getTripDriver() const;
        int getTripDistance() const;
        int getTripRating() const;
        Ride getTripVehicleType() const;
        
        // Setters
        void setTripID(const std::string&);
        void setTripDriver(const std::string&);
        void setTripDistance(int );
        void setTripRating(int);
        void setTripVehicleType(Ride );
        
        // calculateArea --> pure virtual function
        virtual float calculateFare() const = 0;

        // helper functions
        virtual void printDetails() const;
        std::string getTripTypeName() const; // getting string val of trip type
};

#endif // TRIP_H
