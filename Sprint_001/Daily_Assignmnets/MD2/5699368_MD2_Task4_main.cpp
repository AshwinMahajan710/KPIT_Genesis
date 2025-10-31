#include<iostream>
#include"5699368_MD2_Task4_SeverityLevel.h"
#include"5699368_MD2_Task4_DTC.h"
#include<string>
#include<ctime>
#include"5699368_MD2_Task4_Global.h"

constexpr int N = 6; // for array size

int DTC::s_DTCCount = 0; // set static variable value to 0;

int main(){

    //defining current time
    time_t now = std::time(nullptr);

    // creating const object
    const DTC dtcObj1("P0420","Catalyst efficiency below threshold",false, 2, now-4000, SeverityLevel::WARN, false , false, false, "Exhaust", "ECU_02");

    // calling const methods
    dtcObj1.printSummary(); // allowed
    // dtcObj1.setActive() ; // Not allowed --> as we are using const object we cannot modify its value in any case

    // Now creating DTCobj and then try to use const pointer whihc points to this object
    DTC dtcObj2;
    DTC* const dtcPtr = &dtcObj2; // by this we cannot modify the pointer but can chnage the values of object 
    // const DTC* dtcPtr = &dtcObj2; // by this we cannot modify the vlaues of object but can chnage the pointer itself 

    // now validate the DTC object count
    std::cout<<"\nDTC Object count: "<<DTC::getDTCCount()<<std::endl;
    return 0;
}