#ifndef SHAREDTRIP_H
#define SHAREDTRIP_H

#include"Ride.h"
#include"Trip.h"
#include<iostream>
#include<string>

class SharedTrip: public Trip{
    private:
        int m_sharedTripPassengers;
    public:

        // constructors
        SharedTrip();
        SharedTrip(const std::string& tripId_, int tripDistance_, int tripRating_, int tripVehicleType_, int sharedPassesngers_);

        // Getters
        int getSharedTripPassengers() const;

        //setters
        void setSharedTripPassengers(int passengers_) ;

        // calculate fare 
        float calculateFare() const override;

        // checking is trip as per standard
        bool isTripAsPerStandard() const;

        // overlaoding << operator
        friend std::ostream& operator <<(std::ostream& out, const SharedTrip& other);

};

#endif // SHAREDTRIP_H
