#ifndef INDIVIDUALTRIP_H
#define INDIVIDUALTRIP_H

#include"Trip.h"

class IndividualTrip: public Trip{
    private:  
        int m_individualTripDuration;
    public: 

        // constructors
        IndividualTrip();
        IndividualTrip(const std::string& tripId_, const std::string& tripDriver_, int tripDistance_, int tripRating_, Ride tripVehicleType_,int duration_);

        // getters
        int getIndividualTripDuration() const;

        // setters
        void getIndividualTripDuration(int );

        // calculating fare
        float calculateFare() const;
        float calculateFare(float surcharge_)const; // with surcharge

        // checking is Trip as per standards
        bool isTripAsPerStandard() const;

        // helper function
        void printDetails() const override ;
};

#endif // INDIVIDUALTRIP_H
