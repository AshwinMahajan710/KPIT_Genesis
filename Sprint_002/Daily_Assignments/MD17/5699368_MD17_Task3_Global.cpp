#include<string>
#include"5699368_MD17_Task3_SensorEvent.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<list>
#include"5699368_MD17_Task3_Global.h"
#include<algorithm>

// for counting critical events using count_if
size_t countCriticalEvents(const std::list<SensorEvent>& events){
    return std::count_if(events.begin(), events.end(),[](const SensorEvent& event) {return event.getIsCriticalEvent();});
}

// for finding first critical event using std::find_if --> always returns evenets.end() in case not found
std::list<SensorEvent>::const_iterator findFirstCriticalEvent(const std::list<SensorEvent>& events){
    auto founded = std::find_if(events.begin(), events.end(), [](const SensorEvent& event){return event.getIsCriticalEvent();});
    return founded;
}

// returns iterator after advancing the steps using std::next --> std::next returns new_iterator everytime using it so return iterator when using it anywhere
std::list<SensorEvent>:: const_iterator getNextEvent(std::list<SensorEvent>::const_iterator&it, size_t steps){
    return std::next(it, steps);
}

// advances iterator in step by using std::advance --> std::advance is used for inplace update instead of std::next
void advanceToEvent(std::list<SensorEvent>::const_iterator& it, size_t steps){
    std::advance(it, steps);
}

// print the event
void printEvent(const SensorEvent& event){
    event.display();
}