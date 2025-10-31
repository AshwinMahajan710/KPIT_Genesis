#include"VehicleFuelAccount.h"
#include"Global.h"
#include<iostream>
#include<string>
#include<stdexcept>

constexpr int ARR_SIZE = 3; // size for arr

double VehicleFuelAccount::s_fleetEfficiencyRate = 3;

int main(){

    // Creating 3 VehicleFuelAccount objects
    // TC1
    VehicleFuelAccount* vehicle1 = new VehicleFuelAccount(2000.0);
    VehicleFuelAccount* vehicle2 = new VehicleFuelAccount(3000.0);
    VehicleFuelAccount* vehicle3 = new VehicleFuelAccount(2500.0);

    // Creating arr of this pointers
    VehicleFuelAccount* array[3];
    array[0] = vehicle1;
    array[1] = vehicle2;
    array[2] = vehicle3;

    // < = = = = = = = TC1  = = = = = = = >
    // Setting fleetefficiencyrate to 3%
    VehicleFuelAccount::s_fleetEfficiencyRate = 3;

    // calling apply bonuses and then showing updated balances
    applyBonusToFleet(array,ARR_SIZE);

    // displaying to show balance updated or not
    for(int i=0;i<ARR_SIZE;i++){
        array[i]->display();
    }
    
    // < = = = = = = = = = TC2 = = = = = = = = = >
    std::cout<<"\nTotal fleet fuel: "<<getTotalFleetFuel(array,ARR_SIZE)<<std::endl;

    // < = = = = = = = = = TC3 = = = = = = = = = >
    // Setting fleetefficiencyrate to 4%
    VehicleFuelAccount::s_fleetEfficiencyRate = 4;

    // calling apply bonuses and then showing updated balances
    applyBonusToFleet(array,ARR_SIZE);

    // displaying to show balance updated or not
    for(int i=0;i<ARR_SIZE;i++){
        array[i]->display();
    }
    
    // < = = = = = = = = = TC4 = = = = = = = = = >
    std::cout<<"\nTotal fleet fuel: "<<getTotalFleetFuel(array,ARR_SIZE)<<std::endl;

    // Removing allocated space;
    for(int i=0;i<ARR_SIZE;i++){
        delete array[i];
        array[i] = nullptr;
    }

}