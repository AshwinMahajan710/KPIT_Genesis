#include<string>
#include"5699368_MD4_Task4_Level.h"
#include"5699368_MD4_Task4_TelemetryPacket.h"
#include <iostream>
#include"5699368_MD4_Task4_global.h"

int main(){


    // creating obj
    TelemetryPacket p1(201,"TEMP",1620000000ULL); // member list initialization
    p1.setReadings(75.0,101.3);
    p1.setLevel(Level::OK);

    TelemetryPacket p2{202,"PRESS",1620000100ULL}; // Uniform initialization
    p2.setReadings(95.2,100.8);
    p2.setLevel(Level::WARN);
    
    TelemetryPacket p3 = TelemetryPacket(); // value initialization
    p3.setReadings(60.5,110.0);
    p3.setLevel(Level::CRITICAL);
    
    TelemetryPacket p4{203,"LIDAR",1620000300ULL}; // Uniform initialization
    p3.setReadings(120.3,95.0);
    p3.setLevel(Level::OK);
    
    TelemetryPacket p5{204,"LIDAR",1620000400ULL}; // Uniform initialization
    p4.setReadings(20.0,101.0);
    p4.setLevel(Level::CRITICAL);

    TelemetryPacket packet[] = {
        std::move(p1),
        std::move(p2),
        std::move(p3),
        std::move(p4),
        std::move(p5)
    };

    // attempting log by value
    // logByValue(p1); // gives error cannot be referenced

    // loogging by ref and Rref
    logByRef(packet[0]);
    std::cout<<std::endl;
    logByRRef(std::move(packet[0]));

    // after moving trying to print the p1 values
    std::cout<<"\nAfter moving p1 values are : "<<std::endl;
    p1.print() ;

    // printing values in arr
    std::cout<<"\nPrinting details of all objs in arr: "<<std::endl;
    for(auto &i : packet){
        std::cout<<std::endl;
        i.print();
    }

    // initialize threshold and chck it with lambda
    int threshold = 10;
    auto lambda1 = [threshold](){std::cout<<"\nThreshold is: "<<threshold;};
    threshold = 20;
    lambda1(); // output: 10 as passed by value

    // initialize threshold and chck it with lambda
    threshold = 10;
    auto lambda2 = [&threshold](){std::cout<<"\nThreshold is: "<<threshold;};
    threshold = 20;
    lambda2(); // output: 20 as passed by REFERENCE
    
    // init-capture is different from capturing threshold directly
    threshold = 10;
    auto lambda3 = [limit = 1.1 * threshold] () {std::cout<<"\nLimit is: "<<limit;}; // cannot access threshold here
    lambda3();
    
    // MUTABLE LAMBDA
    threshold = 10;
    auto lambda4 = [threshold]() mutable {std::cout<<"\nThreshold is: "<<++threshold;};
    lambda4(); 
    std::cout<<"\nold threshold was: "<<threshold<<std::endl;

    return 0;
}