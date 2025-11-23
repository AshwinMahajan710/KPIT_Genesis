#include<string>
#include<variant>
#include"5699368_MD17_Task4_SensorEvent.h"
#include<stdexcept>
#include<list>
#include<memory>
#include<functional>
#include"5699368_MD17_Task4_EventDispatcher.h"
#include<algorithm>

// function to set the handler
void EventDispatcher::setHandler(std::function<void(const SensorEvent&)> func){
    m_handler = std::move(func);
}

// function to addEvent
void EventDispatcher::addEvent(std::shared_ptr<SensorEvent> event){
    m_eventQueue.emplace_back(std::move(event));
}

// function to deploy urgent events 
void EventDispatcher::dispatchUrgentEvents(){
    std::for_each(m_eventQueue.begin(), m_eventQueue.end(),[this](const std::shared_ptr<SensorEvent>& event) {if(event->isUrgentEvent()) {m_handler(*event);}});
}

// getting queue size
size_t EventDispatcher::getQueueSize() const{
    return m_eventQueue.size();
}

// checking that ahs any urgent event or not
bool EventDispatcher::hasAnyUrgentEvent() const{
    return std::any_of(m_eventQueue.begin(), m_eventQueue.end(),[](const std::shared_ptr<SensorEvent>& event){return event->isUrgentEvent();});
}

// checking are all events valid
bool EventDispatcher::areAllEventsValid() const {
    return std::all_of(
        m_eventQueue.begin(),
        m_eventQueue.end(),
        [](const std::shared_ptr<SensorEvent>& event) {

            // invalid if source module is empty
            if (event->getSourceModule().empty())
                return false;

            // if payload is a string, it must not be empty
            if (std::holds_alternative<std::string>(event->getPayload())) {
                const auto& s = std::get<std::string>(event->getPayload());
                if (s.empty())
                    return false;
            }

            return true;
        }
    );
}

// checking that the there is no module of given name present
bool EventDispatcher::noneFromModule(const std::string& module) const{
    return std::none_of(m_eventQueue.begin(), m_eventQueue.end(), [&module](const std::shared_ptr<SensorEvent>& event){return event->getSourceModule()==module;});
}

// returning nthEVent
std::list<std::shared_ptr<SensorEvent>> EventDispatcher:: getNthEvent(size_t n){
    if(n>=m_eventQueue.size()) {throw std::runtime_error("InvalidArgument");};
    std::list<std::shared_ptr<SensorEvent>> list;
    list.emplace_back(*std::next(m_eventQueue.begin(),n));
    return list;
}