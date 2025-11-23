#ifndef TOTALCOSTOFOWNERSHIP_H
#define TOTALCOSTOFOWNERSHIP_H

#include"Vehicle.h"
#include"Registration.h"
#include"Maintainance.h"
#include"Insuarance.h"

class TotalCostOfOwnership
{
    private:
        Vehicle m_vehicle;
        Registration m_registration;
        Maintainance m_maintainance;
        Insuarance m_insuarance;

    public:
        TotalCostOfOwnership() = default;
        TotalCostOfOwnership(Vehicle vehicle_,Registration registration_,Maintainance maintainance_,Insuarance insuarance_);

        // getters
        const Vehicle& getVehicle() const;
        const Registration& getRegistration () const;
        const Maintainance& geMtaintainance () const;
        const Insuarance& getInsuarance () const;

        //setters
        void setVehicle(Vehicle vehicle_);
        void setRegistration(Registration registration_);
        void setMaintainance(Maintainance maintainance_);
        void setInsuarance(Insuarance insuarance_);

};



#endif // TOTALCOSTOFOWNERSHIP_H
