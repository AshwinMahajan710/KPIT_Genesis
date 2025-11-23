#include<string>
#include<mutex>
#include<functional>
#include"5699368_MD9_Task2_Event.h"
#include"5699368_MD9_Task2_Aggregator.h"
#include<thread>
#include<iostream>
#include<vector>

int main(){

    // creating lambda function
    auto preprocess = [] (const Event& e) -> std::string {return ("<" + e.getSource() + ">" + e.getPayload());};

    // creating vector of event
    std::vector<Event> events;
    events.emplace_back(Event("Navigation","pose=12.3, heading=87"));
    events.emplace_back(Event("Vision","object= 5, confidence=0.91"));
    events.emplace_back(Event("Control","throttle=0.52, Brake=0.0"));
    events.emplace_back(Event("Diagnostics","temp = 65, voltage=12.1"));

    // creating object or aggregator
    Aggregator aggregator("TelemetryAggregator");

    // creating vector of threads
    std::vector<std::thread> threads;
    for(auto &event: events){
        threads.emplace_back(&Aggregator::process, &aggregator, std::move(event), std::ref(preprocess));
    }

    // joining the threads
    for(auto &thread: threads){
        if(thread.joinable()){
            thread.join();
        }
    }

    std::cout<<"All events processed"<<std::endl;
}