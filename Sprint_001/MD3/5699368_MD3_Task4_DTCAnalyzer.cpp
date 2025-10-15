#include<iostream>
#include<string>
#include"5699368_MD3_Task4_DTCAnalyzer.h"
#include"5699368_MD3_Task4_SeverityLevel.h"
#include"5699368_MD3_Task4_DTC.h"

// constructor
DTCAnalyzer::DTCAnalyzer(const std::string& analyzerID_, const std::string& organization_): m_analyzerID(analyzerID_), m_organization(organization_){};

// logDTC function
void DTCAnalyzer::addDTC(DTC* dtc){
    if(m_DTCCount >=0 && this->m_DTCCount < 5){
        this->m_dtcPtrArray[m_DTCCount++] = dtc;
        std::cout<<"\nSuccessfully allocated object...."<<std::endl;
    }else{
        std::cout<<"\nCannot allocate object.."<<std::endl;
    }
}

// function to print only critical fault dtc
void DTCAnalyzer::reviewCriticalFaults() const{
    int critObjCount = 0; // to track no of critical obj found
    for(size_t i=0;i<m_DTCCount;i++){
        if(m_dtcPtrArray[i]->getSeverityLevel() == static_cast<SeverityLevel>(2)){
            std::cout<<"\nCritical obj: "<<++critObjCount<<std::endl;
            m_dtcPtrArray[i]->printDTCInfo();
        }
    }
}

// summarize session
void DTCAnalyzer::reportSummary() const{
    std::cout<<"\nAnalyzer ID: "<<m_analyzerID<<std::endl;
    std::cout<<"Organization: "<<m_organization<<std::endl;
    std::cout<<"Total DTC: "<<m_DTCCount<<std::endl;
    for(int i=0;i<this->m_DTCCount;i++){
        std::cout<<"\nDTC "<<i+1<<std::endl;
        m_dtcPtrArray[i]->printDTCInfo();
    }
}