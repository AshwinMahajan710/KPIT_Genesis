#ifndef INC_5699368_MD14_TASK2_SENSORDATA_H
#define INC_5699368_MD14_TASK2_SENSORDATA_H

#include<variant>
#include<string>

class Sensordata{
    private:
        std::string m_sensorID;
        std::variant<int , float, std::string> m_reading;

    public:
        Sensordata() = default;
        Sensordata(const std::string& id_, const std::variant<int, float, std::string>& value);
        ~Sensordata() = default;
        Sensordata(const Sensordata&) = default;
        Sensordata& operator =(const Sensordata&) = default;
        Sensordata(Sensordata&&) = default;
        Sensordata& operator =(Sensordata&&) = default;

        // getters
        std::string getId() const;
        bool isInt() const;
        bool isString() const;
        bool isFloat() const;
        std::variant<int , float, std::string> getVariant() const;
        
        // printing the message in variant
        void processReading() const;
};

#endif // INC_5699368_MD14_TASK2_SENSORDATA_H
