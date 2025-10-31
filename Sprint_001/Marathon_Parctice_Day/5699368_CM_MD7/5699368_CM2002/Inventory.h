#ifndef INVENTORY_H
#define INVENTORY_H

#include<string>

class Inventory{
    private:
        std::string m_descriptionOfProduct;
        int m_balanceStock;
        int m_productCode;
    
    public:
        Inventory(); // default constructor
        Inventory(const std::string& descriptionOfProduct_, int balanceStock_, int productCode_); // parameterized constructor
        void purchase(int qty_); // to purchase product
        void sale(int qty_); // to sale product

        // Helper function --> to display product details
        void displayProductDetails() const;

        // helper getter function --> to get product code
        int getProductCode() const;

};

#endif // INVENTORY_H
