#include<string>
#include"5699368_MD12_Task3_Product.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include"5699368_MD12_Task3_Global.h"

// returning vector of products
std::vector<std::unique_ptr<Product>> createCatalog(){
    std::vector<std::unique_ptr<Product>> products;
    products.emplace_back( std::make_unique<Product>(1,"Soap",100)); 
    products.emplace_back (std::make_unique<Product>(2,"Wheat",110) );
    products.emplace_back (std::make_unique<Product>(3,"ToothPaste",210) );
    products.emplace_back (std::make_unique<Product>(4,"Watch",180) );
    products.emplace_back (std::make_unique<Product>(5,"Shirt",780) );
    return products;
}

// display function
void displayAll(const std::vector<std::unique_ptr<Product>>& products){
    std::cout<<"Displaying all products details: "<<std::endl;
    for(auto &product: products){
        product->display();
    }
}

