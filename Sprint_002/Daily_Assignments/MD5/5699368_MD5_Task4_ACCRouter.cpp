#include<string>
#include<functional>
#include<vector>
#include<iostream>
#include"5699368_MD5_Task4_ACCRouter.h"

// to add handler
void ACCRouter::addHandler(std::function<void (const Event& )> h){
    handlers.push_back(h);
}

// to remove handler
void ACCRouter::removeHandler(size_t idx_){
    handlers.erase(handlers.begin() + idx_);
}

// to dispatch
void ACCRouter::dispatch(const Event& e){
    std::cout<<"\nDispatching all events: "<<std::endl;
    for(auto &i : handlers){
        std::cout<<"\n";
        i(e);
    }   
}

// to replace
void ACCRouter::replaceHandler(size_t idx_, std::function<void (const Event& )> h){
    handlers[idx_] = h;
}