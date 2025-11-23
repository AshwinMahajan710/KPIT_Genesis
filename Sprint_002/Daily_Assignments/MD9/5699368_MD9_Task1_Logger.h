#ifndef INC_5699368_MD9_TASK1_LOGGER_H
#define INC_5699368_MD9_TASK1_LOGGER_H

#include<string>
#include<mutex>

class Logger{
    private:
        std::string m_name{};
        std::mutex m_mtx;

    public:
        Logger() = default;
        Logger(std::string&& name_);

        // deleted copy constructor and assignment
        Logger(const Logger& log) = delete;
        Logger& operator = (const Logger& log) = delete;

        // Allow move constrcutor and move assignment
        Logger(Logger&& log);
        Logger& operator = (Logger&& log);

        //display function
        void logMessage(const std::string& msg);
        
        //functor operator 
        void operator ()(int count);
};

#endif // INC_5699368_MD9_TASK1_LOGGER_H
