#include"Vehicle.h"
#include"VehicleType.h"
#include"Global.h"
#include<iostream>
#include<stdexcept>
#include<string>

constexpr int ARRAY_SIZE = 3;

int main(){

    // < = = = = = = = = = = = = = = =  TC1 = = = = = = = = = = = = = = >

    // Creating array of 3 vehicle objects
    Vehicle array [ARRAY_SIZE];

    // taking input in each using >>
    try{
        for(int i=0;i<ARRAY_SIZE;i++){
            std::cin >> array[i];
        }
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    // Displaying using <<
    for(int i=0;i<ARRAY_SIZE;i++){
        std::cout << array[i];
    }

    // < = = = = = = = = = = = = = = = TC2 = = = = = = = = = = = = = = = >
    // using == to compare first and second obj
    if(array[0] == array[1]) {std::cout<<"\nYes Both are same.."<<std::endl;}
    else{std::cout<<"\nNO Both are Different.."<<std::endl;}
    
    // < = = = = = = = = = = = = = = = TC3 = = = = = = = = = = = = = = = >
    // creating copy and then compare
    Vehicle copyVehicle(array[1]);
    if(array[1] == copyVehicle) {std::cout<<"\nYes Both are same.."<<std::endl;}
    else{std::cout<<"\nNo Both are Different.."<<std::endl;}
    
    // < = = = = = = = = = = = = = = = TC4 = = = = = = = = = = = = = = = >
    // Accessing first index score
    std::cout<<"\nTest score at first idx: "<<array[2][1]<<std::endl;

    // < = = = = = = = = = = = = = = = TC5 = = = = = = = = = = = = = = = >
    // Accessing fifth index score --> expected exception
    try{
        std::cout<<"\nTest score at fifth idx: "<<array[0][5]<<std::endl;
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    // < = = = = = = = = = = = = = = = TC6 = = = = = = = = = = = = = = = >
    // creating copy using assignment operator
    Vehicle v2 = array[0];

    // < = = = = = = = = = = = = = = = TC7 = = = = = = = = = = = = = = = >
    // creating copy using copy constructor
    Vehicle v3(array[2]);    

    // < = = = = = = = = = = = = = = = TC8 = = = = = = = = = = = = = = = >
    // findingminAvgScore()
    findMinAvgScoore(array,ARRAY_SIZE);    

    // < = = = = = = = = = = = = = = = TC9 = = = = = = = = = = = = = = = >
    // showing vehicles of commertial type
    showVehicles(array,ARRAY_SIZE,VehicleType::COMMERCIAL);

    // < = = = = = = = = = = = = = = = TC10 = = = = = = = = = = = = = = = >
    // showing vehicles of PASSENGER type
    showVehicles(array,ARRAY_SIZE,VehicleType::PASSENGER);

    return 0;
}