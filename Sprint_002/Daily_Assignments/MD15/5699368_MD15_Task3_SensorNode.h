#ifndef INC_5699368_MD15_TASK3_SENSORNODE_H
#define INC_5699368_MD15_TASK3_SENSORNODE_H

#include<string>

class SensorNode{
    protected:
        std::string m_id;
        double m_value;
    public:
        SensorNode() = default;
        SensorNode(const std::string& id_, double value_);

        virtual void updateVal(double newVal_);
        virtual double getVal() const;

        std::string getId() const;
};

#endif // INC_5699368_MD15_TASK3_SENSORNODE_H
