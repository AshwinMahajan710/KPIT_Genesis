#include"Battery.h"
#include<string>
#include<iostream>
#include<stdexcept>
#include"Global.h"

// function to search battery via manufacturer
void searchBattriesByManufacturer(Battery* batteries_, int count_, const std::string& manufacturer_){
    if(count_ == 0) {throw std::invalid_argument("NoBatteryRecordsException: \"Currently there are no battery records..\"");}

    bool isFound = false; // to keep track batteries found or not
    int totalBatteriesFound = 0; // to keep track of how much batteries found with respective manufacturer 
    for(int i=0;i<count_;i++){
        if(batteries_[i].getManufacturer() == manufacturer_){
            std::cout<<"\nBattery "<<++totalBatteriesFound<<" Found.."<<std::endl;
            std::cout<<batteries_[i]<<std::endl;
            isFound = true;
        }
    }
    // if no battery found --> throw exception
    if(!isFound){
        throw std::out_of_range("NOTFoundException: \"No battery with respective manufacturer found..\"");
    }
}

// function to show all batteries details
void showAllBatteries(Battery* batteries_, int count_){
    if(count_ == 0) {throw std::invalid_argument("NoBatteryRecordsException: \"Currently there are no battery records..\"");}
    for (int i = 0; i < count_; i++)
    {
        std::cout<<"\nBattery "<<i+1<<std::endl;
        std::cout<<batteries_[i]<<std::endl;
    }
}
