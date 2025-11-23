#include<string>
#include"5699368_MD17_Task3_SensorEvent.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<list>
#include"5699368_MD17_Task3_Global.h"
#include<algorithm>

int main(){

    // creating 6 readings of sensorEvent
    std::list<SensorEvent> readings = {
        {"Brake", 100.0, true},
        {"Engine", 200.0, true},
        {"Pedal", 300.0, false},
        {"ECU", 400.0, false},
        {"OIL", 500.0, false},
    };

    std::cout<<"\nTotal Readings count: "<<readings.size()<<std::endl;
    
    // counting critical events
    std::cout<<"\nCritical Events count: "<<countCriticalEvents(readings)<<std::endl;

    // getting first critical event
    std::list<SensorEvent>::const_iterator firstCritical = findFirstCriticalEvent(readings);
    std::cout<<"\nFirst Critical Event: "<<std::endl;
    firstCritical->display();
    
    // go to next 2 steps from first critical 
    std::list<SensorEvent>::const_iterator twoStepNextEvent = getNextEvent(firstCritical,2);
    std::cout<<"\nAfter NEXT two steps: "<<std::endl;
    twoStepNextEvent->display();
    
    // go to next using advance
    advanceToEvent(twoStepNextEvent,2);
    std::cout<<"\nAfter advancing two steps: "<<std::endl;
    twoStepNextEvent->display();

    return 0;
}