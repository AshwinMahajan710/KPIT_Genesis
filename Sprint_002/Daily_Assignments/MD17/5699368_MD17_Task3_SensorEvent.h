#ifndef INC_5699368_MD17_TASK3_SENSOREVENT_H
#define INC_5699368_MD17_TASK3_SENSOREVENT_H

#include<string>

class SensorEvent{
    private:
        std::string m_type;
        double m_value;
        bool m_isCritical;
    
    public:
        SensorEvent() = default;
        SensorEvent(const std::string& type_, double value_, bool isCritical_);
        SensorEvent(const SensorEvent&)= default;
        SensorEvent& operator=(const SensorEvent&)= default;
        SensorEvent(SensorEvent&&)= default;
        SensorEvent& operator=(SensorEvent&&)= default;
        ~SensorEvent() = default;

        // getters
        std::string getType() const;
        double getValue() const;
        bool getIsCriticalEvent() const;
        
        // helper -> display details
        void display() const;
};

#endif // INC_5699368_MD17_TASK3_SENSOREVENT_H
