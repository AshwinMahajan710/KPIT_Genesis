#include<iostream>
#include"VehicleFuelAccount.h"
#include"Global.h"

// defining applyBonusToFleet function --> calculates and adds bouns for each vehicle
void applyBonusToFleet(VehicleFuelAccount* arr_[], int size_){
    for(int i=0;i<size_;i++){
        arr_[i]->calculateMonthlyBonus();
    }
    std::cout<<"\nSuccessfully calculated monthly bonus for each vehicle..."<<std::endl;
}

// defining getTotalFleetFuel function --> will return total fuel from each vehicle
double getTotalFleetFuel(VehicleFuelAccount* arr_[], int size_){
    double totalFuel;
    for(int i=0;i<size_;i++){
        totalFuel += arr_[i]->getFuelBalance();
    }
    return totalFuel;
}