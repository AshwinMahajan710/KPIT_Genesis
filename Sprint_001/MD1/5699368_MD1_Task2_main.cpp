#include<iostream>
#include<ctime>
#include<string>
#include"5699368_MD1_Task2_DTC.h"
#include"5699368_MD1_Task2_SeverityLevel.h"

int main(){

    // creating DTC object using default constructor
    DTC dtc;

    // creating another dtc object via parameterized constructor
    DTC dtc2("P301","Cylinder misfire detected", true, 3, 1625247600, SeverityLevel::NORMAL,true, false, true, "Engine", "ECU_01");

    // modifying few attributes of object
    dtc.setActive(true);
    dtc.setDescription("Unknown Engine Fault");

    // calling incrementOccurance on both object
    dtc.incrementOccurence();
    dtc2.incrementOccurence();

    // toggling the MIL status for both
    dtc.toggleMIL();
    dtc2. toggleMIL();

    // marking the confirmation for both
    dtc.markConfirmed();
    dtc2.markConfirmed();
    
    // displaying details
    std::cout<<"\nDetails of dtc1: "<<std::endl;
    dtc.printDTCInfo();
    std::cout<<"\nDetails of dtc2: "<<std::endl;
    dtc2.printDTCInfo();

    return 0;
}