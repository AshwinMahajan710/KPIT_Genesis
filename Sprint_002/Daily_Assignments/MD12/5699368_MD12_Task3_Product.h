#ifndef INC_5699368_MD12_TASK3_PRODUCT_H
#define INC_5699368_MD12_TASK3_PRODUCT_H

#include<string>

class Product{
    private:
        int m_id{};
        std::string m_name{};
        double m_price{};

    public:
        Product();

        // price validation
        Product(int id_, const std::string& name_, double m_price);
        Product(const Product&) = delete;
        Product& operator=(const Product&) = delete;
        Product(Product&&);
        Product& operator=(Product&&);

        // getters
        int getId() const;
        std::string getName() const;
        double getPrice() const;

        // setters
        void setId(int id_) ;
        void setName(const std::string& name_) ;
        void setPrice(double price_);

        // display method
        void display() const;
};

#endif // INC_5699368_MD12_TASK3_PRODUCT_H
