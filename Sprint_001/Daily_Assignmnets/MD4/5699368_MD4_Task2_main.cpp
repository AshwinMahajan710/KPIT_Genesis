#include<iostream>
#include"5699368_MD4_Task2_SeverityLevel.h"
#include"5699368_MD4_Task2_DTC.h"
#include"5699368_MD4_Task2_EngineDTC.h"
#include"5699368_MD4_Task2_FullEngineDTC.h"
#include<string>
#include<ctime>


int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating engineDTC object using parameterized constructor 
    FullEngineDTC fullEngineDTCObj("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01", 3800, 128.5, 38.0, 125.3, 78,"Detected during uphill highway climb");

    // modfying attributes --> occurenceCount, Description, Severitylevel
    fullEngineDTCObj.setOccurenceCount(10);
    fullEngineDTCObj.setSeverityLevel(static_cast<SeverityLevel>(1));
    fullEngineDTCObj.setDescription("Cylinder 4 misfire");

    // invoking some getters
    std::cout<<"Occurence count is: "<<fullEngineDTCObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    fullEngineDTCObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    fullEngineDTCObj.markConfirmed();

    // printing info 
    std::cout<<"\nPrinting full detailed report..."<<std::endl;
    fullEngineDTCObj.printFullDTCReport();

    // checking is engine overheated
    std::cout<<"\nEngine overheating status: "<<(fullEngineDTCObj.isOverheated() ? "YES" : "NO")<<std::endl;
    
    return 0;
}