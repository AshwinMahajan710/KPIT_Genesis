#ifndef INC_5699368_MD2_TASK2_SENSOR_H
#define INC_5699368_MD2_TASK2_SENSOR_H

#include<string>
#include"5699368_MD4_Task2_State.h"

class Sensor{
    private:
        int m_id{}; // safe initialization
        std::string m_type{}; 
        float m_gain{};
        float m_offset{};
        State m_state{};
    
    public:
        // constsructors
        Sensor() = default;
        Sensor(int id_, const std::string & type_, float gain_, float offset_, State state_);

        // member functions
        void applyCallibration(float gain_, float offset_);
        void print() const;
        float getGain() const;
        State getState() const;

        // only rvalue ref are allowed
        void setState(State&&);
        void setState(const State&) = delete;
        Sensor(const Sensor&) = delete; // copy not allowed

        // helper --> get state name
        std::string getStateName() const;
};

#endif // INC_5699368_MD2_TASK2_SENSOR_H
