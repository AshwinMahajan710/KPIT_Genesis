#include<vector>
#include<functional>
#include<string>
#include"5699368_MD5_Task2_AlertManager.h"
#include<iostream>

void AltertManager::dispatch(const std::string& label_, double value_){
    std::cout<<"\nDispatching Alerts: "<<std::endl;
    for(auto &i: handler){
        std::cout<<std::endl;
        i(label_,value_);
    }
}