#ifndef SENSOR_H
#define SENSOR_H

#include<string>
#include<chrono>

class Sensor{
    private:
        std::string m_name{};
        int m_minVal{};
        int m_maxVal{};
        int m_iterations{}; //num of readings to simulate

    public:
        Sensor() = default;
        Sensor(const std::string& name_, int minVal_, int maxVal_, int iterations_ = 5);        
        void run() const;
        
};

#endif // SENSOR_H
