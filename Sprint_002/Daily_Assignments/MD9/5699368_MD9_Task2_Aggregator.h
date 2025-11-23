#ifndef INC_5699368_MD9_TASK2_AGGREGATOR_H
#define INC_5699368_MD9_TASK2_AGGREGATOR_H

#include<string>
#include<mutex>
#include<functional>
#include"5699368_MD9_Task2_Event.h"

class Aggregator{
    private:
        std::mutex m_mtx;
        std::string m_name{};
    public:
        Aggregator() = default;
        Aggregator(const std::string& n);

        // delete copy and default move
        Aggregator(const Aggregator& other) = delete;
        Aggregator& operator =(const Aggregator& other) = delete;
        Aggregator(Aggregator&& other) = default;
        Aggregator& operator =(Aggregator&& other) = default;

        // adding public member function
        void process(Event ev, const std::function<std::string(const Event&)>& preproc);
        
};

#endif // INC_5699368_MD9_TASK2_AGGREGATOR_H
