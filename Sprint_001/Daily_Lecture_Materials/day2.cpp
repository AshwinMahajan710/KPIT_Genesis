 
// #include <iostream>
// class Car{
//     private:
//         static int s_totalCar;    // static data member
//         int engineHealth;
//     public:
//         Car(){
//             s_totalCar++;
//             engineHealth = 50;
//         }
//         static int getTotalCar(){   // static function/method
//             return s_totalCar;
//         }
//         friend void service(Car&);  // friend function
//         friend class DiagnosticTool;    // friend class
// };
// int Car::s_totalCar = 0;
// void service(Car& other){
//     other.engineHealth = 100;
//     std::cout << "Engine Serviced\n" ;
// }
// class DiagnosticTool{
//     public:
//         void read(Car& other){
//             if(other.engineHealth > 50){
//                 std::cout << "Engine is okay\n";
//             }
//         }
// };
// int main(){
//     Car car1;
//     std::cout << car1.getTotalCar() << '\n';
//     Car car2;
//     std::cout << car2.getTotalCar() << '\n';
//     Car car3;
//     std::cout << car1.getTotalCar() << '\n';
//     service(car1);
//     DiagnosticTool dt1;
//     dt1.read(car1);
//     return 0;
// }
 

 
#include<iostream>

class FuelTank{
    private:
        uint m_liters;
    public:
        FuelTank(uint liters_):m_liters(liters_){}
    
        FuelTank operator+(const FuelTank& other){
        return FuelTank(this->m_liters + other.m_liters);
        }
        
        friend std::ostream& operator<<(std::ostream& os,const FuelTank& other){
            os << other.m_liters;
            return os;
        }
};
int main(){
    FuelTank tank1(40), tank2(20);
    FuelTank tatalFuel = tank1 + tank2;
    std::cout << "Total Fuel is" << tatalFuel << '\n';
    return 0;
}
 