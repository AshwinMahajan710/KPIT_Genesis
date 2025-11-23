#ifndef SENSOR_H
#define SENSOR_H

#include<string>
#include<functional>

class Sensor{
    private:
        int m_id{};
        std::string m_type{};
        double m_value{};
        double m_threshold{};
        std::function<void(int,double)> f_onTrigger;

    public:
        // constructor
        Sensor(int id_, const std::string& type_, double value_, double threshold_);
        Sensor() = default;

        void update(double value_);
        void setHandler(std::function<void(int,double)>);

        // helper --> getter for threshold
        double getThreshold() const;
};  

#endif // SENSOR_H
