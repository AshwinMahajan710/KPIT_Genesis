#include<vector>
#include<functional>
#include"5699368_MD5_Task3_TaskManager.h"
#include<iostream>
#include"5699368_MD5_Task3_Global.h"

// free function --> logging a message
void logTask(){
    std::cout<<"\n[Free Function] Task is performing.."<<std::endl;
}

// --> perform work with id
void Worker::doWork(int id_){
    std::cout<<"\n[Worker class Function] Task is performing for id: "<<id_<<std::endl;
}

// functor
void TaskFunctor::operator()(){
    std::cout<<"\n[Functor] Task is performing.."<<std::endl;
}
