#ifndef INC_5699368_MD17_TASK1_SENSORREADING_H
#define INC_5699368_MD17_TASK1_SENSORREADING_H

#include<string>

class SensorReading{
    private:
        std::string m_moduleName; // must not be empty
        double m_value; // should be non-negative
        bool m_isfaulty;
        
    public:
        SensorReading() = default;
        SensorReading(const std::string& moduleName_, double value_, bool isValid_);
        SensorReading(const SensorReading&)= default;
        SensorReading& operator=(const SensorReading&)= default;
        SensorReading(SensorReading&&)= default;
        SensorReading& operator=(SensorReading&&)= default;
        ~SensorReading() = default;

        // getters
        std::string getModuleName() const;
        double getValue() const;
        bool isFaultyModule() const;

        // display function
        void display() const;
        
};

#endif // INC_5699368_MD17_TASK1_SENSORREADING_H
