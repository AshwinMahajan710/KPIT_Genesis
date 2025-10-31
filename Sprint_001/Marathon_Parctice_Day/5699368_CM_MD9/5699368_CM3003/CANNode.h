#ifndef CANNODE_H
#define CANNODE_H
#include<cstdint>

enum FrameType{STANDARD,EXTENDED,REMOTE};

class CANNode{
    private:
        int m_nodeId;
        FrameType m_frameType;
        uint32_t m_canId;
        uint8_t* m_payload;
        std::size_t m_payloadSize;
        char* m_name;
        static int s_liveCount;
        static std::size_t MAX_PAYLOAD;
        static std::size_t MAX_NAME_LEN;
    
    public:
        // constructor
        CANNode();
        CANNode(int nodeId_, FrameType frameType_, uint32_t canId_, const uint8_t* payload_, std::size_t payloadSize_,const char* name);
        CANNode(const CANNode& other);

        // copy assignment operator
        CANNode& operator= (const CANNode& other);

        // destrcutor
        ~CANNode();

        // getters
        int getNodeId()const;
        FrameType getFrameType()const;
        uint32_t getCanId()const;
        const uint8_t* getPayload() const;
        std::size_t getPayloadSize()const;
        const char* getName()const;
        static int getLiveCount();

        // setters
        void setNodeId(int id_);
        void setFrameType(FrameType frameType_);
        void setCanId(uint32_t canId_); 
        void setPayload(const uint8_t* d1ata_, std::size_t size_);
        void setPayload(const char* hexString);
        void setName(const char* newName);


};


#endif // CANNODE_H
