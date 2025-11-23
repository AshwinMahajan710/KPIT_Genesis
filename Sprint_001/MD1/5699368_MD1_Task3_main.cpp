#include<iostream>
#include<ctime>
#include<string>
#include"5699368_MD1_Task3_DTC.h"
#include"5699368_MD1_Task3_SeverityLevel.h"

int main(){

    //  1. creating default object
    DTC dtcDefault;

    //  2. Instantiating dtc object --> parametrized
    DTC dtcParam("P301","Cylinder misfire detected", true, 3, 1625247600, SeverityLevel::INFO,true, false, true, "Engine", "ECU_01");

    //  3. using setters
    time_t curr_time = std::time(nullptr);
    dtcDefault.setCode("P0420");
    dtcDefault.setDescription("Catalyst System Efficiency Below Threshold");
    dtcDefault.setSystem("Exhaust");
    dtcDefault.setOrigin("ECU_02");
    dtcDefault.setOccurenceCount(2);
    dtcDefault.setLastOccurenceTime(curr_time - 4000); // ≈ 66 minutes ago
    dtcDefault.setSeverityLevel(SeverityLevel::WARN);
    dtcDefault.setMilOn(false);

    //  4. now printing riskscore and recommended action
    std::cout<<"\nRisk score for dtcDefault: "<<dtcDefault.computeRiskScore()<<"\nRecommended action: "<<dtcDefault.recommendAction()<<std::endl;
    std::cout<<"\nRisk score for dtcParam: "<<dtcParam.computeRiskScore()<<"\nRecommended action: "<<dtcParam.recommendAction()<<std::endl;

    //  5. Creating duplicate DTC and trying merge
    DTC dtcParamDup;
    dtcParamDup.setCode("P301");
    dtcParamDup.setDescription("");
    dtcParamDup.setActive(false);
    dtcParamDup.setOccurenceCount(10);
    dtcParamDup.setLastOccurenceTime(curr_time - 100); // ≈ 1.7 minutes ago
    dtcParamDup.setSeverityLevel(SeverityLevel::WARN);
    dtcParamDup.setConfirmed(false);
    dtcParamDup.setPending(true);
    dtcParamDup.setSystem("Exhaust");
    dtcParamDup.setMilOn(false);
    dtcParamDup.setSystem("Engine");
    dtcParamDup.setOrigin("ECU_02");

    // merging with dtcParam
    if(dtcParam.mergeIfSameCode(dtcParamDup)) {std::cout<<"\nMerged sucessfully...";}
    else{std::cout<<"\nNot merged..";}

    // 6. Assessing future edge case and computing action and score
    DTC dtcEdge;
    dtcParamDup.setCode("P303");
    dtcParamDup.setDescription("");
    dtcParamDup.setActive(false);
    dtcParamDup.setOccurenceCount(-5);
    dtcParamDup.setLastOccurenceTime(curr_time + 100000); // ≈ 1.7 minutes ago
    dtcParamDup.setSeverityLevel(SeverityLevel::INFO);
    dtcParamDup.setConfirmed(false);
    dtcParamDup.setPending(true);
    dtcParamDup.setSystem("Exhaust");
    dtcParamDup.setMilOn(false);
    dtcParamDup.setSystem("Engine");
    dtcParamDup.setOrigin("ECU_02");

    // checking score and action for dtcEdge
    std::cout<<"\nRisk score for dtcEdge: "<<dtcEdge.computeRiskScore()<<"\nRecommended action: "<<dtcEdge.recommendAction()<<std::endl;

    //  7. Checking overflow condition
    DTC dtcEdge1 ;
    DTC dtcEdge2 ;
    dtcEdge1.setCode("P403");
    dtcEdge2.setCode("P403");
    dtcEdge1.setSystem("Engine");
    dtcEdge2.setSystem("Engine");
    dtcEdge1.setOccurenceCount(INT32_MAX - 2);
    dtcEdge2.setOccurenceCount(INT32_MAX - 1);
    
    // merge and validate
    dtcEdge1.mergeIfSameCode(dtcEdge2);
    std::cout<<"\nNew occurence count: "<<dtcEdge1.getOccurenceCount()<<std::endl;

    // now printing all objects for verification
    std::cout<<"\nObject dtcDefault: "<<std::endl;
    dtcDefault.printDTCInfo();
    std::cout<<"\nObject dtcParam: "<<std::endl;
    dtcParam.printDTCInfo();
    std::cout<<"\nObject dtcParamDup: "<<std::endl;
    dtcParamDup.printDTCInfo();
    std::cout<<"\nObject dtcEdge: "<<std::endl;
    dtcEdge.printDTCInfo();
    std::cout<<"\nObject dtcEdge1: "<<std::endl;
    dtcEdge1.printDTCInfo();
    std::cout<<"\nObject dtcEdge2: "<<std::endl;
    dtcEdge2.printDTCInfo();

    return 0;
}