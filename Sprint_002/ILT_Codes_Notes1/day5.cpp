#include<iostream>
#include<thread>
#include<chrono> // special library to deal with timing
#include<vector>
#include<mutex> // for synchronization

// refered to as thread function when used with the thread
void greet(const std::string& name){
    auto startTime = std::chrono::high_resolution_clock::now(); // storing the start time
    std::cout<<"hello.... good morning..."<<name<<" ."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // time in sec
    auto endTime = std::chrono::high_resolution_clock::now(); // storing the end time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout<<"done with thread "<<name<<" ."<<"at time "<<duration<<std::endl;
}

class MyDemo{
    public:
        void memberFunc(std::string name){
            std::cout<<"Hello good morning..."<<name<<std::endl;
        }
};
// main function
int main(){

    std::thread th1(std::ref(greet), "Ashwin"); // using std::ref so that the coopy of function should not be created 
    std::thread th2(std::ref(greet), "Saurabh"); 
    std::thread th3(std::ref(greet), "yash");
    
    std::vector<std::string> names = {"Ashwin","Saurabh","Yash"};
    std::vector<std::thread> threads;

    for(const auto& name: names){
        threads.emplace_back(std::ref(greet), name);
    }
    
    for(auto &thread: threads){
        if(thread.joinable()){
            thread.join();
        }
    }

    std::cout<<"\n * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * \n";
    MyDemo demo1,demo2,demo3;
    std::thread demoTh1(&MyDemo::memberFunc, &demo1, "One");
    std::thread demoTh2(&MyDemo::memberFunc, &demo2, "Two");
    std::thread demoTh3(&MyDemo::memberFunc, &demo3, "Three");

    demoTh1.join();
    demoTh2.join();
    demoTh3.join();

    // th1.join(); 
    // th2.join();
    // th3.join();

    std::cout<<"\nDone with main..."<<std::endl;
    return 0;
} 

// std::mutex demoMutex;

// class MyDemoClass {
// private:
//     std::thread thread;
//     std::string name;

//     void memberFunction(const std::string& msg) {
//         demoMutex.lock();
//         std::cout << "Hello, Good Morning! " << name << " - " << msg << std::endl;
//         demoMutex.unlock();
//     }

// public:
//     MyDemoClass(const std::string& n) : name(n) {}
    
//     // Destructor
//     ~MyDemoClass() {
//         if(thread.joinable()){
//             thread.join();
//         }
//     }
    
//     void startThread(){
//         thread = std::thread(&MyDemoClass::memberFunction, this, name);
//     }
// };


// int main(){

//     MyDemoClass demo1("one"), demo2("two"), demo3("three");
//     demo1.startThread();
//     demo2.startThread();
//     demo3.startThread();

//     return 0;
// }