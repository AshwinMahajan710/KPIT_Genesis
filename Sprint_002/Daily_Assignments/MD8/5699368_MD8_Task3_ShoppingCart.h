#ifndef INC_5699368_MD8_TASK3_SHOPPINGCART_H
#define INC_5699368_MD8_TASK3_SHOPPINGCART_H

#include<string>

class ShoppingCart{
    public:
        int m_cartId{};
        int m_averageOrderSize{};
        int m_currItems{};
        std::string m_customerName{};
        double m_totalCost{};

        ShoppingCart() = default;
        ShoppingCart(int id_, int averageOrderSize_,const std::string& customerName_);

        void removeItems(); // simulating items removal by fixed size. and print removal details
        void addItem(int quantity_, double price_);
        void displayDetails() const;

        void applyDiscount(double discountPercentage_);
        
};

#endif // INC_5699368_MD8_TASK3_SHOPPINGCART_H
