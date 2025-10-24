#include"Global.h"
#include"Inventory.h"
#include<iostream>
#include<stdexcept>

// search function --> to search specific product using product code from Inventory arr
void search(Inventory arr_[], int size_, int productCode_){
    bool found = false; // to keep track product found or not
    int count = 0; // to keep track of how much products found with respective product code
    for(int i=0;i<size_;i++){
        if(arr_[i].getProductCode() == productCode_){
            std::cout<<"\nProduct "<<++count<<" found...."<<std::endl;
            arr_[i].displayProductDetails();
            found = true;
        }
    }
    // if product not found then raise exception
    if(!found){
        throw std::out_of_range("ProductNotFoundException: \"Product with respective ID Not Found...\"");
    }
}
