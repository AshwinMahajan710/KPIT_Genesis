#include<iostream>
#include<string>
#include"5699368_MD3_Task3_DiagnosticSession.h"
#include"5699368_MD3_Task3_SeverityLevel.h"
#include"5699368_MD3_Task3_DTC.h"

// constructor
DiagnosticSession::DiagnosticSession(const std::string& technicianName_, const std::string& sessionID_): m_technicianName(technicianName_), m_sessionID(sessionID_){};

// logDTC function
void DiagnosticSession::logDTC(const DTC& dtc){
    if(this->m_DTCCount <5){
        this->m_dtcArray[m_DTCCount++] = dtc;
        std::cout<<"\nSuccessfully allocated object...."<<std::endl;
    }else{
        std::cout<<"\nCannot allocate object.."<<std::endl;
    }
}

// summarize session
void DiagnosticSession::summarizeSession() const{
    std::cout<<"\nTechnician Detail: "<<m_technicianName<<std::endl;
    std::cout<<"Session ID: "<<m_sessionID<<std::endl;
    std::cout<<"Total DTC: "<<m_DTCCount<<std::endl;
    for(int i=0;i<this->m_DTCCount;i++){
        std::cout<<"\nDTC "<<i+1<<std::endl;
        m_dtcArray[i].printDTCInfo();
    }
}

// function to activate critical faults automatically
int DiagnosticSession::activateCriticalFaults(){
    int totalDTCActivated = 0;
    for(int i=0;i<m_DTCCount;i++){
        if(m_dtcArray[i].getSeverityLevel() == static_cast<SeverityLevel>(2)){
            m_dtcArray[i].setActive(true);
            totalDTCActivated++;
        }
    }
    return totalDTCActivated;
}