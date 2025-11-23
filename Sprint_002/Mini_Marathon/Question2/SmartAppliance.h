#ifndef SMARTAPPLIANCE_H
#define SMARTAPPLIANCE_H

#include<string>
#include"Status.h"

class SmartAppliance{
    private:
        int m_id{};
        std::string m_name{};
        Status m_status{};
        double m_discount{}; //: Promotional discount (must be between 0.0–25.0)        

    public:

        // constrcutors
        SmartAppliance() = default;
        SmartAppliance(int id_, const std::string& name_, Status status_, double discount_);

        // deleted copy constructor and copy assignment
        SmartAppliance(const SmartAppliance&) = delete;
        SmartAppliance& operator=(const SmartAppliance&) = delete;

        // move constructor and move assignment
        SmartAppliance(SmartAppliance&&);
        SmartAppliance& operator=(SmartAppliance&&);

        // display method to display values
        void display() const;

        // getter for discount, name, Status
        double getDiscount() const;
        std::string getName() const;
        Status getStatus() const;

        // setter for discount value
        void setDiscount(double newDiscount);
        
        // helper --> get Status string
        std::string getStatusString() const; 

};

#endif // SMARTAPPLIANCE_H
