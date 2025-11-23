#ifndef INC_5699368_MD5_TASK4_GLOBAL_H
#define INC_5699368_MD5_TASK4_GLOBAL_H

#include<string>
#include<functional>
#include<vector>
#include<iostream>
#include"5699368_MD5_Task4_ACCRouter.h"

// free function
void logEvent(const Event&);

// class
class Controller{
    std::string m_name{};
    public:
        Controller(std::string Name);
        void onSpeed(const Event&);
};

// functor
struct SafetyFunctor{
    int m_id{};
    static int counter;
    void operator()(const Event&);
    void setId(int id_);
};




#endif // INC_5699368_MD5_TASK4_GLOBAL_H
