#ifndef INC_5699368_MD17_TASK1_SENSORDATA_H
#define INC_5699368_MD17_TASK1_SENSORDATA_H

#include<string>

class Sensordata{
    private:
        std::string m_moduleName; // must not be empty
        double m_value; // should be non-negative
        bool m_isValid;
        
    public:
        Sensordata() = default;
        Sensordata(const std::string& moduleName_, double value_, bool isValid_);
        Sensordata(const Sensordata&)= default;
        Sensordata& operator=(const Sensordata&)= default;
        Sensordata(Sensordata&&)= default;
        Sensordata& operator=(Sensordata&&)= default;
        ~Sensordata() = default;

        // getters
        std::string getModuleName() const;
        double getValue() const;
        bool isValidReading() const;
};

#endif // INC_5699368_MD17_TASK1_SENSORDATA_H
