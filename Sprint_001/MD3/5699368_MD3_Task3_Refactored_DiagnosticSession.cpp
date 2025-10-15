#include <iostream>
#include <string>
#include "5699368_MD3_Task3_Refactored_DiagnosticSession.h"
#include "5699368_MD3_Task3_SeverityLevel.h"
#include "5699368_MD3_Task3_DTC.h"

// Constructor
DiagnosticSession::DiagnosticSession(const std::string& technicianName, const std::string& sessionId)
    : m_technicianName(technicianName),
      m_sessionId(sessionId),
      m_dtcCount(0) // ✅ Initialize count
{
    // No need to initialize array of objects; default constructors are called automatically
}

// Add a DTC to the session
void DiagnosticSession::logDTC(const DTC& dtc)
{
    if (m_dtcCount < MAX_DTC_COUNT)
    {
        m_dtcArray[m_dtcCount] = dtc;
        ++m_dtcCount;
        std::cout << "\nDTC logged successfully." << std::endl;
    }
    else
    {
        std::cout << "\nCannot log DTC: Maximum capacity reached." << std::endl;
    }
}

// Print summary of the session
void DiagnosticSession::summarizeSession() const
{
    std::cout << "\nTechnician: " << m_technicianName << std::endl;
    std::cout << "Session ID: " << m_sessionId << std::endl;
    std::cout << "Total DTCs: " << m_dtcCount << std::endl;

    for (int i = 0; i < m_dtcCount; ++i)
    {
        std::cout << "\nDTC #" << (i + 1) << ":" << std::endl;
        m_dtcArray[i].printDTCInfo();  // ✅ Use consistent method name
    }
}

// Activate all critical faults and return count
int DiagnosticSession::activateCriticalFaults()
{
    int totalActivated = 0;

    for (int i = 0; i < m_dtcCount; ++i)
    {
        DTC& dtcRef = m_dtcArray[i]; // ✅ Avoid repeated array indexing
        if (dtcRef.getSeverityLevel() == SeverityLevel::CRIT)
        {
            dtcRef.setActive(true);
            ++totalActivated;
        }
    }

    return totalActivated;
}
