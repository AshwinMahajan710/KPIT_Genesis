
// Exam class .h file

#ifndef EXAM_H
#define EXAM_H

#include"Date.h"

// preferrably create new class for enum.. but problem statement wnats us to create it in here
enum ExamType {ONLINE,OFFLINE} ;

// class ExamClass --> contains entire details of exam
class Exam{
    private:
        int m_examCode;
        ExamType m_examType;
        Date m_examDate;
    
    public:
        Exam(int examCodes_,ExamType examType_, int d_, int m_, int y_); // constructor
        void display() const; // to print exam details
};

#endif // EXAM_H
