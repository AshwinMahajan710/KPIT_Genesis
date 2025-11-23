#include<vector>
#include<functional>
#include<memory>
#include"5699368_MD5_Task3_TaskManager.h"
#include<iostream>
#include"5699368_MD5_Task3_Global.h"

int main(){

    // lambda function
    int count = 0;
    auto lambda1 = [=, &count]() mutable {std::cout<<"\n[Lambda= ] Task is performing "<<++count<<" Times.."<<std::endl;};

    // creating the unique ptr for worker--> and binding its function
    std::unique_ptr<Worker> worker = std::make_unique<Worker> ();
    auto boundFunc = std::bind(&Worker::doWork, worker.get(),42); 

    // creating shared_ptr for functor
    std::shared_ptr<TaskFunctor> functor = std::make_shared<TaskFunctor> ();
    auto sharedBound = std::bind(&TaskFunctor::operator(), functor.get());

    // create object of task manager and adding tasks
    TaskManager manager;
    manager.addtask(logTask);// pushing free function
    manager.addtask(boundFunc);// bounding by passing constrant value
    manager.addtask(lambda1);// pushing lambda function   
    manager.addtask(sharedBound);// pushing taskFunctor function   
    manager.addtask(std::ref(logTask));// pushing free function via ref
    
    // calling runAll to verify all tasks
    manager.runAll();

    // dynamically removing task
    manager.tasks.erase(manager.tasks.begin());

    // rerun
    manager.runAll();
    
    return 0;
}