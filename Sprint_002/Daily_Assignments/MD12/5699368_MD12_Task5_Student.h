#ifndef INC_5699368_MD12_TASK5_STUDENT_H
#define INC_5699368_MD12_TASK5_STUDENT_H

#include<string>

class Student{
    private:
        int m_id{};
        std::string m_name{};
        double m_grade{}; //range 0-100.0
    public:
        Student() = default;
        Student(int id_, const std::string& name_, double greade_);

        // getters
        int getId () const;
        std::string getName () const;
        double getGrade () const;
        
        // Setters
        void setId (int id_);
        void setName (const std::string& name_) ;
        void setGrade (double grade_) ;
        
        // display function
        void display() const;
};

#endif // INC_5699368_MD12_TASK5_STUDENT_H
