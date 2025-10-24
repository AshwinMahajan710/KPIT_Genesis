#include"Inventory.h"
#include"Global.h"
#include<iostream>
#include<string>
#include<stdexcept>

int constexpr MAX_ARR_SIZE = 3;

int main(){

    // TC1 --> Create Instance
    Inventory inv("Engine Spare Parts", 20,1);

    // TC2 --> Purchase some stock
    inv.purchase(10);

    // TC3 --> Sale some stock
    inv.sale(5);

    // TC4 --> Sale stock with insufficient balanceStock
    try
    {
        inv.sale(30);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // TC5 --> Creating array of multiple products --> will raise exceptioon due to invalid stock value 
    try
    {
        Inventory items[] = {Inventory("Engine spares",20,1), Inventory("Brake spares",15,2), Inventory("Brake spares",0,3)};
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // TC6 --> creating array and searching for valid code
    Inventory items[MAX_ARR_SIZE] = {Inventory("Engine spares",20,1), Inventory("Brake spares",25,2), Inventory("Brake spares",30,3)};
    search(items,MAX_ARR_SIZE, 2);

    // TC6 --> searching for invalid code --> will throw exception as product not found
    try
    {
        search(items,MAX_ARR_SIZE, 99);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}