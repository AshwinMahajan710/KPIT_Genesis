#ifndef MD14_5699368_TASK1_SENSORREADING_H
#define MD14_5699368_TASK1_SENSORREADING_H

#include<string>
#include<variant>

class SensorReading{
    private:
        std::string m_sensorName{};
        std::variant<int , float, std::string> m_value;
    public:
        SensorReading() = default;
        SensorReading(const std::string& name_, const std::variant<int , float, std::string >& val_);
        ~SensorReading() = default;
        SensorReading(const SensorReading&) = default;
        SensorReading(SensorReading&&) = default;
        SensorReading& operator =(const SensorReading&) = default;
        SensorReading& operator =(SensorReading&&) = default;

        std::string getName() const;
        std::variant<int , float, std::string> getValue() const;
        std::string getValueAsString() const;
        void updateValue(std::variant<int , float, std::string >& val_);
};

#endif // MD14_5699368_TASK1_SENSORREADING_H
