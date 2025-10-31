
// Inventory .cpp file

#include<iostream>
#include<string>
#include<stdexcept>
#include"Inventory.h"

constexpr int MIN_STOCK_QTY = 20;

// default constructor --> deligated to parameterized constructor
Inventory::Inventory() : Inventory("",MIN_STOCK_QTY,00){};

// parameterized constructor
Inventory::Inventory(const std::string& description_, int balanceStock_, int productCode_): m_descriptionOfProduct(description_), m_productCode(productCode_){
    if(balanceStock_ < MIN_STOCK_QTY){
        throw std::invalid_argument("\nMin Product Stock size is 20 ... Can never be less than 20..");
    }
    else{
        m_balanceStock = balanceStock_;
    }
}

// Parametrized constructor only for balanceStock --> initializing object only using one param
Inventory::Inventory(int balanceStock_) : Inventory("",balanceStock_,0){}

// purchase stock function --> adding new stock qty to existing qty
void Inventory::purchase(int purchaseVal_){
    m_balanceStock += purchaseVal_; // adding quanity to existing stock val
    std::cout<<"After purchase stock : "<<m_balanceStock<<std::endl;
}

// reduce stock function --> reducing stock qty from existing qty
void Inventory::sale(int saleVal_){
    if((m_balanceStock - saleVal_) < MIN_STOCK_QTY){
        throw std::invalid_argument("Exception: \"Low Stock Level\"");
    }
    else{
        m_balanceStock -= saleVal_; // reduce the stockQty
        std::cout<<"After sale stock: "<<m_balanceStock<<std::endl;
    }
}

// HELPER Function :- printing productn details in inventory
void Inventory::printDetails() const{
    std::cout<<"Product description: "<<m_descriptionOfProduct<<std::endl;
    std::cout<<"Stock in balance: "<<m_balanceStock<<std::endl;
    std::cout<<"Product code: "<<m_productCode<<std::endl;
}

// Getting product code
int Inventory::getProductCode() const{
    return m_productCode;
}