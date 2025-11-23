#include"5699368_MD8_Task3_ShoppingCart.h"
#include<string>
#include<iostream>
#include<vector>
#include<thread>
#include"5699368_MD8_Task3_ShoppingCartManagementSystem.h"
#include<mutex>

std::mutex mtx;

// adding cart
void ShoppingCartManagementSystem::addCart(const ShoppingCart& cart){
    m_carts.push_back(cart);
}

// simulating item removal
void ShoppingCartManagementSystem::simulateItemRemoval(){
    std::lock_guard<std::mutex> lock(mtx);
    for(auto &cart: m_carts){
        cart.removeItems();
    }
}

// increasing stock level
void ShoppingCartManagementSystem::restockItems(){
    std::lock_guard<std::mutex> lock(mtx);
    int fixed_restock_size = 5;
    for(auto &cart: m_carts){
        cart.addItem(fixed_restock_size, 50);
    }
}

// displaying stock level
void ShoppingCartManagementSystem::displayStockLevel() const{
    std::cout<<"\nCurrent Stock level: "<<m_stockLevel<<std::endl;
}

// update and display totalReveneue
void ShoppingCartManagementSystem::displayTotalRevenue(){
    double cost = 0;
    for(auto &cart: m_carts){
        cost += cart.m_totalCost;
    }
    m_totalRevenue = cost;
}

// generating report
void ShoppingCartManagementSystem::generateReport() {
    m_totalRevenue = 0;
    for(auto &cart: m_carts){
        m_totalRevenue += cart.m_totalCost;
    }
    std::cout<<"\nStock Level: "<<m_stockLevel<<std::endl;
    std::cout<<"\nTotal Revenue: "<<m_totalRevenue<<std::endl;
}