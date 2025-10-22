#include<iostream>
#include"5699368_MD3_Task2_SeverityLevel.h"
#include"5699368_MD3_Task2_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD3_Task2_Global.h"
#include"5699368_MD3_Task2_DTCDiagnostics.h"

constexpr int N = 6; // for array size

int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating dtcObject using parameterized constructor 
    DTC dtcObj1("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");
    DTC dtcObj2("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01");

    // checking equality and non equlity
    if(dtcObj1!=dtcObj2) {std::cout<<"\nobj1 is not equal to obj2.."<<std::endl;}
    if(dtcObj1==dtcObj2) {std::cout<<"\nobj1 is equal to obj2.."<<std::endl;}

    // increment
    std::cout<<"\nObject after pre-incrementing: "<<(++dtcObj1).getOccurenceCount()<<std::endl;
    std::cout<<"\nObject after post-incrementing: "<<(dtcObj1++).getOccurenceCount()<<std::endl;

    // printing obj
    std::cout<<dtcObj1<<std::endl;

    // Assignment operator
    DTC dtcObj3;
    dtcObj3 = dtcObj2;
    std::cout<<dtcObj3<<std::endl;

    // compare using severity 
    if(dtcObj1<dtcObj2) {std::cout<<"\nobj1 has lesser severity than obj2.."<<std::endl;}
    if(dtcObj1>dtcObj2) {std::cout<<"\nobj1 has greater severity than obj2.."<<std::endl;} 
    
    // calling () operator
    dtcObj1();

    // accessing attributes
    std::cout<<dtcObj1["occurenceCount"]<<std::endl;
    std::cout<<dtcObj1["urenceCount"]<<std::endl; // UNKNOWN

    // testing !
    bool isNotActive = !dtcObj1; 
    std::cout<<"\nTesting active status: "<<isNotActive<<std::endl;


    return 0;
}