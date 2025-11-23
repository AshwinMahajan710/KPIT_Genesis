#include<string>
#include"5699368_MD9_Task2_Event.h"

// constructor
Event::Event(const std::string& src, const std::string& data): m_payload(data), m_source(src) {}

// getters
std::string Event::getSource() const{
    return m_source;
}

std::string Event:: getPayload() const{
    return m_payload;
}