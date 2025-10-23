// // Parameterized constructor
// DTC::DTC(const std::string& code_,
//          const std::string& description_,
//          bool active_,
//          int occurenceCount_,
//          std::time_t lastOccurenceTime_,
//          int severityCode_,
//          bool confirmed_,
//          bool pending_,
//          bool milOn_,
//          const std::string& system_,
//          const std::string& origin_)
//     : m_code(""),  // temporary, will assign after validation
//       m_description(description_),
//       m_active(active_),
//       m_occurenceCount(occurenceCount_),
//       m_lastOccurenceTime(0),  // temporary, assign after validation
//       m_confirmed(confirmed_),
//       m_pending(pending_),
//       m_milOn(milOn_),
//       m_system(system_),
//       m_origin(origin_),
//       m_severityLevel(SeverityLevel::INFO) // default, assign after validation
// {
//     // Validate DTC code
//     if (code_.empty() == true)
//     {
//         throw std::invalid_argument("EmptyCodeException: \"DTC code cannot be empty...\"");
//     }

//     bool isSpace = true;
//     for (std::size_t i = 0U; i < code_.size(); ++i)
//     {
//         if (code_[i] != ' ')
//         {
//             isSpace = false;
//             break;
//         }
//     }

//     if (isSpace == true)
//     {
//         throw std::invalid_argument("EmptyCodeException: \"DTC code cannot be empty...\"");
//     }

//     m_code = code_;

//     // Validate timestamp
//     if (lastOccurenceTime_ < 0)
//     {
//         throw std::invalid_argument("InvalidTimeStampException: \"Timestamp must be a valid non-negative UNIX time\"");
//     }
//     m_lastOccurenceTime = lastOccurenceTime_;

//     // Validate severity
//     if ((severityCode_ >= 0) && (severityCode_ <= 2))
//     {
//         m_severityLevel = static_cast<SeverityLevel>(severityCode_);
//     }
//     else
//     {
//         throw std::invalid_argument("InvalidSeverityException: \"Severity level must be between 0 (INFO) and 2 (CRIT)\"");
//     }

//     // Increment DTC count
//     ++s_DTCCount;
// }
