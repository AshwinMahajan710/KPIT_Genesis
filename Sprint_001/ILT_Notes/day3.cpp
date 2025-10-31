#include<iostream>

// Composition:

// Use if:
    // - Individual parts cannot exist indeendently
    // - Want to control ownership of lifetime
    // - has a relationship
    // - also called as tight coupling
// class Engine{
//     public:
//         void ignite(){
//             std::cout<<"\nEngine Ignited..."<<std::endl;
//         }
// };

// class BreakSystem{
//     public:
//         void apply(){
//             std::cout<<"Breaks applied..."<<std::endl;
//         }
// };

// class Car{
//     private:
//         Engine engine;
//         BreakSystem breaks;
//     public:
//         void start(){
//             engine.ignite();
//             std::cout<<"Car Started..."<<std::endl;
//         }
//         void stop(){
//             breaks.apply();
//             std::cout<<"Car Stopeed..."<<std::endl;
//         }
// };

// int main(){
//     Car car;
//     car.start();
//     car.stop();
//     return 0;
// }


// Aggregation
// Also called as loose coupling
// Diagnostic class is not owning sensor
// using one in other but without ownership
// class Sensor{
//     public:
//         std::string sensorID;
//         Sensor(std::string id) {this->sensorID = id;}
//         double readSensor(){ return 12.5;}      
// };

// class DiagnosticTool{
//     private:
//         Sensor* sensor;
//     public:
//         DiagnosticTool(Sensor* s): sensor(s){}
//         void runDiagnostics(){
//             std::cout<<"\nSensor ID: "<<sensor->sensorID<<" Reading: "<<sensor->readSensor()<<std::endl;
//         }
// };

// int main(){
//     Sensor* sensor = new Sensor("BreakSensor");
//     DiagnosticTool tool(sensor);
//     tool.runDiagnostics();
//     return 0;
// }

// Inheritance
class Vehicle{
    protected:
        std::string make;
        int yearOfManufacture;
    public:
        Vehicle(std::string make, int yearOfManufacture): make(make), yearOfManufacture(yearOfManufacture){}
        virtual void start(){
            std::cout<<"\nMake: "<<make<<" Year of manufacture: "<<yearOfManufacture<<"started.."<<std::endl;
        }
        virtual void stop(){
            std::cout<<"\nMake: "<<make<<" Year of manufacture: "<<yearOfManufacture<<"stopped.."<<std::endl;
        }
        virtual void runDiagnostics() = 0; // pure virtual function
};

class Car:public Vehicle{
    private:
        std::string model;
        int numOfSeats;
    public:
        Car(std::string make, int years, std::string model, int no) : Vehicle(make,years), model(model), numOfSeats(no){};
        void honk(){
            std::cout<<"\nCar honked.."<<std::endl;
        }  
        void showDetails(){
            std::cout<<"\nMake: "<<make<<" Year of manufacture: "<<yearOfManufacture<<"Model "<<model<<"num of seats"<<numOfSeats<<std::endl;
        }
        void start () override{
            std::cout<<"\nCar start has been called.."<<std::endl;
        }
        void stop () override{
            std::cout<<"\nCar stop has been called.."<<std::endl;
        }
        void runDiagnostics() override{
            std::cout<<"Car diagnostic has been run successfully..."<<std::endl;
        }
};

int main(){
    // Vehicle v1("TATA",10); this will give error because we cannot create object of vehicle as it is abstract class
    Car c1("TATA",10, "Nexon", 5);

    // v1.start();
    // v1.stop();

    // basic functions
    c1.start();
    c1.stop();
    c1.honk();
    c1.showDetails();

    std::cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<std::endl;
    Vehicle * v1 = new Car("Mahindra",10, "XUV700", 5);
    v1->runDiagnostics();
    v1->start();
    v1->stop();
    
    return 0;
}