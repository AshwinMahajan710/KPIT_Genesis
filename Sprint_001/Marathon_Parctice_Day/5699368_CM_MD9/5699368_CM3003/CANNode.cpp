
#include"CANNode.h"
#include<stdexcept>
#include<string>
#include<cstring>

size_t CANNode:: MAX_PAYLOAD = 8;
size_t CANNode:: MAX_NAME_LEN = 32;

// constructor --> deafult
CANNode::CANNode(){
    m_nodeId = -1;
    m_frameType = FrameType::STANDARD;
    m_canId = 0;
    m_payload = nullptr;
    m_payloadSize = 0;
    m_name = nullptr;
    s_liveCount++;
}

// constructor --> parameterized
CANNode::CANNode(int nodeId_, FrameType frameType_, uint32_t canId_, const uint8_t* payload_, std::size_t payloadSize_,const char* name_){
    // validate id  
    if(nodeId_ < 0) {throw std::invalid_argument("Id can never be -ve");}
    else {m_nodeId = nodeId_;}

    m_frameType = frameType_;
    m_canId = canId_;

    // validate payload and store it
    if(payload_==nullptr || payloadSize_ == 0){
        m_payload = nullptr;
        m_payloadSize = 0; 
    }
    else{
        m_payloadSize = (payloadSize_ > MAX_PAYLOAD) ? MAX_PAYLOAD : payloadSize_;
        m_payload = new uint8_t[m_payloadSize];
        for(int i=0;i<m_payloadSize;i++){
            m_payload[i] = payload_[i];
        }
    }

    if(name_== nullptr) {m_name = nullptr;}
    else{
        int newNameLength = (strlen(name_) > MAX_NAME_LEN-1) ? MAX_NAME_LEN-1 : strlen(name_);
        m_name = new char[newNameLength + 1];
        strncpy(m_name, name_, newNameLength);
        m_name[newNameLength] = '\0';
    }

    s_liveCount++;
}

// constructor --> copy
CANNode::CANNode(const CANNode& other){
    m_nodeId = other.m_nodeId;
    m_frameType = other.m_frameType;
    m_canId = other.m_canId;
    
    if(other.m_payload==nullptr || other.m_payloadSize == 0){
        m_payload = nullptr;
        m_payloadSize = 0; 
    }
    else{
        m_payloadSize = other.m_payloadSize;
        m_payload = new uint8_t[m_payloadSize];
        for(int i=0;i<m_payloadSize;i++){
            m_payload[i] = other.m_payload[i];
        }
    }
    if(other.m_name == nullptr) {m_name = nullptr;}
    else{
        int nameLength = strlen(other.m_name);
        m_name = new char[nameLength + 1];
        strncpy(m_name, other.m_name, nameLength + 1);
    }
}

// copy assignment operator
CANNode& CANNode::operator= (const CANNode& other){
    if(this != &other){
        delete[] m_name;
        delete[] m_payload;
        m_nodeId = other.m_nodeId;
        m_frameType = other.m_frameType;
        m_canId = other.m_canId;
        if(other.m_payload==nullptr || other.m_payloadSize == 0){
            m_payload = nullptr;
            m_payloadSize = 0; 
        }
        else{
            m_payloadSize = other.m_payloadSize;
            m_payload = new uint8_t[m_payloadSize];
            for(int i=0;i<m_payloadSize;i++){
                m_payload[i] = other.m_payload[i];
            }
        }
        if(other.m_name == nullptr) {m_name = nullptr;}
        else{
            int nameLength = strlen(other.m_name);
            m_name = new char[nameLength + 1];
            strncpy(m_name, other.m_name, nameLength + 1);
        }
    }
    return *this;
}

// destrcutor
CANNode::~CANNode(){
    delete[] m_payload;
    delete[] m_name;
    s_liveCount--;
}

// getters
int CANNode::getNodeId()const{
    return m_nodeId;
}
FrameType CANNode::getFrameType()const{
    return m_frameType;
}
uint32_t CANNode::getCanId()const{
    return m_canId;
}
const uint8_t* CANNode::getPayload() const{
    return m_payload;
}
std::size_t CANNode::getPayloadSize()const{
    return m_payloadSize;
}
const char* CANNode::getName()const{
    return m_name;
}
int CANNode::getLiveCount(){
    return s_liveCount;
}

// setters
void CANNode::setNodeId(int nodeId_){
    // validate id  
    if(nodeId_ < 0) {throw std::invalid_argument("Id can never be -ve");}
    else {m_nodeId = nodeId_;}
}
void CANNode::setFrameType(FrameType frameType_){
    m_frameType = frameType_;
}
void CANNode::setCanId(uint32_t canId_){
    m_canId = canId_;
}

void CANNode::setPayload(const uint8_t* data_, size_t size_) {
    if (m_payload != nullptr) {
        delete[] m_payload;
        m_payload = nullptr;
    }

    if (data_ == nullptr || size_ == 0) {
        m_payloadSize = 0;
        return;
    }
    m_payloadSize = (size_ > MAX_PAYLOAD) ? MAX_PAYLOAD : size_;
    m_payload = new uint8_t[m_payloadSize];
    for (size_t i = 0; i < m_payloadSize; ++i) {
        m_payload[i] = data_[i];
    }
}


void CANNode::setPayload(const char* hexString_) {
    if (!hexString_) return;  

    delete[] m_payload;  

    size_t len = strlen(hexString_);
    m_payloadSize = (len > MAX_NAME_LEN) ? MAX_NAME_LEN : len;

    m_payload = new uint8_t[m_payloadSize];

    for (size_t i = 0; i < m_payloadSize; ++i) {
        char ch = hexString_[i];
        if (ch >= '0' && ch <= '9')
            m_payload[i] = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            m_payload[i] = 10 + (ch - 'A');
        else if (ch >= 'a' && ch <= 'f')
            m_payload[i] = 10 + (ch - 'a');
        else
            m_payload[i] = 0; 
    }
}


void CANNode::setName(const char* newName){
    delete[] m_name;
    if(newName == nullptr) {m_name = nullptr;}
    else{
        int nameLength = strlen(newName);
        m_name = new char[nameLength + 1];
        strncpy(m_name, newName, nameLength + 1);
    }
}


