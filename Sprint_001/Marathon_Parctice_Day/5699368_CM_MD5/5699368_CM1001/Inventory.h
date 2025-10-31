
// Inventory .h file

#ifndef INVENTORY_H
#define INVENTORY_H

#include<string>

// class Inventory --> Inventory management base class
class Inventory{
    private:
        std::string m_descriptionOfProduct;
        int m_balanceStock;
        int m_productCode;
    public:

        // constructors
        Inventory();
        Inventory(const std::string& description_, int balanceStock_, int productCode_);
        Inventory(int balanceStock_); // constructor to initialize object only using balanceStock

        // purchase function to add product quantity to current stock
        void purchase(int purchaseVal_);

        // reduce function to reduce product quantity from current stock
        void sale(int saleVal_);

        // HELPER: printing details of product 
        void printDetails()const;

        // getter for product Code --> used in search (Global) function
        int getProductCode() const;
};

#endif // INVENTORY_H
