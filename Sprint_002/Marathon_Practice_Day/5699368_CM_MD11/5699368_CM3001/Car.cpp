#include<string>
#include"CAR_CATEGORY.h"
#include<iostream>
#include"Car.h"

// parametrized constructor --> full attributes
Car::Car(const std::string& no_,const std::string& brand_, const std::string& model_, CAR_CATEGORY category_, float price_, int seatCount_, int capacity_): m_carChasisNumber(no_), m_carBrand(brand_), m_carCategory(category_), m_carModel(model_), m_carPrice(price_), m_carSeatCount(seatCount_), m_carFuelCapacity(capacity_){};

// parameterized constructor --> some arguments
Car::Car(const std::string& no_,const std::string& brand_, const std::string& model_, float price_):m_carChasisNumber(no_), m_carBrand(brand_), m_carModel(model_), m_carPrice(price_){}

// overload << to display details
std::ostream& operator<<(std::ostream& out, const Car& other){
    out<<"Chasis No: "<<other.m_carChasisNumber<<std::endl;
    out<<"Brand : "<<other.m_carBrand<<std::endl;
    out<<"Model : "<<other.m_carModel<<std::endl;
    out<<"Car Category: "<<other.categoryName()<<std::endl;
    out<<"Car Price: "<<other.m_carPrice<<std::endl;
    out<<"Car Seat count: "<<other.m_carSeatCount<<std::endl;
    out<<"Fuel Capacity: "<<other.m_carFuelCapacity<<std::endl;
    return out;
}

// getters
std::string Car::getChassisNumber() const{
    return m_carChasisNumber;
}
std::string Car::getBrand() const{
    return m_carBrand;
}
std::string Car::getModel() const{
    return m_carModel;
}
CAR_CATEGORY Car::getCarCategory() const{
    return m_carCategory;
}
float Car::getPrice() const{
    return m_carPrice;
}
int Car::getSeatCount() const{
    return m_carSeatCount; 
}
int Car::getFuelCapacity() const{
    return m_carFuelCapacity; 
}

// getters
void Car::setChassisNumber(const std::string& no_){
    m_carChasisNumber = no_;
}
void Car::setBrand(const std::string& brand_){
    m_carBrand = brand_;
}
void Car::setModel(const std::string& model_){
    m_carModel = model_;
}
void Car::setCarCategory(CAR_CATEGORY category_){
    m_carCategory = category_;
}
void Car::setPrice(float price_){
    m_carPrice = price_;
}
void Car::setSeatCount(int seatCount_){
    m_carSeatCount = seatCount_;
}
void Car::setFuelCapacity(int fuelCapacity_){
    m_carFuelCapacity = fuelCapacity_;
}

// helper function to get category name
std::string Car::categoryName() const{
    if(m_carCategory == CAR_CATEGORY::SEDAN){return "Sedan";}
    else if(m_carCategory == CAR_CATEGORY::SPORTS_HATCHBACK){return "Sports Hatchback";}
    else {return "SUV";}  
}