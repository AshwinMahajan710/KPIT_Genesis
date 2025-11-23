#include<string>
#include"Status.h"
#include"SmartAppliance.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include"Global.h"

int main(){

    // TC1 --> calling createAppliances
    std::vector<std::unique_ptr<SmartAppliance>> now = createAppliances();

    // TC2 --> displaying all appliance
    std::cout<<"\nDisplaying all appliances: "<<std::endl;
    for (auto &appliance: now){
        appliance->display();
    }

    // TC3 --> creating the reference wrapper
    std::reference_wrapper<std::vector<std::unique_ptr<SmartAppliance>>> refs = now;

    // TC4 --> lambda captures reference wrapper and calls CountOnAppliances
    auto lambda1 = [](std::vector<std::unique_ptr<SmartAppliance>>& refs) -> void{
        countOnAppliances(refs);
    };
    
    lambda1(refs);
    
    // TC5 --> lambda captures reference wrapper and threshold and then calls FilterByDiscount
    auto lambda2 = [](std::vector<std::unique_ptr<SmartAppliance>>& refs, double discount) -> void{
        filterByDiscount(refs,discount);
    };

    lambda2(refs,10);
    
    // TC6 --> lambda captures reference wrapper and name and then calls searchByName
    auto lambda3 = [](std::vector<std::unique_ptr<SmartAppliance>>& refs, const std::string& name) -> void{
        searchByName(refs,name);
    };

    lambda3(refs,"Microwave");
    
    // TC7 --> creating std::function<> and bind functions as per conditions   and calling update discount
    std::function<void(SmartAppliance& appliance)> func;
    
    // TC8 --> recalculatingdiscount
    recalculateDiscount(refs, func);

    // TC9 --> calculating average discount
    findAverageDiscount(refs);

    // TC10 --> displaying all appliances again
    std::cout<<"\nDisplaying all appliances: "<<std::endl;
    for (auto &appliance: now){
        appliance->display();
    }

    return 0;
}