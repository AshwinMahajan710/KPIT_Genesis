#include<string>
#include<iostream>
#include"5699368_MD16_Task3_SensorEvent.h"
#include<stack>
#include<memory>
#include<stdexcept>
#include"5699368_MD16_Task3_SensorEventStack.h"
#include<vector>
#include"5699368_MD16_Task3_Global.h"

// function to create event
std::unique_ptr<SensorEvent> createEvent(const std::string& id_, double value_, const std::string& description_){
    std::unique_ptr<SensorEvent> sensorEvent = std::make_unique<SensorEvent>(id_, value_, description_);
    return sensorEvent;
}

// creating events in the batch
std::vector<std::unique_ptr<SensorEvent>> batchCreateEvents(std::vector<std::tuple<std::string, double, std::string>> &rawData){
    std::vector<std::unique_ptr<SensorEvent>> vectorOfEvents;
    for(auto& tuple: rawData){
        auto &[id_, value_, description] = tuple; // structural binding
        vectorOfEvents.emplace_back(std::make_unique<SensorEvent>(id_,value_,description));
    }
    return vectorOfEvents;
}


// transfering events
void transferEvents(std::vector<std::unique_ptr<SensorEvent>> & source, SensorEventStack& destination){
    for(auto &event: source){
        destination.pushEvent(std::move(event));
    }
}

// printing all events
void printAllEvents(SensorEventStack& stack){
    std::stack<std::unique_ptr<SensorEvent>>& eventStack =  stack.getEventStack();
    while(!stack.isEmpty()){
        std::unique_ptr<SensorEvent> event = std::move(eventStack.top());
        eventStack.pop();
        event->print();
        std::cout<<std::endl;
    }
}

// cheking that particular event is high value or not
bool isHighValueEvent(const SensorEvent& event, double threshold){
    if(event.getValue() > threshold) {return true;}
    return false;
}
