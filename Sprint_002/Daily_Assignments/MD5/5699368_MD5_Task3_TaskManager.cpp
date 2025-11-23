#include<vector>
#include<functional>
#include"5699368_MD5_Task3_TaskManager.h"
#include<iostream>

// adding task 
void TaskManager::addtask(std::function<void()> newtask){
        tasks.push_back(newtask);
}

// running all tasks
void TaskManager::runAll(){
        std::cout<<"\nRunning all tasks..."<<std::endl;
        for(auto &i: tasks){
                i();
        }
}