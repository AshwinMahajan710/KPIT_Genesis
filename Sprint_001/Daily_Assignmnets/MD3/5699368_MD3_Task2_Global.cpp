#include"5699368_MD3_Task2_DTC.h"
#include"5699368_MD3_Task2_Global.h"
#include<iostream>

// print all DTC information and also skips null pointer if any
void displayAllDTCs(DTC* const* array_, const int size_){
    if(array_ == nullptr) {return;}
    for(size_t i=0;i<size_;i++){
        if(array_[i] != nullptr){
            std::cout<<std::endl;
            array_[i]->printDTCInfo();
        }
    }
}