// #include <iostream>
// #include<string>

// class Demo{
//     private:
//         int a;
//         double b;
//         std::string name;
//     public:
//         Demo() = default; // for default constructor // special thing (default values becomes more good --> like int(0), double(0))
//         Demo(std::string name_) : Demo(0,0.0,name_){} // this concept of calling parameterized constructor via default or copy constructor called as constructor delegation
//         Demo(int a_, double b_, const std::string& name_){ // parameterized construtor
//             a = a_;
//             b = b_;
//             name = name_;
//         }

//         Demo(const Demo& other) = delete; // avoid creating copy 
//         ~Demo() = default; // for default destructor in case terminal do not support inplicit destruction of obj

//         virtual void printData() const final{
//             std::cout<<"\nValue a: "<<a<<std::endl;
//             std::cout<<"\nValue b: "<<b<<std::endl;
//             std::cout<<"\nValue name: "<<name<<std::endl;
//         }
// };

// class Derived: public Demo{
//     // void printData() const override {
//     //     std::cout<<"In derived class ...."<<std::endl;
//     // } // will give error as in base class declared as final
// };

// int main(){

//     Demo d1; // now valid
//     d1.printData();

//     Demo d2("Ashwin");
//     return 0;
// }

#include <iostream>


class DemoClass{
    private:
        int number;
        double value;
        std::string data;
    public:
        // DemoClass():number(0), value(0.0), data(""){}
        DemoClass():DemoClass(0,0.0,""){};  // constructor Delegation

        DemoClass(std::string str):DemoClass(0, 0.0, str){}

        DemoClass(int num, double val, std::string dt):number(num), value(val), data(dt){}
        
        virtual void printData() const {
            std::cout << "Number: " << number << std::endl;
            std::cout << "Value: " << value << std::endl;
            std::cout << "Data: " << data << std::endl;
        }

        void setData(int num, double val, std::string dt) = delete;

        //DemoClass(const DemoClass& other) : number(other.number), value(other.value), data(other.data) {}
        DemoClass(const DemoClass& other) = delete;
        DemoClass& operator=(const DemoClass& other) = delete;
        ~DemoClass() = default;

        void *operator new(size_t) = delete;
        void operator delete(void*) = delete;
};

class DerivedClass:public DemoClass{
    public:
        void printData() const override final{
            std::cout << "in derived class" << std::endl;
        }

};


class DerivedClass2:public DerivedClass{
    public:
        // void printData() const {
        //     std::cout << "in derived class" << std::endl;
        // }

};


using DemoClassPtr = DemoClass*;

using myString = std::string;

// using the enum classes --> and values  can be accessed using the Colors::RED
// helps to remove conflicts creted by using enum objects only
// like enum Color{} and enum trafficLights{} if have same elements then creates ambiguity. use above method to resolve the abiguity
enum class Colors{
    RED,
    Blue
};

int main(){
    DemoClass obj1(10,20.5,"Hello");
    DemoClass obj2;
    obj1.printData();

    // DemoClass obj3(obj1);
    // DemoClass obj4 = obj1;
    // obj2.printData();

    // DemoClass* ptr = new(sizeof(DemoClass));

    DemoClass obj5("Hello");

    DemoClass* objArray[10];
    DemoClassPtr objArray[10];

    myString s1;

    int var = 10;
    std::cout << var << std::endl;

    auto var2 = 10;
    std::cout << var2 << std::endl;

    auto name = "Parag";

    return 0;
}