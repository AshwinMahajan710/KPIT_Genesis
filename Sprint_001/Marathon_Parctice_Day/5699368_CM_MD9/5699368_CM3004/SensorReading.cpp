#include"SensorReading.h"
#include"SensorType.h"
#include<stdexcept>
#include<cstring>

float SensorReading::MIN_CONFIDENCE = 0.0f;
float SensorReading::MAX_CONFIDENCE = 1.0f;
float SensorReading::MAX_PAYLOAD = 64;
float SensorReading::MAX_LABEL_LEN = 64;

// constructor --> default
SensorReading::SensorReading() : m_readingId(-1), m_type(SensorType::LIDAR), m_confidence(0.0f), m_payloadSize(0), m_payload(nullptr), m_label(nullptr) {}

// constructor --> parameterized
SensorReading::SensorReading(int id_, SensorType type_, float confidence_, const uint8_t* payload_, std::size_t size_, const char* label){

    // validate id
    if(id_ < 0) {throw std::invalid_argument("Id should be +ve or 0");}
    else {m_readingId = id_;}

    m_type = type_;
    m_confidence = (confidence_ < MIN_CONFIDENCE) ? MIN_CONFIDENCE : (confidence_ > MAX_CONFIDENCE ? MAX_CONFIDENCE : confidence_);
    
    //validating payload
    if(payload_ == nullptr || size_ <= 0){
        m_payload = nullptr;
        m_payloadSize = 0; 
    }
    else{
        m_payloadSize = (size_ > MAX_PAYLOAD) ? MAX_PAYLOAD : size_;
        m_payload = new uint8_t[m_payloadSize];
        for(int i=0;i<m_payloadSize;i++){
            m_payload[i] = payload_[i];
        }
    }

    // set lable
    if(label == nullptr) {m_label = nullptr;}
    else{
        int labelSize = (strlen(label) > MAX_LABEL_LEN - 1) ? MAX_LABEL_LEN-1 : strlen(label);
        m_label = new char[labelSize + 1];
        strncpy(m_label, label, labelSize);
        m_label[labelSize] = '\0';
    }
}

SensorReading::SensorReading(const SensorReading& other){
    m_readingId = other.m_readingId;
    m_type = other.m_type;
    m_confidence = other.m_confidence;
    m_payloadSize = other.m_payloadSize;
    m_payload = new uint8_t[m_payloadSize];
    for(int i=0;i<m_payloadSize;i++){
        m_payload[i] = other.m_payload[i];
    }
    if (other.m_label != nullptr) {
        int len = strlen(other.m_label);
        m_label = new char[len + 1];
        strncpy(m_label, other.m_label, len + 1); 
    } else {
        m_label = nullptr;
    }
}

// assignment operator
SensorReading& SensorReading::operator=(const SensorReading& other){
    if(this != &other){
        delete[] m_label;
        delete[] m_payload;
        m_readingId = other.m_readingId;
        m_type = other.m_type;
        m_confidence = other.m_confidence;
        m_payloadSize = other.m_payloadSize;
        m_payload = new uint8_t[m_payloadSize];
        for(int i=0;i<m_payloadSize;i++){
            m_payload[i] = other.m_payload[i];
        }
        if (other.m_label != nullptr) {
            int len = strlen(other.m_label);
            m_label = new char[len + 1];
            strncpy(m_label, other.m_label, len + 1); 
        } else {
            m_label = nullptr;
        }
    }
    return *(this);
}

// destructor
SensorReading::~SensorReading(){
    delete[] m_label;
    delete[] m_payload;
}

// getters
int SensorReading::getReadingId() const {
    return m_readingId;
}

SensorType SensorReading::getType() const {
    return m_type;
}

float SensorReading::getConfidence() const {
    return m_confidence;
}

const uint8_t* SensorReading::getPayload() const {
    return m_payload;
}

std::size_t SensorReading::getPayloadSize() const {
    return m_payloadSize;
}

const char* SensorReading::getLabel() const {
    return m_label;
}


// Setters
void SensorReading::setReadingId(int id_){
    // validate id
    if(id_ < 0) {throw std::invalid_argument("Id should be +ve or 0");}
    else {m_readingId = id_;}
}

void SensorReading::setConfidence(float confidence_){
    m_confidence = (confidence_ < MIN_CONFIDENCE) ? MIN_CONFIDENCE : (confidence_ > MAX_CONFIDENCE ? MAX_CONFIDENCE : confidence_);
}
void SensorReading::setPayload(const uint8_t* payload_, std::size_t size_){
    if(payload_ == nullptr || size_ <= 0){
        m_payload = nullptr;
        m_payloadSize = 0; 
    }
    else{
        m_payloadSize = (size_ > MAX_PAYLOAD) ? MAX_PAYLOAD : size_;
        m_payload = new uint8_t[m_payloadSize];
        for(int i=0;i<m_payloadSize;i++){
            m_payload[i] = payload_[i];
        }
    }
}

void SensorReading::setLabel(const char* label){
    if(label == nullptr) {m_label = nullptr;}
    else{
        int labelSize = (strlen(label) > MAX_LABEL_LEN - 1) ? MAX_LABEL_LEN-1 : strlen(label);
        m_label = new char[labelSize + 1];
        strncpy(m_label, label, labelSize);
        m_label[labelSize] = '\0';
    }
}

std::ostream& operator<<(std::ostream& out, const SensorReading& other){
    out<<"\n"<<other.m_readingId<<" "<<other.getSensorTypeString()<<" "<<other.m_confidence<<" "<<other.m_label<<" "<<other.m_payloadSize<<std::endl;
    return out;
}

SensorReading SensorReading:: operator+ (const SensorReading& other) const{
    int newId = (m_readingId >= 0 || other.m_readingId>=0) ? std::min(m_readingId, other.m_readingId) : -1;
    SensorType newType = (m_type > other.m_type) ? m_type : other.m_type;
    int newConfidence = (m_confidence + other.m_confidence) / 2.0;
    
    // label
    int fullLength = strlen(m_label) + strlen(other.m_label) + 2;
    char* newLable = new char[fullLength];
    strcpy(newLable, m_label);
    strcat(newLable,"-");
    strcat(newLable,other.m_label);
    int newLabelLength = (strlen(newLable) > MAX_LABEL_LEN - 1) ? (MAX_LABEL_LEN-1) : fullLength;
    char* newLableName = new char[newLabelLength + 1];
    strncpy(newLableName, newLable, newLabelLength);
    newLableName[newLabelLength] = '\0' ;
    delete [] newLable;

    // payload
    std::size_t newPayloadSize = std::max(m_payloadSize, other.m_payloadSize);
    uint8_t* newPayload = new uint8_t[newPayloadSize];
    for(int i=0;i<newPayloadSize;i++){
        if(i<m_payloadSize && i<other.m_payloadSize){
            newPayload[i] = static_cast<uint8_t>((m_payload[i] + other.m_payload[i])/2); 
        }
        else if(i>=m_payloadSize){
            newPayload[i] = other.m_payload[i] ;
        }
        else if(i>=other.m_payloadSize){
            newPayload[i] = m_payload[i] ;
        }
    }

    return SensorReading(newId, newType, newConfidence,newPayload, newPayloadSize, newLableName);
}

// helper --> getting enum value as str
std::string SensorReading:: getSensorTypeString() const{
    switch (m_type)
    {
        case SensorType::CAMERA:{
            return "Camera";
            break;
        }
        case SensorType::LIDAR:{
            return "Lidar";
            break;
        }
        case SensorType::RADAR:{
            return "Radar";
            break;
        }    
    }
}