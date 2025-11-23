#ifndef INC_5699368_MD16_TASK3_SENSOREVENT_H
#define INC_5699368_MD16_TASK3_SENSOREVENT_H

#include<string>

class SensorEvent{
    private:
        std::string m_id;
        double m_value;
        std::string m_description;
    public:
        SensorEvent() = default;
        SensorEvent(const std::string& id_, double value_, const std::string& description_);
        SensorEvent ( const SensorEvent&) = delete;
        SensorEvent(SensorEvent&&) noexcept;
        SensorEvent& operator =( const SensorEvent&) = delete;
        SensorEvent& operator=(SensorEvent&&) noexcept;
        ~SensorEvent() = default;

        // getters
        std::string getId() const;
        double getValue() const;
        std::string getDescription() const;

        void print() const;
};

#endif // INC_5699368_MD16_TASK3_SENSOREVENT_H
