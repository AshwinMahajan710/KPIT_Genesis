#include<string>
#include<vector>
#include<functional>
#include"Sensor.h"
#include<iostream>

// constructor--> parametrized
Sensor::Sensor(const std::string& id_){
    m_id = id_;
}

// function to add functions in listener vector
void Sensor::addListeners(std::function<void(const std::string& )> listen_){
    m_listeners.push_back(listen_);
}

// triggering all callbacks with given message
void Sensor::triggerMessage(const std::string& message_){
    std::cout<<"Sensor "<<m_id<<" Triggering all messages: "<<std::endl;
    for(auto &i: m_listeners){
        i(message_);
    }
}

// Get sensor ID
std::string Sensor::getId() const { return m_id; }