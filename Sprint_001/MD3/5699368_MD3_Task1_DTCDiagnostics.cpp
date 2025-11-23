#include"5699368_MD3_Task1_SeverityLevel.h"
#include"5699368_MD3_Task1_DTC.h"
#include"5699368_MD3_Task1_DTCDiagnostics.h"
#include<iostream>
#include<string>

// defining the function from 
void DTCDiagnostics::reportStatus(const DTC& dtc_){
    std::cout<<"\nDTC Code: "<<dtc_.m_code<<std::endl;
    std::cout<<"\nSystem Name: "<<dtc_.m_system<<std::endl;
    std::cout<<"\nSeverity Level: "<<dtc_.getSeverityString()<<std::endl;
    std::cout<<"\nMIL Status: "<<(dtc_.m_milOn ? "Yes":"No")<<std::endl;
}