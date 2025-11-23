#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>

std::mutex mt;

void print(int count, char ch){
    mt.lock();
    for(int i=0;i<count;i++){
        std::cout<<ch;
        // std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
    std::cout<<std::endl;
    mt.unlock();
}

int counter = 0;

void increment(){
    std::unique_lock<std::mutex> lock(mt, std::defer_lock);
    // lock.lock();   // lock when needed
    lock.lock();
    ++counter;
    std::cout<<"\nCounter: "<<counter<<std::endl;
    // mt.unlock();
    throw "Exception";
}

int main(){

    std::vector<std::thread> threads2;
    for(int i=0;i<10;i++){
        threads2.emplace_back([]{
            try
            {
                increment();
            }
            catch(const char* e)
            {
                std::cerr << e << '\n';
            }
                           
        });
    }

    for(auto &t : threads2){
        t.join();
    }
    
    // std::thread th1(std::ref(print), 5, '*');
    // std::thread th2(std::ref(print), 10, '/');
    // std::thread th3(std::ref(print), 20, '#');

    // th1.join();
    // th2.join();
    // th3.join();

    // std::vector<std::thread> threads;
    // threads.emplace_back(std::ref(increment));
    // threads.emplace_back(std::ref(increment));
    // threads.emplace_back(std::ref(increment));

    // for(auto &thread: threads){
    //     thread.join();
    // }

    return 0;
}