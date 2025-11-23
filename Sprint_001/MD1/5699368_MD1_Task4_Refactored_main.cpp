#include<iostream>
#include<ctime>
#include<string>
#include"5699368_MD1_Task4_DTC.h"
#include"5699368_MD1_Task4_SeverityLevel.h"

// function which will demonstrate memory leak
void leakDemo(){
    
    // creating two objects dynamically
    DTC *heapDTCObj1 = new DTC;
    DTC *heapDTCObj2 = new DTC;

    // delete dynamically object 1
    delete heapDTCObj1;
    heapDTCObj1 =  nullptr;

    // ALERT::: as we are only deleting obj1 , obj2 remains in memory. no that memory is occupied by value which is not going to need in future. also the memory occupied is wasted. due to this reason we should always free the dynamically allocated memory
}


// function which will demonstrate memory leak fix
void leakFix(){
    
    // creating two objects dynamically
    DTC *heapDTCObj1 = new DTC;
    DTC *heapDTCObj2 = new DTC;

    // delete both dynamically allocated objects
    // delete obj1
    delete heapDTCObj1; 
    heapDTCObj1 =  nullptr;
    // delete obj2
    delete heapDTCObj2;
    heapDTCObj2 =  nullptr;

    // ALERT::: now here we are accurately freeing dynamically allocated memory and hence this will not cause any memory leak
}

//
int main(){

    // cretaing current time obj
    time_t curr_time = time(nullptr);
    
    // Dynamically allocating memory using heap
    DTC *heapDTCObj = new DTC;
    heapDTCObj->setCode("P301");
    heapDTCObj->setDescription("");
    heapDTCObj->setActive(false);
    heapDTCObj->setOccurenceCount(10);
    heapDTCObj->setLastOccurenceTime(curr_time - 100); // ≈ 1.7 minutes ago
    heapDTCObj->setSeverityLevel(SeverityLevel::WARN);
    heapDTCObj->setConfirmed(false);
    heapDTCObj->setPending(true);
    heapDTCObj->setSystem("Exhaust");
    heapDTCObj->setMilOn(false);
    heapDTCObj->setSystem("Engine");
    heapDTCObj->setOrigin("ECU_02");

    /// now increment counter and toggleMIL
    heapDTCObj->incrementOccurence();
    heapDTCObj->toggleMIL();

    // now printing info
    std::cout<<"\nHeap allocated object info: "<<std::endl;
    heapDTCObj->printDTCInfo();

    // deletion
    delete heapDTCObj;
    heapDTCObj = nullptr; // after deleting heapDTCObj points to memory location where there is nothing. so, explicitly point it to nullptr

    // Dangling pointer demonstration and safe access task
    
    // creating new object in heap and then delete it. then try to print information
    // DTC *newHeapDTCObj = new DTC;
    // delete newHeapDTCObj;
    // newHeapDTCObj->printDTCInfo(); /// will throw error :- segmentation fault: core dumped

    // Now lets check safer version
    DTC *newHeapDTCObj = new DTC;
    delete newHeapDTCObj;
    newHeapDTCObj = nullptr;
    newHeapDTCObj->printDTCInfo(); /// Now this line will give error at compile time so that we can clear the error at directly compile time
    
    return 0;
}