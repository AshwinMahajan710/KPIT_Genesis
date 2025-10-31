
#include"Global.h"
#include"CANNode.h"

// function to count frameTypes
std::size_t countFramesByType(const CANNode* arr_[], int count_, FrameType ft_){
    std::size_t frameCount = 0;
    for(int i=0;i<count_;i++){
        if(arr_[i] != nullptr && arr_[i]->getFrameType()==ft_){
            frameCount++;
        }
    }
    return frameCount;
}


void replacePayloadForNode(CANNode* arr_[], int count_, int targetNodeId_, const uint8_t* newPayload_, std::size_t newSize) {
    for (int i = 0; i < count_; i++) {
        if (arr_[i] != nullptr && arr_[i]->getNodeId() == targetNodeId_) {
            if (newPayload_ == nullptr || newSize == 0) {
                arr_[i]->setPayload(nullptr, 0); 
            }
            arr_[i]->setPayload(newPayload_, newSize);
        }
    }
}
