#include <iostream>
#include <string>
#include <ctime>
#include "5699368_MD3_Task3_SeverityLevel.h"
#include "5699368_MD3_Task3_Refactored_DTC.h"
#include "5699368_MD3_Task3_Refactored_DiagnosticSession.h"
#include "5699368_MD3_Task3_Global.h"
#include "5699368_MD3_Task3_DTCDiagnostics.h"

int DTC::s_dtcCount = 0; // Initialize static variable

int main()
{
    // Define current time
    std::time_t currentTime = std::time(nullptr);

    // Create DTC objects using parameterized constructor
    DTC dtc1("P0420", "Catalyst efficiency below threshold", false, 2, currentTime - 4000, SeverityLevel::WARN, false, false, false, "Exhaust", "ECU_02");
    DTC dtc2("P0301", "Cylinder 1 Misfire detected", true, 3, 1625247600, SeverityLevel::CRIT, true, false, true, "Engine", "ECU_01");
    DTC dtc3("B1001", "Airbag Internal failure", true, 3, 100000, SeverityLevel::CRIT, true, true, false, "Safety", "ECU_04");
    DTC dtc4("B1235", "Wheel Speed sensor failure", true, 3, 100000, SeverityLevel::CRIT, false, true, false, "ABS", "ECU_06");

    // Create DiagnosticSession object
    DiagnosticSession session("John Joshi", "Session 001");

    // Log DTC objects into the session
    session.logDTC(dtc1);
    session.logDTC(dtc2);
    session.logDTC(dtc3);
    session.logDTC(dtc4);

    // Print session summary
    session.summarizeSession();

    // Activate critical DTCs and display total activated
    int totalActivated = session.activateCriticalFaults();
    std::cout << "\nTotal DTCs activated due to critical severity: " << totalActivated << std::endl;

    return 0;
}
