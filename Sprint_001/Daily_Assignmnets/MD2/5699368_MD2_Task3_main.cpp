#include<iostream>
#include"5699368_MD2_Task3_SeverityLevel.h"
#include"5699368_MD2_Task3_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD2_Task3_Global.h"

constexpr int N = 6; // for array size

int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // first try to show the value of static count
    std::cout<<"\nDTC instances at start: "<<DTC::getDTCCount()<<std::endl;
    
    // now cretaing  3  statically allocated objects using all 3 constructors
    DTC dtcStaticDefault; // using default constructor
    DTC dtcStaticParam("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01"); // using parameterized constructor
    DTC dtcStaticCopy(dtcStaticParam); // using copy constructor on dtcB
    
    // not print dtc count
    std::cout<<"\nDTC instances after static creation: "<<DTC::getDTCCount()<<std::endl;
    
    // now try severity overloads
    dtcStaticDefault.setSeverity(2);
    std::cout<<"\nNew severity level of dtcStaticDefault: "<<dtcStaticDefault.getSeverityString()<<std::endl;
    
    // similarly with string value
    dtcStaticDefault.setSeverity("Warn");
    std::cout<<"\nNew severity level of dtcStaticDefault: "<<dtcStaticDefault.getSeverityString()<<std::endl;
    
    // testing markActive --> default
    dtcStaticDefault.markActive();
    std::cout<<"\nNew active status of dtcStaticDefault: "<<dtcStaticDefault.getActive()<<std::endl;
    
    // pass param
    dtcStaticDefault.markActive(false);
    std::cout<<"\nNew active status of dtcStaticDefault: "<<dtcStaticDefault.getActive()<<std::endl;
    
    // Now dynamically allocating some objects
    DTC* pA = new DTC();
    DTC* pB = new DTC("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");
    DTC* pC = new DTC(*pB);
    
    // creating array and displaying DTC count
    // here any one missing attribute will assign pointer to garbage value and will responsible for segmenattion fault so make sure to amke all nullptr or at least some valid pointer val
    DTC* dtcArray[N] = {pA,pB,nullptr,pC ,new DTC("U1000","Comm Bus Fault", true,5,now-60,SeverityLevel::WARN,false,true,false,"network","Gateway"),nullptr};
    
    std::cout<<"\nDTC instances after dynamic allocation: "<<DTC::getDTCCount()<<std::endl;
    
    // printing all dtc values
    std::cout<<"\nDisplaying all DTC values: "<<std::endl;
    displayAllDTCs(dtcArray,N);
    
    // using overloaded set severity and mark active 
    dtcArray[4]->setSeverity("Crit");
    dtcArray[4]->markActive();
    std::cout<<"\ndtcArray[4] info after update: "<<std::endl;
    dtcArray[4] -> printDTCInfo();
    
    // now delete all things
    for(size_t i=0;i<N;i++){
        delete dtcArray[i];
        dtcArray[i] = nullptr;
    }
    // Verify DTC count again after deletion
    std::cout<<"\nDTC instances after deletion of dynamic allocation: "<<DTC::getDTCCount()<<std::endl;

    // Now try it in temp object cretaion
    {
        DTC temp;
        std::cout<<"\nAfter creating temp dtcCount: "<<DTC::getDTCCount()<<std::endl;
    }
    std::cout<<"\nAfter exiting temp block dtcCount: "<<DTC::getDTCCount()<<std::endl;


    return 0;
}