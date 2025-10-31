
// Global Functions .cpp file

#include<iostream>
#include<string>
#include<stdexcept>
#include"Inventory.h"
#include"Global.h"

// search function --> search product from Inventory array
void Search(Inventory* arr_, int size_, int productCode_){
    bool isFound_ = false; // variable to keep track product found or not
    for(int i=0;i<size_;i++){
        // if product found
        if(arr_[i].getProductCode() == productCode_){
            std::cout<<"Product Found: (Details Below)"<<std::endl;
            arr_[i].printDetails();
            isFound_ = true; 
        }
    }
    if(!isFound_){
        throw std::out_of_range("Exception: \"Product not found\"");
    }
}