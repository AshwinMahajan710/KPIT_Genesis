// static constexpr float MIN_BRAKE_PRESSURE = 0.5F;

// BrakeDTC::BrakeDTC(const std::string& code,
//                    const std::string& description,
//                    bool active,
//                    int occurrenceCount,
//                    std::time_t lastOccurrenceTime,
//                    SeverityLevel severityLevel,
//                    bool confirmed,
//                    bool pending,
//                    bool milOn,
//                    const std::string& system,
//                    const std::string& origin,
//                    float brakePressure,
//                    bool absEngaged)
//     : DTC(code, description, active, occurrenceCount, lastOccurrenceTime, severityLevel, confirmed, pending, milOn, system, origin),
//       m_absEngaged(absEngaged),
//       m_brakePressure(0.0F)  // safe default
// {
//     // Validate brake pressure
//     if (brakePressure < MIN_BRAKE_PRESSURE)
//     {
//         throw std::invalid_argument("LowBrakePressureException: brake pressure too low for safe operation");
//     }

//     m_brakePressure = brakePressure;
// }
// ✅ Key