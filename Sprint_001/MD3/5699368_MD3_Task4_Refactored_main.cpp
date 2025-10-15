#include <iostream>
#include <string>
#include <ctime>
#include "5699368_MD3_Task4_SeverityLevel.h"
#include "5699368_MD3_Task4_Refactored_DTC.h"
#include "5699368_MD3_Task4_Global.h"
#include "5699368_MD3_Task4_Refactored_DTCAnalyzer.h"

// Initialize static class member
int DTC::s_dtcCount = 0;

int main()
{
    // ✅ Define current time safely
    const std::time_t currentTime = std::time(nullptr);

    // ✅ Create DTC objects dynamically (parameterized constructor)
    DTC* const dtcPtr1 = new DTC("P0420", "Catalyst efficiency below threshold",
                                 false, 2, currentTime - 4000,
                                 SeverityLevel::WARN, false, false, false,
                                 "Exhaust", "ECU_02");

    DTC* const dtcPtr2 = new DTC("P0301", "Cylinder 1 Misfire detected",
                                 true, 3, 1625247600,
                                 SeverityLevel::CRIT, true, false, true,
                                 "Engine", "ECU_01");

    DTC* const dtcPtr3 = new DTC("B1001", "Airbag Internal failure",
                                 true, 3, 100000,
                                 SeverityLevel::CRIT, true, true, false,
                                 "Safety", "ECU_04");

    DTC* const dtcPtr4 = new DTC("B1235", "Wheel Speed sensor failure",
                                 true, 3, 100000,
                                 SeverityLevel::CRIT, false, true, false,
                                 "ABS", "ECU_06");

    // ✅ Create DTCAnalyzer object
    DTCAnalyzer analyzer("ANZ001", "Autotech Diagnostics");

    // ✅ Add DTC pointers to analyzer
    analyzer.addDTC(dtcPtr1);
    analyzer.addDTC(dtcPtr2);
    analyzer.addDTC(dtcPtr3);
    analyzer.addDTC(dtcPtr4);

    // ✅ Review critical faults
    std::cout << "\n=== Critical Faults ===" << std::endl;
    analyzer.reviewCriticalFaults();

    // ✅ Print analyzer summary
    std::cout << "\n=== Analyzer Summary ===" << std::endl;
    analyzer.reportSummary();

    // ✅ Clean up dynamically allocated memory (MISRA: Rule 18-4-1)
    delete dtcPtr1;
    delete dtcPtr2;
    delete dtcPtr3;
    delete dtcPtr4;

    return 0;
}
