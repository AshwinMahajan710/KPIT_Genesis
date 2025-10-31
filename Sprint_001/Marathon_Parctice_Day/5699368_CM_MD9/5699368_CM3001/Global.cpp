
#include"DetectedVehicle.h"
#include"Global.h"
#include<float.h>

// return smallest possible distancemeter with id >= 0; --> if no valid found return -1.0F
float ComputeClosestDistance(const DetectedVehicle arr_[], int count_){
    float closestDistance = FLT_MAX;
    for(int i=0;i<count_;i++){
        if(arr_[i].getId() >= 0 && arr_[i].getDistanceMeters() < closestDistance){
            closestDistance = arr_[i].getDistanceMeters();
        }
    }
    return (closestDistance == FLT_MAX  ? -1.0F : closestDistance);
}

// return count of vehicle with  (getIsBreaking() == true) && (getdistanceMeters() <= maxDistance()) && (id>=0)
int countBrakingVehiclesWithin(const DetectedVehicle arr_[], int count_, float maxDistance_){
    int countVehicles = 0;
    for(int i=0;i<count_;i++){
        if((arr_[i].getId() >= 0) && (arr_[i].getDistanceMeters() <= maxDistance_) && (arr_[i].getIsBreaking())){
            countVehicles++;
        }
    }
    return countVehicles;
}