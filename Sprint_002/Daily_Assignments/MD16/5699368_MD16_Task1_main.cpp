#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include"5699368_MD16_Task1_SensorFaultTracker.h"
#include<iostream>
#include<stdexcept>
#include"5699368_MD16_Task1_Global.h"

int main(){

    // creating sensorFaultTracker obj
    SensorFaultTracker tracker;

    // reporting faults
    tracker.reportfault("S1",101);
    tracker.reportfault("S1",105);
    tracker.reportfault("S2",99);
    tracker.reportfault("S3",120);

    // priniting fault summary
    printFaultSummary(tracker);

    // printing next critical fault
    std::pair<int , std::string> criticalFault = tracker.getNextCriticalFault();
    std::cout<<"Next critical fault is: ( SensorId --> "<<criticalFault.second<<"  Value: "<<criticalFault.first<<" )"<<std::endl;

    // checking S3 is critical by checking threshold of 110
    if(isSensorCritical(tracker, "S3", 110)){std::cout<<"It is critical";}
    else{std::cout<<"It is not critical";}

    // getting fault counts of all
    int faultCounts = 0;
    std::unordered_map<std::string, std::vector<int>> faultMap = tracker.getFaultMap();
    for(auto &sensor: faultMap){
        for(auto &fault: sensor.second){
            faultCounts++;
        }
        std::cout<<std::endl;
    }
    std::cout<<"Total Faults: "<<faultCounts<<std::endl;

    return 0;
}   