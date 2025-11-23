#include"5699368_MD8_Task3_ShoppingCart.h"
#include<string>
#include<iostream>
#include<vector>
#include<thread>
#include"5699368_MD8_Task3_ShoppingCartManagementSystem.h"
#include<mutex>
#include <functional>


int main(){

    // creating obj of shoppingCartManagementSystem
    ShoppingCartManagementSystem system;

    // three obj of ShoppingCart with different obj size
    ShoppingCart cart1(1, 10, "Ashwin");
    ShoppingCart cart2(2, 10, "Saurabh");
    ShoppingCart cart3(3, 10, "Yash");

    // addding items
    system.addCart(cart1);
    system.addCart(cart2);
    system.addCart(cart3);

    // creating two threads --> one for item removal,  using simulateItemRemoval, one for restocking items
    std::thread th1(&ShoppingCartManagementSystem::restockItems, std::ref(system)); 
    th1.join();

    std::thread th2(&ShoppingCartManagementSystem::simulateItemRemoval, std::ref(system));
    // join threads
    th2.join();

    return 0;
}