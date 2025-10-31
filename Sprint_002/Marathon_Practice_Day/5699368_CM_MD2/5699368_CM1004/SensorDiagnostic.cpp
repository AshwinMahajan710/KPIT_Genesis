#include<string>
#include"DiagnosticTask.h"
#include"Severity.h"
#include"SensorDiagnostic.h"

// constructor --> parameterized
SensorDiagnostic::SensorDiagnostic(int sensorId_){
    m_sensorId = sensorId_;
}

// runImplementation function;
bool SensorDiagnostic::run() const{
    if(m_sensorId%2 == 0){
        return true;
    }
    else{
        return false;
    }
}

//function to gte severity
Severity SensorDiagnostic::getSeverity() const noexcept{
    if(run()){return Severity::INFO;}
    else {return Severity::WARNING;}
}