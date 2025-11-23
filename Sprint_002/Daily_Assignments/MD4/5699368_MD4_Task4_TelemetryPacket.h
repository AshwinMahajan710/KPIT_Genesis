#ifndef INC_5699368_MD4_TASK4_TELEMETRYPACKET_H
#define INC_5699368_MD4_TASK4_TELEMETRYPACKET_H

#include<string>
#include"5699368_MD4_Task4_Level.h"

class TelemetryPacket{
    private:
        int m_id{};
        std::string m_tag{};
        std::uint64_t m_timeStamp{};
        double m_temperature{};
        double m_pressure{};
        Level m_level{};
        size_t m_payloadSize{};
    
    public:
        // constructors
        TelemetryPacket() = default; 
        TelemetryPacket(int id_, const std::string& tag_, std::uint64_t timestamp_);
        TelemetryPacket(const TelemetryPacket& ) = delete ;// deleted copy constructor
        TelemetryPacket(TelemetryPacket&& other_)noexcept; // move constructor
        TelemetryPacket& operator =(TelemetryPacket&& other_) noexcept; // move Assignment

        // member function --> set readings
        void setReadings(double temp_, double pres_);
        void setLevel(Level&& lvl);
        void print() const;

        // deleted copying from lvalue level
        void setLevel(const Level& ) = delete;

        //Helper --> get string value of level
        std::string getLevelName() const;
};

#endif // INC_5699368_MD4_TASK4_TELEMETRYPACKET_H
