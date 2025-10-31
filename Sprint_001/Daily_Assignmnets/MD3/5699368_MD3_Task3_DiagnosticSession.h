#ifndef DIAGNOSTICSESSION_H
#define DIAGNOSTICSESSION_H

#include"5699368_MD3_Task3_DTC.h"
#include"5699368_MD3_Task3_SeverityLevel.h"

#include<string>

// class diagnosticSession
class DiagnosticSession{
    private:
        std::string m_technicianName;
        std::string m_sessionID;
        DTC m_dtcArray[5];
        int m_DTCCount;

    public:
        DiagnosticSession(const std::string& technicianName_, const std::string& sessionID_);
        void logDTC(const DTC& dtc);
        void summarizeSession() const;
        int activateCriticalFaults();
};


#endif // DIAGNOSTICSESSION_H
