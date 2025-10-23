//     static constexpr float MIN_CONFIDENCE_SCORE = 0.0F;
//     static constexpr float MAX_CONFIDENCE_SCORE = 1.0F;

// ADASDTC::ADASDTC(const std::string& code,
//                  const std::string& description,
//                  bool active,
//                  int occurrenceCount,
//                  std::time_t lastOccurrenceTime,
//                  SeverityLevel severityLevel,
//                  bool confirmed,
//                  bool pending,
//                  bool milOn,
//                  const std::string& system,
//                  const std::string& origin,
//                  const std::string& sensorType,
//                  float confidenceScore)
//     : DTC(code, description, active, occurrenceCount, lastOccurrenceTime, severityLevel, confirmed, pending, milOn, system, origin),
//       m_sensorType(sensorType),
//       m_confidenceScore(MIN_CONFIDENCE_SCORE) // safe default
// {
//     // Validate sensor confidence
//     if ((confidenceScore < MIN_CONFIDENCE_SCORE) || (confidenceScore > MAX_CONFIDENCE_SCORE))
//     {
//         throw std::invalid_argument("SensorConfidenceException: sensor confidence score must be between 0.0 and 1.0");
//     }

//     m_confidenceScore = confidenceScore;
// }