#ifndef ENGINEDTC_H
#define ENGINEDTC_H

#include<string>
#include"5699368_MD6_Task2_DTC.h"

// class engine DTC
class EngineDTC{
    private:
        int m_rpmAtFault;
        float m_coolantTemp;

    public:
        EngineDTC(int rpmAtFault_, float coolantTemp_);
        void printEngineDTCInfo() const;
        bool isOverheated() const;

};

#endif // ENGINEDTC_H
