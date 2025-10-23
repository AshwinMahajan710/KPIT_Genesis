// static constexpr float COOLANT_TEMP_THRESHOLD = 130.0F;

// EngineDTC::EngineDTC(const std::string& code,
//                      const std::string& description,
//                      bool active,
//                      int occurrenceCount,
//                      std::time_t lastOccurrenceTime,
//                      SeverityLevel severityLevel,
//                      bool confirmed,
//                      bool pending,
//                      bool milOn,
//                      const std::string& system,
//                      const std::string& origin,
//                      int rpmAtFault,
//                      float coolantTemp) 
//     : DTC(code, description, active, occurrenceCount, lastOccurrenceTime, severityLevel, confirmed, pending, milOn, system, origin),
//       m_rpmAtFault(rpmAtFault),
//       m_coolantTemp(0.0F)  // Initialize first to safe default
// {
//     // Validate coolant temperature
//     if (coolantTemp > COOLANT_TEMP_THRESHOLD)
//     {
//         throw std::invalid_argument("OverHeatRiskException: coolant temperature exceeds safe threshold");
//     }

//     m_coolantTemp = coolantTemp;
// }