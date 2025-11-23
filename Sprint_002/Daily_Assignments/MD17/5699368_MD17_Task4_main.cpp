#include<string>
#include<variant>
#include"5699368_MD17_Task4_SensorEvent.h"
#include<stdexcept>
#include<list>
#include<memory>
#include<functional>
#include"5699368_MD17_Task4_EventDispatcher.h"
#include<algorithm>
#include<iostream>

int main(){

    // creating 5 sensors
    EventDispatcher dispatcher;
    
    // adding sensorEvents
    dispatcher.addEvent(std::make_shared<SensorEvent>("Engine",112,false));
    dispatcher.addEvent(std::make_shared<SensorEvent>("Brake",112.456,true));
    dispatcher.addEvent(std::make_shared<SensorEvent>("Gear","12",false));
    dispatcher.addEvent(std::make_shared<SensorEvent>("ECU","112",false));
    dispatcher.addEvent(std::make_shared<SensorEvent>("Exhaust",1123,true));

    // lamda handler that prints dtails of sensor
    auto lambda = [](const SensorEvent& other) -> void { std::cout<<"\nName: "<<other.getSourceModule()<<" Payload: ";
        std::visit([](auto&& ele){std::cout<<ele;}, other.getPayload());
        std::cout<< "is Urgent: "<<((other.isUrgentEvent()) ? "Yes": "No")<<std::endl;}; 
    
    // setting the handler
    dispatcher.setHandler(lambda);

    // dispatching urgent events
    std::cout<<"\nDispatching urgent events: "<<std::endl;
    dispatcher.dispatchUrgentEvents();

    // printing total no of sensorEvents in the queue
    std::cout<<"\nTotal no of events in queue: "<<dispatcher.getQueueSize()<<std::endl;

    // checking are all events valid
    if(dispatcher.areAllEventsValid()){std::cout<<"\nAll events are valid..."<<std::endl;}
    else{std::cout<<"\nAll events are not valid..."<<std::endl;}
    
    //chekcing non of module is from break
    if(dispatcher.noneFromModule("Brake")){std::cout<<"\nNone module from Brake..."<<std::endl;}
    else{std::cout<<"\nThere is module with name Brake..."<<std::endl;}

    
    
    return 0;
}