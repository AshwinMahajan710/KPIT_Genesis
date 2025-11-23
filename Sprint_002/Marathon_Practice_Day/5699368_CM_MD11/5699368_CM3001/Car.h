#ifndef CAR_H
#define CAR_H

#include<string>
#include"CAR_CATEGORY.h"
#include<iostream>

class Car{
    private:
        std::string m_carChasisNumber{};
        std::string m_carBrand{};
        std::string m_carModel{};
        CAR_CATEGORY m_carCategory{};
        float m_carPrice{};
        int m_carSeatCount{};
        int m_carFuelCapacity{};

    public:

        // constructors
        Car() = delete;
        Car(const std::string& no_,const std::string& brand_, const std::string& model_, CAR_CATEGORY category_, float price_, int seatCount_, int capacity_);
        Car(const std::string& no_,const std::string& brand_, const std::string& model_, float price_);

        // copy assignment and copy constructor defaulted
        Car(const Car&) = default;
        Car& operator =(const Car&) = default;

        // overload << to display details
        friend std::ostream& operator<<(std::ostream& out, const Car& other);

        // getters
        std::string getChassisNumber() const;
        std::string getBrand() const;
        std::string getModel() const;
        CAR_CATEGORY getCarCategory() const;
        float getPrice() const;
        int getSeatCount() const;
        int getFuelCapacity() const;

        // getters
        void setChassisNumber(const std::string& no_);
        void setBrand(const std::string& brand_);
        void setModel(const std::string& model_);
        void setCarCategory(CAR_CATEGORY category_);
        void setPrice(float price_);
        void setSeatCount(int seatCount_);
        void setFuelCapacity(int fuelCapacity_);

        // helper --> get enum class category names
        std::string categoryName() const;
};

#endif // CAR_H
