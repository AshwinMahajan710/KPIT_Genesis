#ifndef GLOBAL_H
#define GLOBAL_H

#include"CANNode.h"

// function to count frameTypes
std::size_t countFramesByType(const CANNode* arr_[], int count_, FrameType ft_);

// function to replace payload 
void replacePayloadForNode(CANNode* arr_[], int count_, int targetNodeId_, const uint8_t* newPayload_, std::size_t newSize);

#endif // GLOBAL_H
