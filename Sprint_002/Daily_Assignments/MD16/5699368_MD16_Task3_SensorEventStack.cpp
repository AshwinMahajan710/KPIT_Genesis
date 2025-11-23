#include<string>
#include<iostream>
#include"5699368_MD16_Task3_SensorEvent.h"
#include<stack>
#include<memory>
#include<stdexcept>
#include"5699368_MD16_Task3_SensorEventStack.h"

// pushing the ptr 
void SensorEventStack::pushEvent(std::unique_ptr<SensorEvent>&& event){
    m_eventStack.emplace(std::move(event));
    std::cout<<"\nSensor added to stack successfully..."<<std::endl;
}

// poping the ptr
std::unique_ptr<SensorEvent> SensorEventStack::popEvent(){
    if(isEmpty()) {throw std::runtime_error("Stack is empty..");}
    else{
        auto sensorEvent = std::move(m_eventStack.top());
        m_eventStack.pop();
        return sensorEvent;
    }
}

// checking of stack is empty
bool SensorEventStack::isEmpty() const{
    return m_eventStack.empty();
}

// getting size of the stack
size_t SensorEventStack::size() const{
    return m_eventStack.size();
}

// getter for stack
std::stack<std::unique_ptr<SensorEvent>>& SensorEventStack:: getEventStack(){
    return m_eventStack;
}