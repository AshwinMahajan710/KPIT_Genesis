#ifndef INC_5699368_MD15_TASK3_SENSORGRID_H
#define INC_5699368_MD15_TASK3_SENSORGRID_H

#include<string>
#include"5699368_MD15_Task3_SensorNode.h"
#include"5699368_MD15_Task3_PressureSensor.h"
#include"5699368_MD15_Task3_TemperatureSensor.h"
#include<array>
#include<memory>

class SensorGrid{
    private:
        std::array<std::shared_ptr<SensorNode>, 5> m_sensors;
    public:
        SensorGrid() = default;
        void setSensor(size_t index, std::shared_ptr<SensorNode> sensor_);
        void updateSensor(size_t idx, double value);
        std::pair<double, double> getMinMaxValues() const;
        size_t getActiveSensorCount(double threshold_) const;
};

#endif // INC_5699368_MD15_TASK3_SENSORGRID_H
