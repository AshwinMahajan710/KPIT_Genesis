#ifndef INC_5699368_MD4_TASK2_SIGNALBUFFER_H
#define INC_5699368_MD4_TASK2_SIGNALBUFFER_H

#include<string>
#include"5699368_MD4_Task3_Status.h"

class SignalBuffer{
    private:
        int m_id{};
        std::string m_source{};
        float m_strength{-999.0f};
        std::uint64_t m_timeStamp{};
        Status m_status{};

    public:
        // constructor
        SignalBuffer() = default;
        SignalBuffer(int id_, const std::string& source_, float strength_, std::uint64_t timeStamp_, Status status_);
        
        // move constructor and move assignment
        SignalBuffer(SignalBuffer&& ) noexcept;
        SignalBuffer& operator= (SignalBuffer&& ) noexcept;
        // member functions
        void updateStrength(float stregth_);
        void setStatus(Status&& status_);
        void print() const;
        float getStrength() const;
        Status getStatus() const;
        
        // helper --> to get status as string
        std::string getStatusName() const;

        // deleted operations
        SignalBuffer(const SignalBuffer& other) = delete;
        SignalBuffer& operator=(const SignalBuffer& other) = delete;
        void setStatus(const Status& ) = delete;
};

#endif // INC_5699368_MD4_TASK2_SIGNALBUFFER_H
