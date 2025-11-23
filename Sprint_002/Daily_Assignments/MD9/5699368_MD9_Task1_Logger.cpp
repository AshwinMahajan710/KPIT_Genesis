#include<string>
#include<mutex>
#include"5699368_MD9_Task1_Logger.h"
#include<iostream>
#include<thread>

// constructor --> move operation on name 
Logger::Logger(std::string&& name_){
    m_name = std::move(name_);
}

// Allow move constructor and move assignment
Logger::Logger(Logger&& log){
    m_name = std::move(log.m_name);
}

// assignmnet operator using move operation
Logger& Logger:: operator = (Logger&& log){
    if(this!=&log){
        m_name = std::move(log.m_name);
    }
    return *this;
}

//display function
void Logger::logMessage(const std::string& msg){
    std::lock_guard<std::mutex> lock(m_mtx);
    std::cout<<"\nLogger Name: "<<m_name<<" Message: "<<msg<<std::endl;
}

//functor operator 
void Logger::operator ()(int count){
    for(int i=1;i<count;i++){
        logMessage("Message" + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout<<"Execution complete...."<<std::endl;
}