#ifndef INC_5699368_MD9_TASK1_EVENT_H
#define INC_5699368_MD9_TASK1_EVENT_H

#include<string>

class Event{
    private:
        std::string m_source{};
        std::string m_payload{};
    public:
        Event() = delete;
        Event(const std::string& src, const std::string& data);

        // delete copy and default move
        Event(const Event& other) = delete;
        Event& operator =(const Event& other) = delete;
        Event(Event&& other) = default;
        Event& operator =(Event&& other) = default;

        // getters
        std::string getSource() const;
        std::string getPayload()const;
};

#endif // INC_5699368_MD9_TASK1_EVENT_H
