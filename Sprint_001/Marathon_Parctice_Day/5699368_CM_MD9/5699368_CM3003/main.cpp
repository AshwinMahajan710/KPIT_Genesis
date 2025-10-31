#include"Global.h"
#include"CANNode.h"
#include<iostream>
#include<string>
#include<stdexcept>

int CANNode::s_liveCount = 0;

int main(){

    // TC1
    CANNode* arr[10] = {
    new CANNode(0, FrameType::STANDARD, 0x100, nullptr, 0, "ECU_A"),
    new CANNode(1, FrameType::EXTENDED, 0x1FFFF, nullptr, 0, "ECU_B"),
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    arr[0]->setPayload("0A1B2C");
    arr[1]->setPayload("FF");
    int n = 2;
    FrameType frameTypeToCount = FrameType::STANDARD;
    uint8_t* tempPayload = new uint8_t[2]{0xDE, 0xAD};
    replacePayloadForNode(arr, 10, 0, tempPayload, 2);
    delete[] tempPayload; 
    std::cout<<"\nCounting frames by Standard type: "<<countFramesByType(const_cast<const CANNode** >( arr),10,frameTypeToCount)<<std::endl;
    std::size_t payload_size = arr[0]->getPayloadSize();
    const uint8_t* ptr = arr[0]->getPayload();
    for(size_t i=0;i<payload_size;i++){
        std::cout<<std::hex << std::uppercase<<static_cast<int> (ptr[i])<<std::dec<<std::endl;
    } 
    std::cout<<"Current live objects: "<<arr[0]->getLiveCount()<<std::endl;
    for(int i=0;i<n;i++){
        delete arr[i];
    }

    // TC --> 2
    CANNode* arr2[10] = {
    new CANNode(2, FrameType::REMOTE, 0x200, nullptr, 0, "Remote_1"),
    new CANNode(3, FrameType::REMOTE, 0x201, new uint8_t[1]{0xAA}, 1, "Remote_2"),
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};    
    int n2 = 2;
    FrameType frameTypeToCount2 = FrameType::REMOTE;
    replacePayloadForNode(arr2, 10, 2, nullptr, 0);
    std::cout << "\nCounting frames by Standard type: "
            << countFramesByType(const_cast<const CANNode**>(arr2), 10, frameTypeToCount2)
            << std::endl;
    std::size_t payload_size2 = arr2[0]->getPayloadSize();
    const uint8_t* ptr2 = arr2[0]->getPayload();
    if(ptr2 != nullptr){
        for (size_t i = 0; i < payload_size2; i++) {
            std::cout << std::hex << std::uppercase << static_cast<int>(ptr2[i]) << std::dec << std::endl;
        }
    }
    std::cout << "Current live objects: " << arr2[0]->getLiveCount() << std::endl;
        for(int i=0;i<n;i++){
        delete arr2[i];
    }
    
    // TC3 ---> 
    CANNode* arr3[10] = {nullptr,nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    int n3 = 0;
    FrameType frameTypeToCount3 = FrameType::STANDARD;
    replacePayloadForNode(arr3, 10, 2, nullptr, 0);
    std::cout << "\nCounting frames by Standard type: "
            << countFramesByType(const_cast<const CANNode**>(arr3), 10, frameTypeToCount3)
            << std::endl;
    std::cout << "Current live objects: " << arr3[0]->getLiveCount() << std::endl;
    for (int i = 0; i < n3; i++) {
        delete arr3[i];
    }

    // TC4 --->
    CANNode* arr4[10] = {
    new CANNode(5, FrameType::STANDARD, 0x123, new uint8_t[1]{0x5B}, 1, "Remote_Two_Idea_For_Large_string_Upto_40_Characters"),
    new CANNode(6, FrameType::STANDARD, 0x204, new uint8_t[1]{0x00}, 1, "N2"),
    new CANNode(7, FrameType::EXTENDED, 0x1ABCDE, new uint8_t[1]{0xFF}, 1, "N3"),
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    int n4 = 3;
    FrameType frameTypeToCount4 = FrameType::STANDARD;
    replacePayloadForNode(arr4, 10, 5, new uint8_t[9]{0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99}, 9);
    std::cout << "\nCounting frames by Standard type: "
            << countFramesByType(const_cast<const CANNode**>(arr4), 10, frameTypeToCount4)
            << std::endl;
    std::size_t payload_size4 = arr4[0]->getPayloadSize();
    const uint8_t* ptr4 = arr4[0]->getPayload();
    if (ptr4 != nullptr) {
        for (size_t i = 0; i < payload_size4; i++) {
            std::cout << std::hex << std::uppercase << static_cast<int>(ptr4[i]) << std::dec << std::endl;
        }
    }
    std::cout << "Current live objects: " << arr4[0]->getLiveCount() << std::endl;
    for (int i = 0; i < n4; i++) {
        delete arr4[i];
    }

    // TC 5-->
    CANNode* arr5[10] = {
    new CANNode(0, FrameType::EXTENDED, 0xABC,nullptr, 0,"A"),
    new CANNode(1, FrameType::STANDARD, 0x100,new uint8_t[1]{0xF1}, 1, "B"),
    new CANNode(2, FrameType::STANDARD, 0x101,new uint8_t[1]{0xAB}, 1, "C"),
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    int n5 = 3;
    FrameType frameTypeToCount5 = FrameType::STANDARD;

    replacePayloadForNode(arr5, 10, 2, new uint8_t[1]{0x00}, 1);

    std::cout << "\nCounting frames by Standard type: "
            << countFramesByType(const_cast<const CANNode**>(arr5), 10, frameTypeToCount5)
            << std::endl;

    std::size_t payload_size5 = arr5[1]->getPayloadSize();
    const uint8_t* ptr5 = arr5[2]->getPayload();
    if (ptr5 != nullptr) {
        for (size_t i = 0; i < payload_size5; i++) {
            std::cout << std::hex << std::uppercase << static_cast<int>(ptr5[i]) << std::dec << std::endl;
        }
    }
    std::cout << "Current live objects: " << arr5[0]->getLiveCount() << std::endl;
    for (int i = 0; i < n5; i++) {
        delete arr5[i];
    }

    return 0;
}