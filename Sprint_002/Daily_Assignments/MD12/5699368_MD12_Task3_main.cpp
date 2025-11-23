#include<string>
#include"5699368_MD12_Task3_Product.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include"5699368_MD12_Task3_Global.h"

int main(){

    // getting products
    std::vector<std::unique_ptr<Product>> products = createCatalog();

    // displaying all products
    displayAll(products);

    // lambda to count products greater than 100
    int count = 0;
    auto lambda = [](std::vector<std::unique_ptr<Product>>& products,int &count) mutable -> void { 
        for(auto &product: products){
            if(product->getPrice() > 100){
                count++;
            }
        }
    };
    lambda(products,count);
    std::cout<<"\nTotal products greater that 100 price are: "<<count<<std::endl;

    return 0;
}