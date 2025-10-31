//exception handling

#include<iostream>
#include<stdexcept>

// int main(){
//     try{
//         int num = 1, den = 0;
//         if(den == 0){
//             throw std::runtime_error("Not divisible by 0");
//         }
//         std::cout<<num/den<<std::endl;
//     }
//     catch(const std::exception& e){
//         std::cout<<e.what()<<std::endl;
//     }
//     return 0;
// }

// class VehicleSpeedControl{
//     private:
//         int speed = 0;
//     public:
//         VehicleSpeedControl(int spd){
//             if (spd < 0 || spd > 150){
//                 throw std::invalid_argument("Speed values out of range..");
//             }  
//             speed = spd;
//         }
// };

// int main(){
//     try{
//         VehicleSpeedControl car2(-160);
//         VehicleSpeedControl car1(160);
//     }
//     catch(const std::exception& e){
        
//     }
//     try{
//         VehicleSpeedControl car2(160);
//     }
//     catch(const std::exception& e){
//         std::cout<<e.what()<<std::endl;
//     }

//     return 0;
// }

// CREATING CUTOM EXCEPTION CLASS 
// class NegativeSpeedValuesException: public std::exception{
//     public:
//         const char* what() const noexcept override{
//             return "Speed values are completely out of range.....";
//         }
// };

// class VehicleSpeedControl{
//     private:
//         int speed = 0;
//     public:
//         VehicleSpeedControl(int spd){
//             if (spd < 0 || spd > 150){
//                 throw NegativeSpeedValuesException();
//             }  
//             speed = spd;
//         }
// };

// int main(){
//     try{
//         VehicleSpeedControl car2(-160);
//         VehicleSpeedControl car1(160);
//     }
//     catch(const NegativeSpeedValuesException& e){
//            std::cout<<e.what()<<std::endl;
//     }
//     try{
//         VehicleSpeedControl car2(160);
//     }
//     catch(const NegativeSpeedValuesException& e){
//         std::cout<<e.what()<<std::endl;
//     }

//     return 0;
// }

 
class NegativeSpeedValueException: public std::exception{
    public:
        const char* what() const noexcept override{
            return "Negative speed value is not allowed";
        }
};
class SpeedLimitException: public std::exception{
    public:
        const char* what() const noexcept override{
            return "Speed limit exceeded";
        }
};
class VehicleSpeedControl{
    private:
        int speed = 0;
    public:
      
        void setSpeed(int spd) {
            if(spd < 0){
                throw NegativeSpeedValueException();
            }
            else if(spd > 150){
                throw SpeedLimitException();
            }   
            speed = spd;
        }
        ~VehicleSpeedControl(){
            std::cout << "VehicleSpeedControl object destroyed" << '\n';
        }    
};
int main(){
    VehicleSpeedControl car;
    try{
        car.setSpeed(20);
    }catch(const NegativeSpeedValueException& msg){
        std::cout << msg.what() << '\n';
    }
    try{
        car.setSpeed(-20);
    }catch(const NegativeSpeedValueException& msg){
        std::cout << msg.what() << '\n';
    }
    try{
        car.setSpeed(500);
    }catch(const SpeedLimitException& msg){
        std::cout << msg.what() << '\n';
    }   
}
 