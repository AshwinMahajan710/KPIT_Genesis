#ifndef INC_5699368_MD17_TASK4_EVENTDISPATCHER_H
#define INC_5699368_MD17_TASK4_EVENTDISPATCHER_H

#include<string>
#include<variant>
#include"5699368_MD17_Task4_SensorEvent.h"
#include<stdexcept>
#include<list>
#include<memory>
#include<functional>

class EventDispatcher{
    private:
        std::list<std::shared_ptr<SensorEvent>> m_eventQueue;
        std::function<void(const SensorEvent&)> m_handler;
    public:
        EventDispatcher() = default;
        EventDispatcher(const EventDispatcher&) = delete;        
        EventDispatcher(EventDispatcher&&) = delete;        
        EventDispatcher& operator=(const EventDispatcher&) = delete;        
        EventDispatcher& operator=(EventDispatcher&&) = delete;        
        ~EventDispatcher() = default;

        // function to set the handler
        void setHandler(std::function<void(const SensorEvent&)>);

        // function to addEvent
        void addEvent(std::shared_ptr<SensorEvent> event);
        
        // function to deploy urgent events 
        void dispatchUrgentEvents();

        // getting queue size
        size_t getQueueSize() const;

        // checking that ahs any urgent event or not
        bool hasAnyUrgentEvent() const;

        // checking are all events valid
        bool areAllEventsValid() const;

        // checking that the there is no module of given name present
        bool noneFromModule(const std::string& module) const;

        // returning nthEVent
        std::list<std::shared_ptr<SensorEvent>> getNthEvent(size_t n);
};

#endif // INC_5699368_MD17_TASK4_EVENTDISPATCHER_H
