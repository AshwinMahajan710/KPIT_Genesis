#include<string>
#include"Status.h"
#include"SmartAppliance.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include"Global.h"

// function which will create vector of unique_ptr of SmartAppliance and then return it after adding some objects
std::vector<std::unique_ptr<SmartAppliance>> createAppliances(){
    std::vector<std::unique_ptr<SmartAppliance>> appliances;
    appliances.emplace_back(std::make_unique<SmartAppliance>(1, "AirConditioner", Status::ON, 10.0));
    appliances.emplace_back(std::make_unique<SmartAppliance>(2, "Refrigerator", Status::OFF, 5.0));
    appliances.emplace_back(std::make_unique<SmartAppliance>(3, "Washing Machine", Status::ON, 17.0));
    appliances.emplace_back(std::make_unique<SmartAppliance>(4, "Microwave", Status::ON, 22.0));
    appliances.emplace_back(std::make_unique<SmartAppliance>(5, "Dish Washer", Status::OFF, 8.0));
    return appliances;
}

// Function to search appliance using its name
SmartAppliance* searchAppliance(const std::vector<std::unique_ptr<SmartAppliance>>& appliances, const std::string& name){
    for(auto& appliance: appliances){
        if(appliance->getName() == name){
            return appliance.get();
        }
    }
    return nullptr;
}

// counts and prints appliances with status ON
void countOnAppliances(const std::vector<std::unique_ptr<SmartAppliance>>& appliances){
    int count = 0;
    for (auto &appliance: appliances){
        if(appliance->getStatus() == Status::ON){
            count++;
        }
    }
    std::cout<<"\nAppliances with status ON: "<<count<<std::endl;
}

// Filters and displays appliances with discount above a given threshold
void filterByDiscount(const std::vector<std::unique_ptr<SmartAppliance>>& appliances, double threshold){
    std::cout<<"\nAppliances with discount > "<<threshold<<"% .."<<std::endl;
    for (auto &appliance: appliances){
        if(appliance->getDiscount()>threshold){
            appliance->display();
        }
    }
}

// Searches and displays an appliance by name
void searchByName(const   std::vector<std::unique_ptr<SmartAppliance>>& appliances, const std::string& target){
    for (auto &appliance: appliances){
        if(appliance->getName() == target){
            std::cout<<"\nAppliance Found: "<<std::endl;
            appliance->display();
            return;
        }
    }
    std::cout<<"\nNo Appliance with that name found..."<<std::endl;
}

// Increase the discount of application by 5%
void increaseDiscount(SmartAppliance& appliance){
    appliance.setDiscount(appliance.getDiscount() + 5.0);
    std::cout<<"Discount increased..New discount: "<<appliance.getDiscount()<<std::endl;
}

// decrease discount by 10 cap at 0%
void decreaseDiscount(SmartAppliance& appliance){
    appliance.setDiscount(appliance.getDiscount() - 10.0);
    std::cout<<"Discount reduced..New discount: "<<appliance.getDiscount()<<std::endl;
}

// Applies conditional discount logic to each appliance using a function passed as a parameter
void   recalculateDiscount(std::vector<std::unique_ptr<SmartAppliance>>& appliances, std::function<void(SmartAppliance&)> func){
    for(auto &appliance: appliances){
        if(appliance->getStatus()==Status::ON) {func = increaseDiscount;}
        else {func = decreaseDiscount;}
        func(*(appliance.get()));
    }
}

// Calculates and prints the average discount across all appliances
void findAverageDiscount(const std::vector<std::unique_ptr<SmartAppliance>>& appliances){
    double totalDiscount = 0.0;
    for (auto &appliance: appliances){
        totalDiscount += appliance->getDiscount();
    }
    std::cout<<"\nAverage Discount of appliances is: "<< (totalDiscount/appliances.size())<<std::endl;
}