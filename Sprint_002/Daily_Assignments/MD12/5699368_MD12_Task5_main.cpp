#include"5699368_MD12_Task5_Student.h"
#include<string>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include"5699368_MD12_Task5_Global.h"
#include<functional>

int main(){

    // creating vector and wrapping it as a reference wrappper
    std::vector<std::unique_ptr<Student>> students = createStudents();
    std::reference_wrapper<std::vector<std::unique_ptr<Student>>> ref(students);

    // now displaying using the ref
    for(const auto &student: ref.get()){
        student->display();
    }

    // writing the funtion to count subjects with marks more than 50
    int count = 0;
    std::function<void()> countStuds = [&ref](){
        int count = 0;
        for(const auto &stud: ref.get()){
            if(stud->getGrade() > 50.0){
                count++;
            }
        }
        std::cout<<"\nCount of students: "<<count<<std::endl;
    };

    countStuds();

    //  function to check whihc function to apply
    std::function<void(Student&)> func;
    recalculateGrades(students,func);
    findAverageGrade(students);

    // now displaying using the ref
    for(const auto &student: students){
        student->display();
    }   

    return 0;
}