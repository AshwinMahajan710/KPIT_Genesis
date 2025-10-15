#include<iostream>
#include"5699368_MD3_Task3_SeverityLevel.h"
#include"5699368_MD3_Task3_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD3_Task3_Global.h"
#include"5699368_MD3_Task3_DTCDiagnostics.h"
#include"5699368_MD3_Task3_DiagnosticSession.h"

int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating dtcObject using parameterized constructor 
    DTC dtcObj1("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");
    DTC dtcObj2("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01");
    DTC dtcObj3("B1001","Airbag Internal failure",true,3,100000, SeverityLevel::CRIT, true , true, false, "Safety","ECU_04");
    DTC dtcObj4("B1235","Wheel Speed sensor failure",true,3,100000, SeverityLevel::CRIT, false , true, false, "ABS","ECU_06");
    
    // creating diagnosticSession object
    DiagnosticSession session("John Joshi","Session 001");

    // logging dtc obj
    session.logDTC(dtcObj1);
    session.logDTC(dtcObj2);
    session.logDTC(dtcObj3);
    session.logDTC(dtcObj4);
    
    // print session info
    session.summarizeSession();

    // testing the logic for making DTC activated in case they are at critical severity level
    std::cout<<"\nTotal DTC made activated are: "<<session.activateCriticalFaults()<<std::endl;

    return 0;
}