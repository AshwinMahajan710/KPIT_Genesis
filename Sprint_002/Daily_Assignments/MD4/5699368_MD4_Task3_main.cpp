#include"5699368_MD4_Task3_SignalBuffer.h"
#include<string>
#include"5699368_MD4_Task3_Status.h"
#include<iostream>
#include"5699368_MD4_Task3_Global.h"

int main(){

    // creatng object via different methods
    SignalBuffer sb1; // default constructor
    SignalBuffer sb2(501,"Alpha",-65.0,1620000000,Status::VALID); // member list initialization
    SignalBuffer sb3{502,"Beta",-85.0,1620000100,Status::WEAK}; // uniform initialization
    SignalBuffer sb4{}; // value initialization 
    SignalBuffer sb5;

    // updating signal strength
    sb1.updateStrength(12345.0);
    sb1.setStatus(Status::VALID);

    // attempting copy operation
    // SignalBuffer sb2 = sb1;// cannot be referenced error

    // using move constructor and move assignmnets
    sb1 = (SignalBuffer(504,"CETA",-95.0,1620000500,Status::WEAK)); // move assignment
    SignalBuffer sb6(SignalBuffer(507, "THETA", -100, 1620000700, Status::LOST)); // move constructor
    
    // logging using ;val , rval and pointer
    logByRef(sb1);
    logByRRef(std::move(sb2));
    logByPtr(&sb1);

    // Applying lamdas
    int threshold = 100;
    auto lambda1 = [threshold](){return threshold;}; // capture threshold by value
    auto lambda2 = [&threshold](){return threshold;}; // capture threshold by reference
    auto lambda3 = [=](){return threshold;}; // capture all by value
    auto lambda4 = [&](){return threshold;}; // capture all by reference
    auto lambda5 = [limit = threshold + 5.0f](){return limit;}; // capture with initialization
    auto lambda6 = [=]() mutable {return threshold++;}; // using mutable

    // filtering using lamdas
    auto filterLambda = [](const SignalBuffer& other_){ return (other_.getStrength()<-90 || other_.getStatus() == Status::LOST);};
    SignalBuffer* arr[6]{&sb1, &sb2, &sb3, &sb4, &sb5, &sb6}; 

    // storing and printing 
    int idx = 0;
    SignalBuffer arr2[6];
    for (auto i: arr)
    {
        if(filterLambda(*i)){
            arr2[idx++] = std::move(*i);
        }
    }
    std::cout<<"\n Print ting the filtered obj details: "<<std::endl;
    for(auto i=0;i<idx;i++){
        std::cout<<std::endl;
        arr2[i].print();

    }
    
    return 0;
}