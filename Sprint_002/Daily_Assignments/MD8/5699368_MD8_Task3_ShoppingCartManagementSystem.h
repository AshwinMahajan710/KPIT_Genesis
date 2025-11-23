#ifndef INC_5699368_MD8_TASK3_SHOPPINGCARTMANAGEMENTSYSTEM_H
#define INC_5699368_MD8_TASK3_SHOPPINGCARTMANAGEMENTSYSTEM_H

#include"5699368_MD8_Task3_ShoppingCart.h"
#include<string>
#include<iostream>
#include<vector>
#include<thread>

class ShoppingCartManagementSystem{
    private:
        std::vector<ShoppingCart> m_carts;
        int m_stockLevel{};
        double m_totalRevenue{};
    public:
        ShoppingCartManagementSystem() = default;
        void addCart(const ShoppingCart& cart);
        void simulateItemRemoval();
        void restockItems(); // increasing stock level
        void displayStockLevel() const;
        void displayTotalRevenue() ;
        void generateReport() ;         
};

#endif // INC_5699368_MD8_TASK3_SHOPPINGCARTMANAGEMENTSYSTEM_H
