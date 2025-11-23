#include"TotalCostOfOwnership.h"
#include<vector>
#include<memory>
#include"Vehicle.h"
#include"Registration.h"
#include"Maintainance.h"
#include"Insuarance.h"
#include<cfloat>
#include"Global.h"

// function to find vehicle with lowest cost
const Vehicle* findLowestTotalCostVehicle(std::vector<std::unique_ptr<TotalCostOfOwnership>>& vehicles){
    const Vehicle* vehicleFound = nullptr;
    float minTotalCost = FLT_MAX;
    for(const auto& vehicle: vehicles){
        float basePrice = (vehicle->getVehicle()).getPurchasePrice();
        float registrationFees = (vehicle->getRegistration()).getLicenseFee() + (vehicle->getRegistration()).getTitleFee();
        float insuaranceFees = (vehicle->getInsuarance()).getCollisionCoverage() + (vehicle->getInsuarance()).getComprehensiveCoverage() + (vehicle->getInsuarance()).getLiabilityCoverage();
        float maintainanceFees = (vehicle->geMtaintainance()).getOilChangeCost() + (vehicle->geMtaintainance()).getTireRotationCost() + (vehicle->geMtaintainance()).getRepairCost();

        float currTotalCost = basePrice + registrationFees + insuaranceFees + maintainanceFees;
        if(currTotalCost < minTotalCost){
            vehicleFound = &(vehicle->getVehicle());
            minTotalCost = currTotalCost; 
        }
    }
    return vehicleFound;
}