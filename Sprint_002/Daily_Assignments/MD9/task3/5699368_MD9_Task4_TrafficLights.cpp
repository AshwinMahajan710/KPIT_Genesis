#include<string>
#include"5699368_MD9_Task4_TrafficLights.h"

// constructor
TrafficLights::TrafficLights(int id_, const std::string& light_): m_state(light_), m_id(id_){}

// for cycling through states
void TrafficLights::changeState(){
    if(m_state == "Red") {m_state = "Green";}
    else if(m_state == "Green") {m_state = "Yellow";}
    else {m_state = "Red";}
}

// for getting info in strings
std::string TrafficLights::toString(){
    return ("\nId: " + std::to_string(m_id) + " State: " + m_state + "\n");
}