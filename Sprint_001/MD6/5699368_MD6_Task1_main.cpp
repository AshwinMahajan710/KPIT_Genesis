#include"5699368_MD6_Task1_DTC.h"
#include"5699368_MD6_Task1_SeverityLevel.h"
#include"5699368_MD6_Task1_EngineDTC.h"
#include<stdexcept>
#include<iostream>
#include<string>

// initializing count
int DTC::s_DTCCount = 0;

int main(){

    // trying constructor with empty str
    try
    {
        EngineDTC EngineDTCObj("","Engine Coolant Temperature sensor fault",true, 2, 1625280000, SeverityLevel::WARN, true , false,false, "Engine", "ECU_ENG", 1850, 102.4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Trying constructor with code of 2 or 3 empty spaces 
    try
    {
        EngineDTC EngineDTCObj("   ","Engine Coolant Temperature sensor fault",true, 2, 1625280000, SeverityLevel::WARN, true , false,false, "Engine", "ECU_ENG", 1850, 102.4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // Now creating object 
    EngineDTC EngineDTCObj("P0301","Cylinder 1 misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false,true, "Engine", "ECU_01", 3800, 95.2);

    // modifying some attributes
    EngineDTCObj.setSeverityLevel(static_cast<SeverityLevel>(1));
    EngineDTCObj.setOccurenceCount(10);
    EngineDTCObj.setDescription("Cylinder 4 misfire");

    // invoking some functions
    std::cout<<"Occurence count is: "<<EngineDTCObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    EngineDTCObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    EngineDTCObj.markConfirmed();

    // printing info
    std::cout<<"\nPrinting report for EngineDTCObj..."<<std::endl;
    EngineDTCObj.printEngineDTCInfo();

    // chekcking is overheated
    if(EngineDTCObj.isOverheated()) {std::cout<<"Yes..Engine overheated";}
    else{std::cout<<"NO..Engine is not overheated";}

    return 0;
}
