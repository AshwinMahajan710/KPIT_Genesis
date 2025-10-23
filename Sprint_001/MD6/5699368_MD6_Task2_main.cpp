#include"5699368_MD6_Task2_DTC.h"
#include"5699368_MD6_Task2_SeverityLevel.h"
#include"5699368_MD6_Task2_EngineDTC.h"
#include"5699368_MD6_Task2_EnvironmentData.h"
#include"5699368_MD6_Task2_FullEngineDTC.h"
#include<stdexcept>
#include<iostream>
#include<string>

// initializing count
int DTC::s_DTCCount = 0;

int main(){
    
    // Checking the exceptions
    try
    {
        FullEngineDTC fullEngineObj( "P0420","Catalyst System Efficiency Below Threshold", true,5,1628258800,SeverityLevel::WARN,true,false,true,"Engine","ECU_02",2200,128.5,-610.0,-500,78.0,"Detected during uphill highway climb");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        FullEngineDTC fullEngineObj( "P0420","Catalyst System Efficiency Below Threshold", true,5,1628258800,SeverityLevel::WARN,true,false,true,"Engine","ECU_02",2200,128.5,38.5,-500,78.0,"Detected during uphill highway climb");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        FullEngineDTC fullEngineObj( "P0420","Catalyst System Efficiency Below Threshold", true,5,1628258800,SeverityLevel::WARN,true,false,true,"Engine","ECU_02",2200,128.5,38.5,1000,-12,"Detected during uphill highway climb");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    // create obj for FullEngineDTC
    FullEngineDTC fullEngineObj( "P0420","Catalyst System Efficiency Below Threshold", true,5,1628258800,SeverityLevel::WARN,true,false,true,"Engine","ECU_02",2200,128.5,38.0,125.3,78.0,"Detected during uphill highway climb");

    // invoking some functions
    std::cout<<"\nOccurence count is: "<<fullEngineObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    fullEngineObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    fullEngineObj.markConfirmed();

    // printing info
    std::cout<<"\nPrinting full DTC Report..."<<std::endl;
    fullEngineObj.printFullDTCReport();

    return 0;
}
