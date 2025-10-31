#ifndef DIAGNOSTIC_SESSION_H
#define DIAGNOSTIC_SESSION_H

#include "5699368_MD3_Task3_DTC.h"
#include "5699368_MD3_Task3_SeverityLevel.h"
#include <string>

// Class: DiagnosticSession
// Purpose: Manages a session of DTC diagnostics for a technician
class DiagnosticSession
{
private:
    static const int MAX_DTC_COUNT = 5;  // ✅ Avoid magic number

    std::string m_technicianName;
    std::string m_sessionId;
    DTC m_dtcArray[MAX_DTC_COUNT];
    int m_dtcCount;

public:
    // Constructor
    DiagnosticSession(const std::string& technicianName, const std::string& sessionId);

    // Add a DTC to the session
    void logDTC(const DTC& dtc);

    // Print summary of the session
    void summarizeSession() const;

    // Activate all critical faults and return count
    int activateCriticalFaults();
};

#endif // DIAGNOSTIC_SESSION_H
