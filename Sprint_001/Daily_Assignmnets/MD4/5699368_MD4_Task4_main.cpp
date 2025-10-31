#include<iostream>
#include"5699368_MD4_Task4_SeverityLevel.h"
#include"5699368_MD4_Task4_DTC.h"
#include"5699368_MD4_Task4_EngineDTC.h"
#include"5699368_MD4_Task4_EnvironmentData.h"
#include"5699368_MD4_Task4_SmartEngineDTC.h"

#include<string>
#include<ctime>


int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating object for smart DTC
    SmartEngineDTC smartEngineDTCObj("P0500","Vehicle Speed sensor malfunction",true, 6, 1628888000, SeverityLevel::CRIT, true , false,true, "Engine", "ECU_ENG_MAIN", 4100,133.5,39.2,110,82,"Occured during peak summer traffic congestion");    

    smartEngineDTCObj.printSmartDTCInfo();
    
    return 0;
}