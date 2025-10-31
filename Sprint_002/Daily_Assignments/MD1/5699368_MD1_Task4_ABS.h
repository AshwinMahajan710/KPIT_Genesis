#ifndef INC_5699368_MD1_TASK4_ABS_H
#define INC_5699368_MD1_TASK4_ABS_H

#include<string>
#include"5699368_MD1_Task4_SafetyFeature.h"

class ABS:public SafetyFeature{
    private:
        double m_wheelSpeedSensorAccuracy;
    public:
        // constructor
        ABS() = default;
        ABS(const std::string& featureName_, bool isEnabled_, double wheelSpeedSensorAccuracy_);
        ABS(const ABS& other) = delete; // so that no one can use it

        void activated() override final;
        void show() override;
};

#endif // INC_5699368_MD1_TASK4_ABS_H
