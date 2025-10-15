#include<iostream>
#include"5699368_MD3_Task4_SeverityLevel.h"
#include"5699368_MD3_Task4_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD3_Task4_Global.h"
#include"5699368_MD3_Task4_DTCAnalyzer.h"


int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating dtcObject using parameterized constructor 
    DTC* dtcObj1 = new DTC("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");
    DTC* dtcObj2 = new DTC("P0301","Cylinder 1 Misfire detected",true, 3, 1625247600, SeverityLevel::CRIT, true , false, true, "Engine", "ECU_01");
    DTC* dtcObj3 = new DTC("B1001","Airbag Internal failure",true,3,100000, SeverityLevel::CRIT, true , true, false, "Safety","ECU_04");
    DTC* dtcObj4 = new DTC("B1235","Wheel Speed sensor failure",true,3,100000, SeverityLevel::CRIT, false , true, false, "ABS","ECU_06");

    // creating DTCAnalyzer object
    DTCAnalyzer analyzer("ANZ001","Autotech Diagnostics");

    // adding dtc ptr obj
    analyzer.addDTC(dtcObj1);
    analyzer.addDTC(dtcObj2);
    analyzer.addDTC(dtcObj3);
    analyzer.addDTC(dtcObj4);

    // print critical info
    std::cout<<"\nFollowing is the info of critical faults: "<<std::endl;
    analyzer.reviewCriticalFaults();

    // print summary
    std::cout<<"\nFollowing is the summary of analyzer: "<<std::endl;
    analyzer.reportSummary();
    
    return 0;
}