#include<iostream>
#include<functional>


// callbale object
void regularFunction(int var){
    std::cout<<"\nValue is "<<var<<std::endl;
}

int add(int a , int b){
    return a+b;
}
int subtratct(int a , int b){
    return a-b;
}
int multiply(int num1, int num2){
    return (num1 * num2);
}

// creating class
class Hello{
    public:
        int addition(int a, int b){return (a+b);}
        static int valid(int a , int b){ return b;}
};

// using "using" keyword to define the syntax and then use it
using mathOperation = int(*)(int ,int);

// passing function pointer inside function
void exceuteAll(int a, int b, mathOperation operation){
    std::cout<<operation(a,b)<<std::endl;
}
void executeWithFunctional(int a, int b, std::function <int(int, int)> op){
    std::cout<<op(a,b)<<std::endl;
}

int  main(){
    int a=10, b=20;
    std::cout<<"\nNormal Call: "<<add(a,b)<<std::endl;
    std::cout<<"\nNormal Call: "<<subtratct(a,b)<<std::endl;

    // decalaration of function pointer
    int (*opaeration) (int,int);
    opaeration = add; // binding function pointer
    std::cout<<"Addtion by function pointer: "<<opaeration(a,b)<<std::endl;
    opaeration = subtratct;
    std::cout<<"Subtract by function pointer: "<<opaeration(a,b)<<std::endl;
    opaeration = multiply;
    std::cout<<"Multiplication by function pointer: "<<opaeration(a,b)<<std::endl;

    // lets define a lamda function
    int bias = 5;
    auto lambda = [bias](int num1, int num2)->int {return (num1*num2 + bias);};
    // opaeration = lambda; // we can also use functional pointer to lamda function --> but when we use capture value it becomes not allowed
    // we cannot convert lamda with capture to a function pointer 

    // lets try the function pointer on class method
    Hello h;
    // opaeration = h.addition; // not valid
    opaeration = Hello::valid ; // valid

    // passing function pointer in function --> writing more modular code
    exceuteAll(10,20,add);
    exceuteAll(10,20,subtratct);
    exceuteAll(10,20,multiply);
    exceuteAll(10,20,Hello::valid);

    // more mordern c++ way
    std::function <int(int, int)> op;
    op = add;
    std::cout<<"std::function: "<<op(a,b)<<std::endl;
    op = lambda;
    std::cout<<"std::function: "<<op(a,b)<<std::endl;

    // at the time of using class non static function we use bind function
    op = std::bind(&Hello::addition, h, std::placeholders::_1, std::placeholders::_2);
    std::cout<<"std::bind "<<op(a,b)<<std::endl;

    return 0;
}

/*
#include <functional>
int add(int num1, int num2){
    return num1 + num2;
}

int subtract(int num1, int num2){
    return num1 - num2;
}

int multiply(int num1, int num2){
    return num1 * num2;
}

class Calculator{
    public:
        int addition(int num1, int num2){
            return num1 + num2;
        }

        static int staticAdddition(int num1, int num2){
            return num1 + num2;
        }
};

using mathOperation = int(*)(int, int);

void executeAndDisplay(const int num1,const int num2,const mathOperation& operation){
    std::cout << "executeAndDisplay " << operation(num1, num2) << std::endl;
}

using mathOperationStdFunction = std::function<int(int,int)>;

void executewithStdFunction(const int num1,const int num2,const mathOperationStdFunction& operation){
    std::cout << "executewithStdFunction " << operation(num1, num2) << std::endl;
}

int main(){
    std::cout << "Normal call " << add(10, 20) << std::endl;
    std::cout << "Normal call " << subtract(10, 20) << std::endl;

    // declaration of function pointer thaty takes 2 int arduments and return int
    int (*operation)(int, int);

    operation = add;
    std::cout << "Function pointer" << operation(10, 20) << std::endl;

    operation = subtract;
    std::cout << "Function pointer" << operation(10, 20) << std::endl;

    auto lambda = [](int num1, int num2) { return num1 * num2; };
    operation = lambda;
    std::cout << "Function pointer" << operation(10, 20) << std::endl;

    int bias = 5;
    auto lambdaCapture = [&bias](int num1, int num2) { return num1 * num2 + bias; };
    // operation = lambdaCapture;   // function pointers can not work with lambda capture 
    
    Calculator calc;
    // operation = calc.addition;  // NOT Allowed, 

    operation = Calculator::staticAdddition;
    std::cout << "Function pointer static function" << operation(10, 20) << std::endl;

    executeAndDisplay(10, 20, add);
    executeAndDisplay(10, 20, subtract);
    executeAndDisplay(10, 20, lambda);
    executeAndDisplay(10, 20, Calculator::staticAdddition);
    std::cout << "-----------------------------------\n";
    std::function<int(int,int)> op;
    op = add;
    std::cout << "std::function " << op(10, 20) << std::endl;

    op = subtract;
    std::cout << "std::function" << op(10, 20) << std::endl;

    op = lambda;
    std::cout << "std::function" << op(10, 20) << std::endl;

    op = lambdaCapture;
    std::cout << "std::function" << op(10, 20) << std::endl;

    mathOperationStdFunction opbind = std::bind(&Calculator::addition,&calc,std::placeholders::_1,std::placeholders::_2);
    std::cout << "std::function" << opbind(10, 20) << std::endl;

    op = Calculator::staticAdddition;
    std::cout << "std::function" << op(10, 20) << std::endl;
    
    std::cout << "-----------------------------------\n";
    executewithStdFunction(10, 20, add);
    executewithStdFunction(10, 20, subtract);
    executewithStdFunction(10, 20, lambda);
    executewithStdFunction(10, 20, lambdaCapture);
    executewithStdFunction(10, 20, opbind);
    executewithStdFunction(10, 20, Calculator::staticAdddition);
}
 
*/

/*
 
#include <memory>
class Demo{
    public:
    Demo() {std::cout << "Demo constructor called" << std::endl;}
    ~Demo(){std::cout << "Demo destructor called" << std::endl;}
    void display(){std::cout << "Hello\n"; }
};
int main(){
    Demo* demo1 = new Demo;
    demo1->display();
    delete demo1;
    // unique pointer
    std::unique_ptr<Demo> demo2 = std::make_unique<Demo>();
    demo2->display();
    // std::unique_ptr<Demo> demo3 = demo2; // can not copy
    std::unique_ptr<Demo> demo3 = std::move(demo2); // ownership transfer allowed
    // shared pointer
    std::shared_ptr<Demo> demo4 = std::make_shared<Demo>();
    demo4->display();
    std::shared_ptr<Demo> demo5 = demo4;    // copy is allowed, shared ownership
    demo5->display();
    std::cout << "count " << demo4.use_count() << '\n';
    // weak pointer
    std::weak_ptr<Demo> demo6weak = demo5;
    auto temp = demo6weak.lock();
    temp->display();
}
 
*/