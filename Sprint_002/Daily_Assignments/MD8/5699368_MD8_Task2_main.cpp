#include<vector>
#include<string>
#include<mutex>
#include"5699368_MD8_Task2_ImageProcessor.h"
#include<iostream>
#include<thread>

int main(){

    // instantiating object of imageprocessor
    ImageProcessor processor(std::vector<int>(1000,0));

    // try to display
    processor.display();

    // run in parallel all threads
    processor.runInParallel();

    // try to display again
    processor.display();
    
    return 0;
}   