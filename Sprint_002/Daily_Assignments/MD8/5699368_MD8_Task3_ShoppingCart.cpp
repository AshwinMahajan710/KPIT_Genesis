#include"5699368_MD8_Task3_ShoppingCart.h"
#include<string>
#include<iostream>
#include<mutex>

// constructor --> parametrized
ShoppingCart::ShoppingCart(int id_, int averageOrderSize_,const std::string& customerName_): m_cartId(id_), m_averageOrderSize(averageOrderSize_), m_customerName(customerName_), m_currItems(0), m_totalCost(0){}

// simulating items removal by fixed size. and print removal details
void ShoppingCart::removeItems(){
    int fixed_removal_size = 5;
    if(m_currItems - fixed_removal_size < 0){std::cout<<"\nLess items not possible.."<<std::endl;}
    else{
        m_totalCost = m_totalCost - (fixed_removal_size*(m_totalCost/m_currItems));
        m_currItems -= fixed_removal_size;
        std::cout<<"\nAvailable items now: "<<m_currItems<<" their total cost: "<<m_totalCost<<std::endl;
    }
}

// adding items
void ShoppingCart::addItem(int quantity_, double price_){
    m_currItems += quantity_;
    m_totalCost += quantity_ * price_;
}

// display details function
void ShoppingCart::displayDetails() const{
    std::cout<<"\nName: "<<m_customerName<<std::endl;
    std::cout<<"Average order size: "<<m_averageOrderSize<<std::endl;
    std::cout<<"Cart ID: "<<m_cartId<<std::endl;
    std::cout<<"Current Items: "<<m_currItems<<std::endl;
    std::cout<<"Total Cost: "<<m_totalCost<<std::endl;
}

// function to apply discount
void ShoppingCart::applyDiscount(double discountPercentage_){
    if(m_currItems == 0){
        std::cout<<"\nCart is already empty.\n";
        return;
    }
    m_totalCost = m_totalCost - (m_totalCost*discountPercentage_/100); 
}