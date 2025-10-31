#include"5699368_MD6_Task3_DTC.h"
#include"5699368_MD6_Task3_SeverityLevel.h"
#include"5699368_MD6_Task3_EngineDTC.h"
#include"5699368_MD6_Task3_ADASDTC.h"
#include"5699368_MD6_Task3_BrakeDTC.h"
#include<stdexcept>
#include<iostream>
#include<string>

// initializing count
int DTC::s_DTCCount = 0;

int main(){
        //defining current time
    time_t now = std::time(nullptr);

    // Validating the exceptions
    try
    {
        EngineDTC EngineDTCObj("P0115","Engine Coolant Temperature sensor fault",true, 2, 1625280000, SeverityLevel::WARN, true , false,false, "Engine", "ECU_ENG", 1850, 132.4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        BrakeDTC BrakeDTCObj("C1234","Wheel Speed Sensor Rear Left input missing",true, 4, 1625230000, SeverityLevel::CRIT, true , false,true, "Brakes", "ECU_BRK", 0.2, true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        ADASDTC ADASDTCObj("B1005","Radar Sensor Misalignment",true, 1, 1625400000, SeverityLevel::WARN, false ,true,true, "ADAS", "ECU_ADAS", "Radar", -1.0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    // Creating object for each of derived class using parameterized constructor 
    EngineDTC EngineDTCObj("P0115","Engine Coolant Temperature sensor fault",true, 2, 1625280000, SeverityLevel::WARN, true , false,false, "Engine", "ECU_ENG", 1850, 102.4);
    BrakeDTC BrakeDTCObj("C1234","Wheel Speed Sensor Rear Left input missing",true, 4, 1625230000, SeverityLevel::CRIT, true , false,true, "Brakes", "ECU_BRK", 2.8, true);
    ADASDTC ADASDTCObj("B1005","Radar Sensor Misalignment",true, 1, 1625400000, SeverityLevel::WARN, false ,true,true, "ADAS", "ECU_ADAS", "Radar", 0.62);

    // modfying attributes --> occurenceCount, Description, Severitylevel
    EngineDTCObj.setOccurenceCount(10);
    BrakeDTCObj.setOccurenceCount(10);
    ADASDTCObj.setOccurenceCount(10);
    EngineDTCObj.setSeverityLevel(static_cast<SeverityLevel>(1));
    BrakeDTCObj.setSeverityLevel(static_cast<SeverityLevel>(1));
    ADASDTCObj.setSeverityLevel(static_cast<SeverityLevel>(1));
    EngineDTCObj.setDescription("Cylinder 4 misfire");
    BrakeDTCObj.setDescription("Cylinder 4 misfire");
    ADASDTCObj.setDescription("Cylinder 4 misfire");

    // invoking some getters
    std::cout<<"Occurence count is: "<<EngineDTCObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    EngineDTCObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    EngineDTCObj.markConfirmed();

    std::cout<<"Occurence count is: "<<BrakeDTCObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    BrakeDTCObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    BrakeDTCObj.markConfirmed();

    std::cout<<"Occurence count is: "<<ADASDTCObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    ADASDTCObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    ADASDTCObj.markConfirmed();

    // printing info of all 3 objects
    std::cout<<"\nPrinting report for EngineDTCObj..."<<std::endl;
    EngineDTCObj.printEngineDTCInfo();
    std::cout<<"\nPrinting report for BrakeDTCObj..."<<std::endl;
    BrakeDTCObj.printBrakeDTCInfo();
    std::cout<<"\nPrinting report for ADASDTCObj..."<<std::endl;
    ADASDTCObj.printADASDTCInfo();
    
    return 0;
}
