// Main things to consider are to put assignments inside body if performing validations

// DTC::DTC() 
// : DTC("Default", "Default", false, 0, 0, SeverityLevel::INFO, false, false, false, "Unknown", "Unknown") 
// {
// }

// DTC::DTC(const std::string& code_,
//          const std::string& description_,
//          bool active_,
//          int occurenceCount_,
//          std::time_t lastOccurenceTime_,
//          SeverityLevel severityLevel_,
//          bool confirmed_,
//          bool pending_,
//          bool milOn_,
//          const std::string& system_,
//          const std::string& origin_)
// {
//     // --- Validate input before member initialization ---
//     if (code_.empty())
//     {
//         throw std::invalid_argument("Empty DTC code");
//     }

//     bool onlyWhitespace = true;
//     for (char ch : code_)
//     {
//         if (!std::isspace(static_cast<unsigned char>(ch)))
//         {
//             onlyWhitespace = false;
//             break;
//         }
//     }

//     if (onlyWhitespace)
//     {
//         throw std::invalid_argument("DTC code contains only whitespace");
//     }

//     if (lastOccurenceTime_ < 0)
//     {
//         throw std::invalid_argument("Invalid timestamp");
//     }

//     // --- Now safe to initialize ---
//     m_code = code_;
//     m_description = description_;
//     m_active = active_;
//     m_occurenceCount = occurenceCount_;
//     m_lastOccurenceTime = lastOccurenceTime_;
//     m_severityLevel = severityLevel_;
//     m_confirmed = confirmed_;
//     m_pending = pending_;
//     m_milOn = milOn_;
//     m_system = system_;
//     m_origin = origin_;

//     ++s_DTCCount;
// }
