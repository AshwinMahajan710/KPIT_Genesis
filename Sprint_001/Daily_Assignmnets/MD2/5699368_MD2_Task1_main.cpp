#include<iostream>
#include"5699368_MD2_Task1_SeverityLevel.h"
#include"5699368_MD2_Task1_DTC.h"
#include<string>
#include<ctime>

int main(){
    // creating pointer that points to array of 3 pointers to DTC objects
    DTC** dtcArray = new DTC* [3];

    // Now allocating DTC object in array
    dtcArray[0] = new DTC("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01");
    dtcArray[1] = new DTC("P0420","Catalyst efficiency below zero",false, 1, 1625248600, SeverityLevel::WARN, false , true, false, "Exhaust", "ECU_02");
    dtcArray[2] = new DTC("P0171","System to lean (Bank 1)",true, 2, 1625249600, SeverityLevel::INFO, true , false, true, "Fuel", "ECU_03");

    // now calling 4 methods on each object
    for(size_t i=0;i<3;i++){
        std::cout<<"\nGetting decription for object "<<i+1<<": "<<dtcArray[i]->getDescription()<<std::endl;
        std::cout<<"Getting Risk score for object "<<i+1<<": "<<dtcArray[i]->computeRiskScore()<<std::endl;
        std::cout<<"Action recommended for object "<<i+1<<": "<<dtcArray[i]->recommendAction()<<std::endl;
        std::cout<<"Getting occurance count for object "<<i+1<<": "<<dtcArray[i]->getOccurenceCount()<<std::endl;
    }    

    // displaying info for all 3 objects
    for(size_t i=0;i<3;i++){
        std::cout<<"\nInfo for object "<<i+1<<": "<<std::endl;
        dtcArray[i]->printDTCInfo();
    }

    // deallocating all allocated memory
    for(size_t i=0;i<3;i++){
        delete dtcArray[i];
    }
    delete[] dtcArray;
    dtcArray = nullptr;

    return 0;

}