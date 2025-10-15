#include<iostream>
#include"5699368_MD3_Task1_SeverityLevel.h"
#include"5699368_MD3_Task1_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD3_Task1_Global.h"
#include"5699368_MD3_Task1_DTCDiagnostics.h"

constexpr int N = 6; // for array size

int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating dtcObject using parameterized constructor
    DTC dtcObj1("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");

    //now call isSevere
    std::cout<<"Is Object Severe: "<<isSevere(dtcObj1)<<std::endl;

    // creating instance of DTCDiagnostics
    DTCDiagnostics diagnostic;
    diagnostic.reportStatus(dtcObj1);

    // now calling reset DTC
    resetDTC(dtcObj1);

    // now calling method to check the change
    std::cout<<"\nDTC Object after change: "<<std::endl;
    dtcObj1.printSummary();

    // creating another object with different DTC status
    DTC dtcObj2("U1000","Communication Bus Fault",true, 5, now-60, SeverityLevel::WARN, false , true, false, "Network", "Gateway");

    // chcking severity of newly created object and also use report status
    std::cout<<"\nIs dtcObj2 Object Severe: "<<isSevere(dtcObj2)<<std::endl;
    diagnostic.reportStatus(dtcObj2);

    // now printing dtc count to verify objects currently present
    std::cout<<"\nCurrent DTC objects count: "<<DTC::getDTCCount()<<std::endl;

    return 0;
}