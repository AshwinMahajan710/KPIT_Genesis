#include"5699368_MD3_Task3_SeverityLevel.h"
#include"5699368_MD3_Task3_DTC.h"
#include"5699368_MD3_Task3_DTCDiagnostics.h"
#include<iostream>
#include<string>

// defining the function from 
void DTCDiagnostics::reportStatus(const DTC& dtc){
    std::cout<<"\nDTC Code: "<<dtc.m_code<<std::endl;
    std::cout<<"\nSystem Name: "<<dtc.m_system<<std::endl;
    std::cout<<"\nSeverity Level: "<<dtc.getSeverityString()<<std::endl;
    std::cout<<"\nMIL Status: "<<(dtc.m_milOn ? "Yes":"No")<<std::endl;
}