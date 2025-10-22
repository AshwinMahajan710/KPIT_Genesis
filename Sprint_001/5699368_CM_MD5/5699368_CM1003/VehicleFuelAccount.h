
// VehicleFuelAccount .h file

#ifndef VEHICLEFUELACCOUNT_H
#define VEHICLEFUELACCOUNT_H

// Class vehicle fuel account
class VehicleFuelAccount{
    private:
        double m_fuelBalance;
    public:
        static double s_fleetEfficiencyRate;
        VehicleFuelAccount(double fuelBalance_);
        void calculateMonthlyBonus() ;
        static void modifyEfficiencyRate(double newRate_);
        double getFuelBalance() const;
        void display() const;
};

#endif // VEHICLEFUELACCOUNT_H
