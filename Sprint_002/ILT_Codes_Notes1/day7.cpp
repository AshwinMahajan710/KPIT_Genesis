#include<iostream>
#include<thread>
#include<future>
#include<chrono>
#include<mutex>

// void printHelloWorld(){
//     std::cout<<"Hello world..."<<std::endl;
// };

// int squareTemp(int temp){
//     std::cout<<"\nExecuting square function..."<<std::endl;
//     return (temp*temp);
// }

// void square(std::promise<int>& tempProm){
//     int temp = 5*5;
//     tempProm.set_value(temp);
// }

// int main(){
//     // std::thread th(std::ref(printHelloWorld));
//     // std::thread sqth(std::ref(squareTemp),5);

//     // th.join();
//     // sqth.join();
//     // // th.detach();

//     // std::future<int> result =  std::async (std::launch::async,std::ref(squareTemp),5);
//     // std::cout<<"\nValue: "<<result.get()<<std::endl;

//     std::promise<int> prom;
//     std::future<int> result = prom.get_future();

//     std::thread t(std::ref(square), std::ref(prom));
//     std::cout<<"\nValue: "<<result.get()<<std::endl;  
    
//     t.join(); 

//     return 0;
// }

// void myfunc1(std::promise<int>& promise, int temp){
//     promise.set_value(temp*temp);
// }

// int main(){
//     std::promise<int> prom;
//     std::future<int> result = prom.get_future();

//     std::async(std::launch::async, myfunc1, std::ref(prom), 5);
//     std::cout<<result.get()<<std::endl;
// }



// now we will use thread for performing one operation and async for another operation

// void performEngineOperation(){
//     std::cout<<"\nPerforming engine diagnostic.."<<std::endl;
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::cout<<"Engine diagnostics completed.."<<std::endl;
// }

// int checkBatteryHealth() {
//     std::cout<<"Checking battery health: "<<std::endl;
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::cout<<"battery health checked: "<<std::endl;
//     return 80;
// }

// int main(){
//     std::thread diagnostics(std::ref(performEngineOperation));
//     std::future<int> health = std::async(std::launch::async, std::ref(checkBatteryHealth));
//     std::cout<<"\nBattery health: "<<health.get()<<std::endl;
//     diagnostics.join();
// }

// three threads
//  1. reading data from cameraSensor, LiDARSensor, RadarSensor

std::mutex mtx;

void detectDistCamera(std::promise<int>& promise){
    mtx.lock();
    std::cout<<"\nReading camera."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    promise.set_value(100);
    mtx.unlock();
}

void detectDistLidar(std::promise<int>& promise){
    mtx.lock();
    std::cout<<"\nReading Lidar."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    promise.set_value(75);
    mtx.unlock();
}
void detectDistRadar(std::promise<int>& promise){
    mtx.lock();
    std::cout<<"\nReading radar."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    promise.set_value(80);
    mtx.unlock();
}

double fuseSensorData(int v1, int v2, int v3){
    std::cout<<"\nCalculating average: "<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return ((v1+v2+v3) / 3.0);
}


int main(){

    std::promise<int> prom1;
    std::promise<int> prom2;
    std::promise<int> prom3;

    std::future<int> res1 = prom1.get_future();
    std::future<int> res2 = prom2.get_future();
    std::future<int> res3 = prom3.get_future();

    std::thread th1(std::ref(detectDistCamera), std::ref(prom1));
    std::thread th2(std::ref(detectDistLidar), std::ref(prom2));
    std::thread th3(std::ref(detectDistRadar), std::ref(prom3));

    std::future<double> average = std::async(std::launch::async, std::ref(fuseSensorData), res1.get(),res3.get(),res2.get());
    std::cout<<"\nAverage: "<<average.get()<<std::endl;

    return 0;
}


/*
 // This program simulates a car's engine, transmission, and navigation system. The startCar function starts the car's engine and transmission using std::async, which runs the function in a separate thread. The getDirections function gets directions from the navigation system using std::async, which also runs the function in a separate thread.
// The main function starts the car, gets directions from the navigation system, and waits for both tasks to complete using std::future. Finally, it prints the directions and stops the car.

#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Simulate a car's engine
class Engine {
public:
    void start() {
        std::cout << "Engine started" << std::endl;
    }

    void stop() {
        std::cout << "Engine stopped" << std::endl;
    }
};

// Simulate a car's transmission
class Transmission {
public:
    void shiftGear(int gear) {
        std::cout << "Shifted to gear " << gear << std::endl;
    }
};

// Simulate a car's navigation system
class Navigation {
public:
    std::string getDirections() {
        std::cout << "Getting directions..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return "Turn left in 0.5 miles";
    }
};

// Function to start the car's engine and transmission
std::future<void> startCar(Engine& engine, Transmission& transmission) {
    return std::async(std::launch::async, [&engine, &transmission]() {
        engine.start();
        transmission.shiftGear(1);
    });
}

// Function to get directions from the navigation system
std::future<std::string> getDirections(Navigation& navigation) {
    return std::async(std::launch::async, [&navigation]() {
        return navigation.getDirections();
    });
}

int main() {
    Engine engine;
    Transmission transmission;
    Navigation navigation;

    // Start the car
    auto startCarFuture = startCar(engine, transmission);

    // Get directions from the navigation system
    auto directionsFuture = getDirections(navigation);

    // Wait for the car to start and get directions
    startCarFuture.wait();
    std::string directions = directionsFuture.get();

    // Print the directions
    std::cout << "Directions: " << directions << std::endl;

    // Stop the car
    engine.stop();

    return 0;
}
*/