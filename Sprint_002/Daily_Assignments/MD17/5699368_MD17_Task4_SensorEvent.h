#ifndef INC_5699368_MD17_TASK4_SENSOREVENT_H
#define INC_5699368_MD17_TASK4_SENSOREVENT_H

#include<string>
#include<variant>

class SensorEvent{
    private:
        std::string m_sourceModule;
        std::variant<int , double, std::string> m_payload;
        bool m_isUrgent;
    public:
        SensorEvent()  = delete;
        SensorEvent(const std::string& sourceModule_, std::variant<int,double,std::string> payload_, bool isUrgent_);
        SensorEvent(const SensorEvent&) = default;
        SensorEvent& operator=(const SensorEvent&) = default;
        SensorEvent(SensorEvent&&) = default;
        SensorEvent& operator=(SensorEvent&&) = default;
        ~SensorEvent() = default;

        // getters
        std::string getSourceModule() const;
        const std::variant<int, double, std::string>& getPayload() const;
        bool isUrgentEvent() const;
    
};

#endif // INC_5699368_MD17_TASK4_SENSOREVENT_H
