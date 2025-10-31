#include <iostream>
#include <string>
#include "5699368_MD3_Task4_Refactored_DTCAnalyzer.h"
#include "5699368_MD3_Task4_SeverityLevel.h"
#include "5699368_MD3_Task4_DTC.h"

// Constructor
DTCAnalyzer::DTCAnalyzer(const std::string& analyzerId, const std::string& organization)
    : m_analyzerId(analyzerId),
      m_organization(organization),
      m_dtcCount(0)    // ✅ Ensure initialization of count
{
    // ✅ Initialize pointer array to nullptr (MISRA: uninitialized pointers are dangerous)
    for (int i = 0; i < MAX_DTC_COUNT; ++i)
    {
        m_dtcPtrArray[i] = nullptr;
    }
}

// Add DTC object to analyzer
void DTCAnalyzer::addDTC(DTC* const dtcPtr)
{
    if ((m_dtcCount >= 0) && (m_dtcCount < MAX_DTC_COUNT))
    {
        m_dtcPtrArray[m_dtcCount] = dtcPtr;
        ++m_dtcCount;
        std::cout << "\nDTC added successfully." << std::endl;
    }
    else
    {
        std::cout << "\nCannot add DTC: Maximum capacity reached." << std::endl;
    }
}

// Review only critical faults
void DTCAnalyzer::reviewCriticalFaults() const
{
    int criticalCount = 0;

    for (int i = 0; i < m_dtcCount; ++i)
    {
        const DTC* const dtcPtr = m_dtcPtrArray[i];

        if ((dtcPtr != nullptr) && 
            (dtcPtr->getSeverityLevel() == SeverityLevel::CRIT))  // ✅ Use named enum value
        {
            ++criticalCount;
            std::cout << "\nCritical DTC #" << criticalCount << ":" << std::endl;
            dtcPtr->printDTCInfo();
        }
    }

    if (criticalCount == 0)
    {
        std::cout << "\nNo critical faults detected." << std::endl;
    }
}

// Print summary report
void DTCAnalyzer::reportSummary() const
{
    std::cout << "\nAnalyzer ID: " << m_analyzerId << std::endl;
    std::cout << "Organization: " << m_organization << std::endl;
    std::cout << "Total DTCs: " << m_dtcCount << std::endl;

    for (int i = 0; i < m_dtcCount; ++i)
    {
        const DTC* const dtcPtr = m_dtcPtrArray[i];
        if (dtcPtr != nullptr)
        {
            std::cout << "\nDTC #" << (i + 1) << ":" << std::endl;
            dtcPtr->printDTCInfo();
        }
    }
}
