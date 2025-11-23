#ifndef INC_5699368_MD9_TASK4_TRAFFICLIGHTS_H
#define INC_5699368_MD9_TASK4_TRAFFICLIGHTS_H

#include<string>

class TrafficLights{
    private:
        int m_id{};
        std::string m_state{"Red"};
        int m_cycleDuration;
    public:
        TrafficLights() = default;
        TrafficLights(int id_, const std::string& light_= "Red");

        // for cycling through states
        void changeState();
        std::string toString();
};

#endif // INC_5699368_MD9_TASK4_TRAFFICLIGHTS_H
