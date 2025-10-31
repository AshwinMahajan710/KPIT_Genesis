#ifndef INC_5699368_MD1_TASK2_SAFETYFEATURE_H
#define INC_5699368_MD1_TASK2_SAFETYFEATURE_H

#include<string>

class SafetyFeature{
    private:
        std::string m_featureName;
        bool m_isEnabled;
    public:
        // constructor
        SafetyFeature() = default;
        SafetyFeature(const std::string& featureName_, bool isEnabled_);
        SafetyFeature(const SafetyFeature& other) = delete; // so that no one can use it

        virtual void activated();
        virtual void show();
};

#endif // INC_5699368_MD1_TASK2_SAFETYFEATURE_H
