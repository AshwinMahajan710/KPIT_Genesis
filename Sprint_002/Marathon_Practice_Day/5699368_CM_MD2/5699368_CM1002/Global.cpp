#include<string>
#include"VehicleSummary.h"
#include<vector>
#include"Owner.h"
#include"Global.h"

// function to print report
std::string ownerReport(const Owner& owner){
    return("\nOwner: " + owner.getName() + "  Vehicles Count: " + std::to_string(owner.lisVehicles().size()));
}