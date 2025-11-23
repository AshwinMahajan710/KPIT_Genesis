#ifndef GLOBAL_H
#define GLOBAL_H

#include"TotalCostOfOwnership.h"
#include<vector>
#include<memory>
#include"Vehicle.h"

const Vehicle* findLowestTotalCostVehicle(std::vector<std::unique_ptr<TotalCostOfOwnership>>& vehicles);

#endif // GLOBAL_H
