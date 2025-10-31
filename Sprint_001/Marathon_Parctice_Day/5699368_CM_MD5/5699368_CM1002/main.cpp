#include<iostream>
#include<string>
#include"Date.h"
#include"Exam.h"

int main(){

    // Testing Date Validation
    try{
        Date d1(15,8,2025); // TC1
        Date d2(29,2,2024); // TC2
        Date d3(31,4,2023); // TC3 ! --> exception will be invoked
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    try{
        Date d4(30,2,2023); // TC4 ! --> exception will be invoked
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    // Trying other test cases to create objects
    try{
        Exam exam1(101,ONLINE,15,8,25); //TC5
        exam1.display();
        Exam exam2(102,OFFLINE,29,2,24); //TC6
        exam2.display();
        Exam exam3(103,ONLINE,31,4,23);//TC7
        exam3.display();
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }


    return 0;
}