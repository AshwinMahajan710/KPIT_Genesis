#include<string>
#include"DiagnosticTask.h"
#include"Severity.h"
#include"SensorDiagnostic.h"
#include<vector>
#include"DiagnosticRunner.h"
#include"ECUDiagnostic.h"

// to add new diagnostic task
void DiagnosticRunner::addTask(DiagnosticTask* diagnosticMember){
    if(diagnosticMember!=nullptr){
        m_diagnostics.push_back(diagnosticMember);
    }
}

// function to run all
std::vector<std::pair<std::string, Severity>> DiagnosticRunner::executeAll(){
    std::vector<std::pair<std::string, Severity>> executeInfo;
    for(auto i: m_diagnostics){
        if(i==nullptr) {continue;}

        std::string type;
        if (dynamic_cast<ECUDiagnostic*>(i)){
            type = "ECU";
        }
        else if (dynamic_cast<SensorDiagnostic*>(i)){
            type = "Sensor";
        } 

        std::string info =  type + (i->run() ? "OK": "FAIL");
        executeInfo.push_back({info,i->getSeverity()});
    }
    return executeInfo;
}
