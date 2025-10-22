#include <iostream>
#include <ctime>
#include <string>
#include "5699368_MD1_Task2_Refactored_DTC.h"
#include "5699368_MD1_Task2_SeverityLevel.h"

int main()
{
    // Create DTC object using default constructor
    DTC dtc;

    // Create another DTC object using parameterized constructor
    const std::time_t lastOccurrenceTime = static_cast<std::time_t>(1625247600);
    DTC dtc2("P301",
             "Cylinder misfire detected",
             true,
             3,
             lastOccurrenceTime,
             SeverityLevel::NORMAL,
             true,
             false,
             true,
             "Engine",
             "ECU_01");

    // Modify some attributes of the default object
    dtc.setActive(true);
    dtc.setDescription("Unknown Engine Fault");

    // Increment occurrence count for both objects
    dtc.incrementOccurence();
    dtc2.incrementOccurence();

    // Toggle MIL status for both objects
    dtc.toggleMIL();
    dtc2.toggleMIL();

    // Mark confirmation for both objects
    dtc.markConfirmed();
    dtc2.markConfirmed();

    // Display DTC details
    std::cout << "\nDetails of dtc1:\n";
    dtc.printDTCInfo();

    std::cout << "\nDetails of dtc2:\n";
    dtc2.printDTCInfo();

    return 0;
}
