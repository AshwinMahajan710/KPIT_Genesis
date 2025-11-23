#include<string>
#include<iostream>
#include"5699368_MD16_Task3_SensorEvent.h"
#include<stack>
#include<memory>
#include<stdexcept>
#include"5699368_MD16_Task3_SensorEventStack.h"
#include<vector>
#include"5699368_MD16_Task3_Global.h"

int main(){

    // creating sensorEvent obj
    SensorEventStack st;

    // creating 3 events and push them
    std::unique_ptr<SensorEvent> event1 = createEvent("101",100,"Engine Sensor");
    std::unique_ptr<SensorEvent> event2 = createEvent("102",110,"Brake Sensor");
    std::unique_ptr<SensorEvent> event3 = createEvent("103",120,"Carborator Sensor");

    // creating batch of 2 events
    std::vector<std::tuple<std::string, double, std::string >> eventValues;
    eventValues.push_back(std::make_tuple("104",140,"ECU Sensor"));
    eventValues.push_back(std::make_tuple("105",150,"CAN Sensor"));
    std::vector<std::unique_ptr<SensorEvent>> events = batchCreateEvents(eventValues);
    events.emplace_back(std::move(event1));
    events.emplace_back(std::move(event2));
    events.emplace_back(std::move(event3));
    
    // pushing all events in st
    transferEvents(events, st);

    // printing all events
    std::cout<<"\nPrinting all events: "<<std::endl;
    printAllEvents(st);
    
    // 
    return 0;
}   