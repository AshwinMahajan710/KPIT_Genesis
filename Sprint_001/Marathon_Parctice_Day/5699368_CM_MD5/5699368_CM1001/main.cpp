
// main file

#include<iostream>
#include<string>
#include<stdexcept>
#include"Global.h"
#include"Inventory.h"

// main function --> testing functionality
int main(){
    
    // TC01 --> To validate sale and purchase functionality
    try{
        Inventory iObj(30);
        iObj.sale(5);
        iObj.sale(4);
        iObj.purchase(10);
        iObj.sale(25); // Exception Invoked....
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    std::cout<<std::endl;

    // TC02 --> To validate sale and purchase functionality
    try{
        Inventory iObj(50);
        iObj.purchase(10);
        iObj.sale(45); // Exception Invoked....
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    
    std::cout<<std::endl;
    
    // TC03 -->  To validate search functionality
    try{
        Inventory iArr[3] = {{"HouseHold", 100, 50111},{"Electronics", 500, 50112},{"Sports", 300, 50113}};
        Search(iArr,3,50112);
        Search(iArr,3,50118);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    
    return 0;
} 