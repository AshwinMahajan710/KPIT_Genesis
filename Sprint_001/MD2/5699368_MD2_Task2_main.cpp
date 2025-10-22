#include<iostream>
#include"5699368_MD2_Task2_SeverityLevel.h"
#include"5699368_MD2_Task2_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD2_Task2_Global.h"

constexpr int N = 6; // for array size
int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // now cretaing the 3 objects using all 3 constructors
    DTC* dtcA = new DTC(); // using default constructor
    DTC* dtcB = new DTC("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01"); // using parameterized constructor
    DTC* dtcC = new DTC(*dtcB); // using copy constructor on dtcB

    // Now uing setters to set values of dtcA
    dtcA->setCode("P0234");
    dtcA->setDescription("Failure of engine ");
    dtcA->setSystem("Engine");
    dtcA->setOrigin("ECU_04");
    dtcA->setSeverityLevel(SeverityLevel::CRIT);
    dtcA->setOccurenceCount(10);
    dtcA->setLastOccurenceTime(1625249600);
    dtcA->setMilOn(true);

    // now calling some methods of dtcA
    std::cout<<"Incrementing occurence count...."<<std::endl;
    dtcA->incrementOccurence();
    std::cout<<"Toggling MIL...."<<std::endl;
    dtcA->toggleMIL();

    // creating new array and assigning elements to it
    DTC* dtcArray[N];
    dtcArray[0] = dtcA;
    dtcArray[1] = dtcB;
    dtcArray[2] = nullptr;
    dtcArray[3] = dtcC;
    dtcArray[4] = new DTC("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");
    dtcArray[5] = nullptr;

    // now calling global function to print only assigned DTC object
    displayAllDTCs(dtcArray, N);

    // now first deleting one object assigning slot to nullptr and reassign new object to test
    delete dtcArray[4];
    dtcArray[4] = nullptr;
    dtcArray[4] = new DTC("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01");

    // now delete all things
    for(size_t i=0;i<N;i++){
        delete dtcArray[i];
        dtcArray[i] = nullptr;
    }

    return 0;
}