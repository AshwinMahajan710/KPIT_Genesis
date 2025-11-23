#include"5699368_MD4_Task3_SignalBuffer.h"
#include<string>
#include"5699368_MD4_Task3_Status.h"
#include<iostream>
#include"5699368_MD4_Task3_Global.h"

//using reference
void logByRef(const SignalBuffer& b){
    std::cout<<"\nPrinting details via call by Ref: "<<std::endl;
    b.print();
}

// using rvaluereference
void logByRRef(const SignalBuffer&& b){
    std::cout<<"\nPrinting details via call by R value Ref: "<<std::endl;
    b.print();
}

// using ptr
void logByPtr(const SignalBuffer* b){
    std::cout<<"\nPrinting details via pointer: "<<std::endl;
    b->print();
}