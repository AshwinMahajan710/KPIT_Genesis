#include<string>
#include<mutex>
#include"5699368_MD9_Task1_Logger.h"
#include<iostream>
#include<thread>
#include<vector>
#include<functional>

int main(){

    // creating vectors
    std::vector<Logger> loggers;

    // adding 3 loggers to vector
    loggers.emplace_back("Navigation");
    loggers.emplace_back("Vision");
    loggers.emplace_back("Control");

    // creating threads
    std::vector<std::thread> threads;
    for(auto &logger: loggers){
        std::function<void(int)> task = std::ref(logger);
        threads.emplace_back(task,5);        
    }

    // attach threads
    for(auto &thread: threads){
        if(thread.joinable()){
            thread.join();
        }
    }

    return 0;
}