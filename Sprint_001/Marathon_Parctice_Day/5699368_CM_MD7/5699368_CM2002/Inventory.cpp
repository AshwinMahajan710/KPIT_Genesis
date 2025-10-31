#include"Inventory.h"
#include<iostream>
#include<stdexcept>
#include<string>

// default constructor --> initializing with default values
Inventory::Inventory() : Inventory("",20,0){}; 

// parameterized constructor --> initialize with particular values
Inventory::Inventory(const std::string& descriptionOfProduct_, int balanceStock_, int productCode_){
    
    // validate balanceStock_ first
    if(balanceStock_<20) {throw std::invalid_argument("InvalidStockValueException: \"Min balance Stock value should be 20 ...\"");}
    else {m_balanceStock = balanceStock_;}

    // Now assign remaining things
    m_descriptionOfProduct = descriptionOfProduct_;
    m_productCode = productCode_;
}

// purchase function --> adding stock to existing stock value
void Inventory::purchase(int qty_){
    // validate the qty 
    if(qty_ <= 0) {throw std::invalid_argument("InvalidQuantityException: \"Purchase quantity should be greater than 0...\"");}
    else {
        m_balanceStock += qty_;
        std::cout<<"\nNew Balance stock after purchasing stock: "<<m_balanceStock<<std::endl;
    }
}

// sale function --> subtracting stock from existing stock value
void Inventory::sale(int qty_){
    // validate the qty 
    if(qty_<=0) {throw std::invalid_argument("InvalidQuantityException: \"Sale quantity should be greater than 0...\"");}
    else if((m_balanceStock - qty_)<20) {throw std::invalid_argument("InvalidQuantityException: \"unsufficient quantity to fulfill the sale...\"");}
    else {
        m_balanceStock -= qty_;
        std::cout<<"\nNew Balance stock after saling stock: "<<m_balanceStock<<std::endl;
    }
}

// Helper function --> to display product details
void Inventory::displayProductDetails() const{
    std::cout<<"\nProduct Code: "<<m_productCode<<std::endl;
    std::cout<<"Product Description: "<<m_descriptionOfProduct<<std::endl;
    std::cout<<"Product Balance Stock: "<<m_balanceStock<<std::endl;
}

// helper getter function --> to get product code
int Inventory::getProductCode() const{
    return m_productCode;
}


