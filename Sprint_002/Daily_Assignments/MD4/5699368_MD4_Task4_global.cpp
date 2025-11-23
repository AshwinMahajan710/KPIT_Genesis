#include <iostream>
#include"5699368_MD4_Task4_global.h"

void logByValue(TelemetryPacket p) {
    std::cout << "\nLog by value.."<<std::endl;
    p.print(); // should FAIL as copy constructor is deleted
}

void logByRef(const TelemetryPacket& p) {
    std::cout << "\nLog by reference: "<<std::endl;
    p.print();
}

void logByRRef(TelemetryPacket&& p) {
    std::cout << "Logged by r value reference: "<<std::endl;
    p.print();
}

void logByPtr(const TelemetryPacket* p) {
    std::cout << "Logged by pointer: "<<std::endl;
    if (p) p->print();
}