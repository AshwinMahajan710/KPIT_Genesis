#ifndef SENSOR_H
#define SENSOR_H

#include<string>
#include"SensorType.h"

class Sensor{
    public:
        SensorType m_sensorType{};
        double m_range{};
        std::string m_resolution{};

        // constructors
        Sensor();
        Sensor(SensorType type_, double range_, const std::string& resolution_);

        // helper --> getsensor name
        std::string getSensorName() const;

};

#endif // SENSOR_H
