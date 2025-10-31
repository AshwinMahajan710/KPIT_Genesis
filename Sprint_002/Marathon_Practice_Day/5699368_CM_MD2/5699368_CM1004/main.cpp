#include<string>
#include"DiagnosticTask.h"
#include"Severity.h"
#include"SensorDiagnostic.h"
#include<vector>
#include"DiagnosticRunner.h"
#include"ECUDiagnostic.h"
#include<iostream>

int main(){

    // creating two obj of ecu and sensor and add them in Diagnostic runner
    DiagnosticTask* ecu = new ECUDiagnostic("EngineControl");
    DiagnosticTask* sensor = new SensorDiagnostic(4);

    DiagnosticRunner runner;
    runner.addTask(ecu);
    runner.addTask(sensor);

    // try to get the results
    std::vector<std::pair<std::string, Severity>> runnerInfo = runner.executeAll();
    for(auto i: runnerInfo){
        std::cout<<i.first<<std::endl;
    }

    return 0;
}