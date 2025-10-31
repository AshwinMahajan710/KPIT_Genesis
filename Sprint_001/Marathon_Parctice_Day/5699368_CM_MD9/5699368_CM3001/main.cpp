#include"DetectedVehicle.h"
#include"Global.h"
#include<stdexcept>
#include<iostream>
#include<string>

int main(){

    // Assumption --> Creating new array each test case

    // TC1 
    DetectedVehicle arr1[10];
    arr1[0] = DetectedVehicle(0,12.5,-1.5,false);
    arr1[1] = DetectedVehicle(1,8.0,0.0,true);
    arr1[2] = DetectedVehicle(2,20.0,-2.0,false);
    float maxDistanceBrakingCount1 = 10.0;
    std::cout<<"\nClosest distance Output: "<<ComputeClosestDistance(arr1, 10)<<std::endl;
    std::cout<<"Breaking count Output: "<<countBrakingVehiclesWithin(arr1, 10, maxDistanceBrakingCount1)<<std::endl;

    // TC2
    DetectedVehicle arr2[10];
    arr2[0] = DetectedVehicle(0 , 0.0 , -3.0 , true);
    arr2[1] = DetectedVehicle(1 , -5.0 , 1.0 , true);
    float maxDistanceBrakingCount2 = 1.0;
    std::cout<<"\nClosest distance Output: "<<ComputeClosestDistance(arr2, 10)<<std::endl;
    std::cout<<"Breaking count Output: "<<countBrakingVehiclesWithin(arr2, 10, maxDistanceBrakingCount2)<<std::endl;
    
    // TC3
    DetectedVehicle arr3[10];
    float maxDistanceBrakingCount3 = 50.0;
    std::cout<<"\nClosest distance Output: "<<ComputeClosestDistance(arr3, 10)<<std::endl;
    std::cout<<"Breaking count Output: "<<countBrakingVehiclesWithin(arr3, 10, maxDistanceBrakingCount3)<<std::endl;
    
    // TC4
    DetectedVehicle arr4[10];
    arr4[0] = DetectedVehicle(5 , 4.2 , -0.5 , true);
    arr4[1] = DetectedVehicle(6 , 4.2 , -0.2 , false);
    arr4[2] = DetectedVehicle(7 , 2.0 , -1.0 , true);
    arr4[3] = DetectedVehicle(8 , 100.0 , 5.0 , true);
    float maxDistanceBrakingCount4 = 5.0;
    std::cout<<"\nClosest distance Output: "<<ComputeClosestDistance(arr4, 10)<<std::endl;
    std::cout<<"Breaking count Output: "<<countBrakingVehiclesWithin(arr4, 10, maxDistanceBrakingCount4)<<std::endl;

    // TC5
    DetectedVehicle arr5[10];
    arr5[0] = DetectedVehicle(0 , 0.5 , -0.1 , false);
    arr5[1] = DetectedVehicle(1 , 0.5 , -0.2 , true);
    arr5[2] = DetectedVehicle(2 , 0.5 , 0.0 , true);
    arr5[3] = DetectedVehicle(3 , 0.5 , -0.3 , false);
    float maxDistanceBrakingCount5 = 0.5;
    std::cout<<"\nClosest distance Output: "<<ComputeClosestDistance(arr5, 10)<<std::endl;
    std::cout<<"Breaking count Output: "<<countBrakingVehiclesWithin(arr5, 10, maxDistanceBrakingCount5)<<std::endl;




}