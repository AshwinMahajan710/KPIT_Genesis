#ifndef INC_5699368_MD12_TASK3_GLOBAL_H
#define INC_5699368_MD12_TASK3_GLOBAL_H

#include<string>
#include"5699368_MD12_Task3_Product.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>

// function to return vector of smaples of products
std::vector<std::unique_ptr<Product>> createCatalog();

// function to display allProducts using loop
void displayAll(const std::vector<std::unique_ptr<Product>>& products);


#endif // INC_5699368_MD12_TASK3_GLOBAL_H
