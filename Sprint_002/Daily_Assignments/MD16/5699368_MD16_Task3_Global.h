#ifndef INC_5699368_MD16_TASK3_GLOBAL_H
#define INC_5699368_MD16_TASK3_GLOBAL_H

#include<string>
#include<iostream>
#include"5699368_MD16_Task3_SensorEvent.h"
#include<stack>
#include<memory>
#include<stdexcept>
#include"5699368_MD16_Task3_SensorEventStack.h"
#include<vector>

// function to create event
std::unique_ptr<SensorEvent> createEvent(const std::string& id_, double value_, const std::string& description_);

// creating events in the batch
std::vector<std::unique_ptr<SensorEvent>> batchCreateEvents(std::vector<std::tuple<std::string, double, std::string>> &rawData);


// transfering events
void transferEvents(std::vector<std::unique_ptr<SensorEvent>> & source, SensorEventStack& destination);

// printing all events
void printAllEvents(SensorEventStack& stack);

// cheking that particular event is high value or not
bool isHighValueEvent(const SensorEvent& event, double threshold);

#endif // INC_5699368_MD16_TASK3_GLOBAL_H
