#include<iostream>
#include<vector>
#include<functional>
#include<string>
#include<memory>
#include"5699368_MD5_Task2_AlertManager.h"
#include"5699368_MD5_Task2_Global.h"

int main(){

    // creating some callables
    auto lambda = [=](std::string str_, double val){std::cout<<"\n[Lambda =]Alert: "<<str_<<" Value: "<<val<<std::endl;};
    
    // lambda with callcount
    int count_ = 0;
    auto lambda2 = [&count_](std::string str_, double val) mutable {std::cout<<"\n[Lambda &]Alert: "<<str_<<" Value: "<<val<<" Count: "<<++count_<<std::endl;};

    // creating unique ptr --> and after that binding it
    std::unique_ptr<Logger> logger = std::make_unique<Logger>();
    auto boundFunc = std::bind(&Logger::record, logger.get(), std::placeholders::_1, std::placeholders::_2);

    // free function reference using std::ref
    auto refFunc = std::ref(logalert);

    // creating sahred ptr
    std::shared_ptr<AlertFunctor> functor = std::make_shared<AlertFunctor>();
    auto sharedFunctor = [functor](std::string label, double val) { (*functor)(label, val);};

    AltertManager manager;

    // Add all handlers to vector
    manager.handler.push_back(lambda);
    manager.handler.push_back(lambda2);
    manager.handler.push_back(boundFunc);
    manager.handler.push_back(refFunc);
    manager.handler.push_back(sharedFunctor);

    manager.dispatch("Engine",120);
    
    // removing one handler
    manager.handler.erase(manager.handler.begin());
    
    // print again
    manager.dispatch("Engine",120);

    return 0;
}