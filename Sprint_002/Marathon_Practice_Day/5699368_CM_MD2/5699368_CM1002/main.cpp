#include<string>
#include"VehicleSummary.h"
#include<vector>
#include"Owner.h"
#include"Global.h"
#include<iostream>

int main(){

    //creating vehicle Summary
    VehicleSummary* vin1 = new VehicleSummary("VIN-A");
    VehicleSummary* vin2 = new VehicleSummary("VIN-B");

    // creating owner obj;
    Owner owner("Rita");
    owner.addVehicle(vin1);
    owner.addVehicle(vin2);

    std::vector<std::string> briefs =  owner.lisVehicles();
    for(auto i: briefs){
        std::cout<<i<<std::endl;
    }

    std::cout<<ownerReport(owner)<<std::endl;

    return 0;
}