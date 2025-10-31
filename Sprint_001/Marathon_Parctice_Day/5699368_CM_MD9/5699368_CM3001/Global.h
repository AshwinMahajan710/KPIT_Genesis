#ifndef GLOBAL_H
#define GLOBAL_H

#include"DetectedVehicle.h"

// return smallest possible distancemeter with id >= 0; --> if no valid found return -1.0F
float ComputeClosestDistance(const DetectedVehicle arr_[], int count_);

// return count of vehicle with  (getIsBreaking() == true) && (getdistanceMeters() <= maxDistance()) && (id>=0)
int countBrakingVehiclesWithin(const DetectedVehicle arr_[], int count_, float maxDistance_);

#endif // GLOBAL_H