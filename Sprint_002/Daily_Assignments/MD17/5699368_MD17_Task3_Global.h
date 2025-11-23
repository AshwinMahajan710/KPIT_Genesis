#ifndef INC_5699368_MD17_TASK3_GLOBAL_H
#define INC_5699368_MD17_TASK3_GLOBAL_H

#include<string>
#include"5699368_MD17_Task3_SensorEvent.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<list>

// for counting critical events using count_if
size_t countCriticalEvents(const std::list<SensorEvent>& events);

// for finding first critical event using std::find_if
std::list<SensorEvent>::const_iterator findFirstCriticalEvent(const std::list<SensorEvent>& events);

// returns iterator after advancing the steps using std::next
std::list<SensorEvent>:: const_iterator getNextEvent(std::list<SensorEvent>::const_iterator&it, size_t steps);

// advances iterator in step by using std::advance
void advanceToEvent(std::list<SensorEvent>::const_iterator& it, size_t steps);

// print the event
void printEvent(const SensorEvent& event);

#endif // INC_5699368_MD17_TASK3_GLOBAL_H
