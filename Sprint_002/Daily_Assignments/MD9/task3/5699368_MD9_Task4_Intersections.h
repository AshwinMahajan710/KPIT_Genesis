#ifndef INC_5699368_MD9_TASK4_INTERSECTIONS_H
#define INC_5699368_MD9_TASK4_INTERSECTIONS_H

#include<string>
#include"5699368_MD9_Task4_TrafficLights.h"
#include<vector>
#include<mutex>
#include<functional>

class Intersection{
    private:
        int m_id{};
        std::vector<TrafficLights> m_lights; // two perpendicular lights
        std::mutex m_mtx;
        std::function<int (const TrafficLights& )> m_cyclePolicy;
        std::function<void (const std::string& )> m_logger;

    public:
        Intersection() = default;
        Intersection(int id_, std::vector<TrafficLights> lights_, std::function<int(const TrafficLights&)> policy_);

        // run the threads
        void run(); // only one light can be green at one time
};

#endif // INC_5699368_MD9_TASK4_INTERSECTIONS_H
