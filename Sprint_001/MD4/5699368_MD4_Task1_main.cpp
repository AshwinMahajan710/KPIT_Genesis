#include<iostream>
#include"5699368_MD4_Task1_SeverityLevel.h"
#include"5699368_MD4_Task1_DTC.h"
#include"5699368_MD4_Task1_EngineDTC.h"
#include<string>
#include<ctime>


int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating engineDTC object using parameterized constructor 
    EngineDTC engineDtcObj("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01", 3800, 95.2);

    // modfying attributes --> occurenceCount, Description, Severitylevel
    engineDtcObj.setOccurenceCount(10);
    engineDtcObj.setSeverityLevel(static_cast<SeverityLevel>(1));
    engineDtcObj.setDescription("Cylinder 4 misfire");

    // invoking some getters
    std::cout<<"Occurence count is: "<<engineDtcObj.getOccurenceCount()<<std::endl;
    std::cout<<"Toggling MIL..."<<std::endl;
    engineDtcObj.toggleMIL();
    std::cout<<"Marking DTC obj confirmed ..."<<std::endl;
    engineDtcObj.markConfirmed();

    // printing info 
    engineDtcObj.printEngineDTCInfo();

    // checking is engine overheated
    std::cout<<"\nEngine overheating status: "<<(engineDtcObj.isOverheated() ? "YES" : "NO")<<std::endl;
    
    return 0;
}