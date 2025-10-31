#include<iostream>
#include"5699368_MD6_Task4_SeverityLevel.h"
#include"5699368_MD6_Task4_DTC.h"
#include"5699368_MD6_Task4_EngineDTC.h"
#include"5699368_MD6_Task4_EnvironmentData.h"
#include"5699368_MD6_Task4_SmartEngineDTC.h"
#include<string>
#include<ctime>


int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // will throw exception due to invalid severity level 
    try
    {
        SmartEngineDTC smartEngineDTCObj("P0500","Vehicle Speed sensor malfunction",true, 6, 1628888000, 4, true , false,true, "Engine", "ECU_ENG_MAIN", 4100,120.5,39.2,110,82,"Occured during peak summer traffic congestion"); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // will throw exception due to invalid rpm val 
    try
    {
        SmartEngineDTC smartEngineDTCObj("P0500","Vehicle Speed sensor malfunction",true, 6, 1628888000, 2, true , false,true, "Engine", "ECU_ENG_MAIN", -10,120.5,39.2,110,82,"Occured during peak summer traffic congestion"); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    
    // creating object for smart DTC
    SmartEngineDTC smartEngineDTCObj("P0500","Vehicle Speed sensor malfunction",true, 6, 1628888000, 2, true , false,true, "Engine", "ECU_ENG_MAIN", 4100,120.5,39.2,110,82,"Occured during peak summer traffic congestion");    
    std::cout<<std::endl<<std::endl;
    smartEngineDTCObj.printSmartDTCInfo();
    
    return 0;
}