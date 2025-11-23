#ifndef DTC_ANALYZER_H
#define DTC_ANALYZER_H

#include "5699368_MD3_Task4_DTC.h"
#include "5699368_MD3_Task4_SeverityLevel.h"
#include <string>

// Class: DTCAnalyzer
// Purpose: To analyze and manage Diagnostic Trouble Codes (DTCs)
class DTCAnalyzer
{
private:
    static const int MAX_DTC_COUNT = 5;  // ✅ MISRA: use named constant instead of magic number

    std::string m_analyzerId;
    std::string m_organization;
    DTC* m_dtcPtrArray[MAX_DTC_COUNT];
    int m_dtcCount;

public:
    // Constructor
    DTCAnalyzer(const std::string& analyzerId, const std::string& organization);

    // Adds a DTC object to the analyzer
    void addDTC(DTC* const dtcPtr);

    // Reviews all critical faults
    void reviewCriticalFaults() const;

    // Prints a summary report of DTCs
    void reportSummary() const;
};

#endif // DTC_ANALYZER_H
