#include<iostream>
#include<string>
#include"Exam.h"
#include"Date.h"

// constructor --> parameterized
Exam::Exam(int examCodes_,ExamType examType_, int d_, int m_, int y_) : m_examCode(examCodes_), m_examType(examType_){
    m_examDate.setYear(y_);
    m_examDate.setMonth(m_);
    m_examDate.setDay(d_);
}

// function to display examDetails
void Exam::display() const{
    std::cout<<"ExamCodes: "<<m_examCode<<std::endl;
    std::cout<<"Exam Type: "<<m_examType<<std::endl;
    m_examDate.printDay();
}