#include<string>
#include"5699368_MD12_Task3_Product.h"
#include<stdexcept>
#include<iostream>

// constructor --> default (delegated)
Product::Product(): Product(0,"Unknown",0.0){};

// constructor --> parameterized ( with price validation)
Product::Product(int id_, const std::string& name_, double price_): m_id(id_), m_name(name_){
    if(price_<0) {throw std::runtime_error("InvalidPriceException..");}
    else {m_price = price_;}
};

// move constructor
Product::Product(Product&& other): m_id(other.m_id), m_price(m_price){
    m_name = std::move(other.m_name);
}

// move assignment
Product& Product:: operator=(Product&& other){
    if(this != &other){
        m_id = other.m_id;
        m_name = std::move(other.m_name);
        m_price = other.m_price;
    }
    return *this;
}

// getters
int Product::getId() const{
    return m_id;
}

std::string Product::getName() const{
    return m_name;
}
double Product::getPrice() const{
    return m_price;
}

// setters
void Product::setId(int id_) {
    m_id = id_;
}
void Product::setName(const std::string& name_) {
    m_name = name_;
}
void Product::setPrice(double price_){
    if(price_<0) {throw std::runtime_error("InvalidPriceException..");}
    else {m_price = price_;}
}

// display method
void Product::display() const{
    std::cout<<"\nProduct ID: "<<m_id<<std::endl;
    std::cout<<"Product Name: "<<m_name<<std::endl;
    std::cout<<"Product price: "<<m_price<<std::endl;
}