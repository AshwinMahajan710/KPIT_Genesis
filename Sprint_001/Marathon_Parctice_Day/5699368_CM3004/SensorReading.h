#ifndef SENSORREADING_H
#define SENSORREADING_H

#include"SensorType.h"
#include<cstdint>
#include<iostream>

class SensorReading{
    private:
        int m_readingId;
        SensorType m_type;
        float m_confidence; // 0.0f to 1.0f
        uint8_t* m_payload;
        std::size_t m_payloadSize;
        char* m_label;
        static float MIN_CONFIDENCE; 
        static float MAX_CONFIDENCE; 
        static float MAX_PAYLOAD; 
        static float MAX_LABEL_LEN;
    
    public:
        // constructors
        SensorReading();
        SensorReading(int id_, SensorType type_, float confidence_, const uint8_t* payload_, std::size_t size_, const char* label);
        SensorReading(const SensorReading& other);

        // assignment operator
        SensorReading& operator=(const SensorReading& other);

        // destructor
        ~SensorReading();

        // getters
        int getReadingId() const;
        SensorType getType() const;
        float getConfidence() const;
        const uint8_t* getPayload() const;
        std::size_t getPayloadSize() const;
        const char* getLabel() const;

        // Setters
        void setReadingId(int id_);
        void setConfidence(float c_);
        void setPayload(const uint8_t* data_, std::size_t size_);
        void setLabel(const char* s);

        // overloading operators
        friend std::ostream& operator<<(std::ostream& out, const SensorReading& other);
        SensorReading operator+ (const SensorReading& other) const;

        // helper --> getting enum value as str
        std::string getSensorTypeString() const;


};

#endif // SENSORREADING_H
