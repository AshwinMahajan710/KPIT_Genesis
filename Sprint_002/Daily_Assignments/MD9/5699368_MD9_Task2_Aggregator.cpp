#include<string>
#include<mutex>
#include<functional>
#include"5699368_MD9_Task2_Event.h"
#include"5699368_MD9_Task2_Aggregator.h"
#include<thread>
#include<iostream>

// constructor
Aggregator::Aggregator(const std::string& n): m_name(n){}

// public function
void Aggregator::process(Event ev, const std::function<std::string(const Event&)>& preproc){
    std::lock_guard<std::mutex> lock(m_mtx);
    std::string result = preproc(ev);
    std::cout<<m_name<<" processed --> "<<result<<std::endl;
}