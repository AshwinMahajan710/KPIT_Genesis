#include<iostream>
#include<string>
#include"5699368_MD1_Task3_Vehicle.h"

// using aliase
using VehicleArray = Vehicle** ;

int main(){

    // creating the obj
    VehicleArray arr = new Vehicle* [3];

    // Assigning the objects
    arr[0] = new Vehicle;
    arr[1] = new Vehicle("SUV", 2023);
    arr[2] = new Vehicle("Sedan", 2022);

    // printing using the loop
    for(auto i=0;i<3;i++){
        arr[i]->show();
    }

    // clear the memory
    for(auto i=0;i<3;i++){
        delete arr[i];
    }

    return 0;
}