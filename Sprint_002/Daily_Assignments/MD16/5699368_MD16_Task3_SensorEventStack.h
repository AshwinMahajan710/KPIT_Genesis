#ifndef INC_5699368_MD16_TASK3_SENSOREVENTSTACK_H
#define INC_5699368_MD16_TASK3_SENSOREVENTSTACK_H

#include<string>
#include<iostream>
#include"5699368_MD16_Task3_SensorEvent.h"
#include<stack>
#include<memory>

class SensorEventStack{
    private:
        std::stack<std::unique_ptr<SensorEvent>> m_eventStack;
    public:
        SensorEventStack() = default;
        SensorEventStack(const SensorEventStack&) =delete;
        SensorEventStack(SensorEventStack&&) = default;

        void pushEvent(std::unique_ptr<SensorEvent>&& event);
        std::unique_ptr<SensorEvent> popEvent();
        bool isEmpty() const;
        size_t size() const;

        // getters for stack
        std::stack<std::unique_ptr<SensorEvent>>& getEventStack();
};

#endif // INC_5699368_MD16_TASK3_SENSOREVENTSTACK_H
