// EnvironmentData::EnvironmentData(
//     const std::string& code_,
//     const std::string& description_,
//     bool active_,
//     int occurenceCount_,
//     std::time_t lastOccurenceTime_,
//     SeverityLevel severityLevel_,
//     bool confirmed_,
//     bool pending_,
//     bool milOn_,
//     const std::string& system_,
//     const std::string& origin_,
//     float ambientTemp_,
//     float altitude_,
//     float humidity_)
// : DTC(code_, description_, active_, occurenceCount_, lastOccurenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_)
// {
//     // --- Validate ambient temperature ---
//     if ((ambientTemp_ < -50.0F) || (ambientTemp_ > 60.0F))
//     {
//         throw std::invalid_argument("Ambient Temperature out of realistic range (-50 to 60)");
//     }
//     m_ambientTemperature = ambientTemp_;

//     // --- Validate altitude ---
//     if ((altitude_ < -100.0F) || (altitude_ > 10000.0F))
//     {
//         throw std::invalid_argument("Altitude must be between -100 to 10000 meters");
//     }
//     m_altitude = altitude_;

//     // --- Validate humidity ---
//     if ((humidity_ < 0.0F) || (humidity_ > 100.0F))
//     {
//         throw std::invalid_argument("Humidity must be between 0.0 to 100 percent");
//     }
//     m_humidity = humidity_;
// }
