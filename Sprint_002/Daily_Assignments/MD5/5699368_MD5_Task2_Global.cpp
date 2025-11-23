#include<iostream>
#include<vector>
#include<functional>
#include<string>
#include"5699368_MD5_Task2_AlertManager.h"
#include"5699368_MD5_Task2_Global.h"


// implementing callable types
void logalert(std::string str_, double val_){
    std::cout<<"\nAlert: "<<str_<<" Val: "<<val_<<std::endl;
}


void Logger::record(std::string str_, double val_){
    std::cout<<"\n[Logger Member function] Alert: "<<str_<<" Val: "<<val_<<std::endl;
}
    
void AlertFunctor::operator()(std::string str_, double val_){
    std::cout<<"\n[Alert Functor opeartor()] Alert: "<<str_<<" Val: "<<val_<<std::endl;
}

