
#include<string>
#include<functional>
#include<vector>
#include<iostream>
#include"5699368_MD5_Task4_ACCRouter.h"
#include"5699368_MD5_Task4_Global.h"

// free function
void logEvent(const Event& e){
    std::cout<<"\n[Free function] Logging: "<<e.label<<" Value: "<<e.value_<<std::endl;
}

// class function 
void Controller::onSpeed(const Event&e){
    std::cout<<"\n[In class function]--> Name: "<<m_name<<" Logging: "<<e.label<<" Value: "<<e.value_<<std::endl;
}

Controller::Controller(std::string name){
    m_name = name;
}

// functor
void SafetyFunctor::operator()(const Event& e){
    std::cout<<"\n[Functor] ---> ID: "<<m_id<<" Logging: "<<e.label<<" Value: "<<e.value_<<" Counter: "<<++counter<<std::endl;
}

void SafetyFunctor::setId(int id_){
    m_id = id_;
}