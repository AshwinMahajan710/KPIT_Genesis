#include"5699368_MD3_Task4_DTC.h"
#include"5699368_MD3_Task4_Global.h"
#include<iostream>

// print all DTC information and also skips null pointer if any
void displayAllDTCs(DTC* const* array, const int size){
    if(array == nullptr) {return;}
    for(size_t i=0;i<size;i++){
        if(array[i] != nullptr){
            std::cout<<std::endl;
            array[i]->printDTCInfo();
        }
    }
}
