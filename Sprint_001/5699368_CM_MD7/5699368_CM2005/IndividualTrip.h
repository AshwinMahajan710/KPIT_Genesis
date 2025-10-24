#ifndef INDIVIDUALTRIP_H
#define INDIVIDUALTRIP_H

#include"Trip.h"
#include"Ride.h"
#include<iostream>
#include<string>

class IndividualTrip: public Trip{
    private:  
        int m_individualTripDuration;
    public: 

        // constructors
        IndividualTrip();
        IndividualTrip(const std::string& tripId_, int tripDistance_, int tripRating_, int tripVehicleType_,int duration_);

        // getters
        int getIndividualTripDuration() const;

        // setters
        void getIndividualTripDuration(int duration_);

        // calculating fare
        float calculateFare() const override;

        // checking is Trip as per standards
        bool isTripAsPerStandard() const;

        // overloading << to display details
        friend std::ostream& operator <<(std::ostream& out, const IndividualTrip& other);
};

#endif // INDIVIDUALTRIP_H
