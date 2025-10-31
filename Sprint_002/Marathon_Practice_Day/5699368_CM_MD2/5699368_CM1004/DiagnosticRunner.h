#ifndef DIAGNOSTICRUNNER_H
#define DIAGNOSTICRUNNER_H

#include<string>
#include"DiagnosticTask.h"
#include"Severity.h"
#include"SensorDiagnostic.h"
#include<vector>

class DiagnosticRunner{
    private:
        std::vector<DiagnosticTask*> m_diagnostics;
    
    public:
        void addTask(DiagnosticTask* diagnosticMember);
        std::vector<std::pair<std::string, Severity>> executeAll();


};

#endif // DIAGNOSTICRUNNER_H
