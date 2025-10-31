#ifndef INC_5699368_MD1_TASK4_AIRBAG_H
#define INC_5699368_MD1_TASK4_AIRBAG_H

#include<string>
#include"5699368_MD1_Task4_SafetyFeature.h"

class Airbag:public SafetyFeature{
    private:
        int m_deploymentThreshold;
    public:
        // constructor
        Airbag() = default;
        Airbag(const std::string& featureName_, bool isEnabled_, int deplymentThreshold_);
        Airbag(const Airbag& other) = delete; // so that no one can use it

        void activated() override;
        void show() override;
};

#endif // INC_5699368_MD1_TASK4_AIRBAG_H
