#ifndef ADAS_DTC_H
#define ADAS_DTC_H

#include <string>
#include "5699368_MD4_Task3_DTC.h"

// Class representing Advanced Driver Assistance System (ADAS) Diagnostic Trouble Code
class ADASDTC : public DTC
{
private:
    std::string m_sensorType;      // Type of ADAS sensor (e.g., camera, radar, lidar)
    float m_confidenceScore;       // Confidence score of detected fault (0.0 to 1.0)

public:
    // Parameterized constructor
    ADASDTC(const std::string& code,
            const std::string& description,
            bool isActive,
            int occurenceCount,
            std::time_t lastOccurenceTime,
            SeverityLevel severityLevel,
            bool isConfirmed,
            bool isPending,
            bool isMilOn,
            const std::string& system,
            const std::string& origin,
            const std::string& sensorType,
            float confidenceScore);

    // Function to print ADAS DTC information
    void printADASDTCInfo() const;

    // Function to check if sensor fault is likely based on confidence score
    bool isSensorFaultLikely() const;
};

#endif // ADAS_DTC_H
