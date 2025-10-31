#ifndef SENSORDIAGNOSTIC_H
#define SENSORDIAGNOSTIC_H

#include<string>
#include"DiagnosticTask.h"
#include"Severity.h"

class SensorDiagnostic final: public DiagnosticTask{
    private:
        int m_sensorId;

    public:
        // default constructo
        SensorDiagnostic() = default;
        SensorDiagnostic(int sensorId_); 

        // runImplementation function;
        bool run() const override;
        Severity getSeverity() const noexcept override; 
};

#endif // SENSORDIAGNOSTIC_H
