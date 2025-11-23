#include<string>
#include"5699368_MD15_Task3_SensorNode.h"

class PressureSensor: public SensorNode{
    public:
        PressureSensor() = default;
        PressureSensor(const std::string& id_, double value_);
       void updateVal(double newVal_) override;
};
