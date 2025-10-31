#ifndef SHAREDTRIP_H
#define SHAREDTRIP_H

#include"Ride.h"
#include"Trip.h"

class SharedTrip: public Trip{
    private:
        int m_sharedTripPassengers;
    public:

        // constructors
        SharedTrip();
        SharedTrip(const std::string& tripId_, const std::string& tripDriver_, int tripDistance_, int tripRating_, Ride tripVehicleType_, int sharedPassesngers_);

        // Getters
        int getSharedTripPassengers() const;

        //setters
        void setSharedTripPassengers(int passengers_) ;

        // calculate fare 
        float calculateFare() const override;

        // checking is trip as per standard
        bool isTripAsPerStandard() const;

        // helper function
        void printDetails() const override;

};

#endif // SHAREDTRIP_H
