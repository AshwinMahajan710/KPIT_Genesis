#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<queue>


// class CANHandler{
//     private:
//         std::unordered_map<int, std::string> myHandler;
//     public:
//         void addHandler(int meassageKey_, const std::string& messageValue_){
//             myHandler[meassageKey_] = messageValue_;
//             std::cout<<"\nMessage added successfully... Key: "<<meassageKey_<<" Value: "<<messageValue_<<std::endl;
//         }

//         void displayHandler() const{
//             for (auto it = myHandler.begin(); it != myHandler.end(); it++)
//             {
//                 std::cout<<"Key: "<<it->first<<" Value: "<<it->second<<std::endl;
//             }
            
//             // works
//             // for(auto &it: myHandler){
//             //     std::cout<<"Key: "<<it.first<<" Value: "<<it.second<<std::endl;
//             // }
//         }

//         void removeHandler(int messageKey){
//             if(myHandler.find(messageKey)!=myHandler.end()){
//                 myHandler.erase(messageKey);
//             }
//         }        

//         void findHandler(int messageKey){
//             if(myHandler.find(messageKey)!=myHandler.end()){
//                 std::cout<<"Handler found.."<<std::endl;
//             }
//             else {
//                 std::cout<<"Handler not found.."<<std::endl;
//             }
//         }

         
// };

// int main(){

//     CANHandler handler;
//     handler.addHandler(1,"Handling engine");
//     handler.addHandler(2,"Brake ");
//     handler.addHandler(3,"Transmission ");

//     handler.displayHandler();
//     handler.removeHandler(1);

//     std::cout<<std::endl;
//     handler.displayHandler();

//     handler.findHandler(3);
//     return 0;
// }

// class StackHandler{
//     private :
//         std::stack<int> st;
//     public:
//         void add(int ele){
//             st.push(ele);
//         }
//         void remove(){
//             st.pop();
//             std::cout<<"Element removed.."<<std::endl;
//         }
//         void checkTop(){
//             if(st.empty()){{std::cout<<"Stack is empty"<<std::endl;}}
//             else {std::cout<<"Top element is: "<<st.top()<<std::endl;}
            
//         }
//         void checkEmpty(){
//             if(st.empty()){std::cout<<"Stack is empty"<<std::endl;}
//             else{std::cout<<"Stack is not empty"<<std::endl;}
//         }
// };

// int main(){
//     StackHandler st;
//     st.add(10);
//     st.add(11);
//     st.add(12);
//     st.add(13);

//     st.checkTop();

//     st.checkEmpty();
    
//     return 0;
// }

// class QueueHandler{
//     private :
//         std::queue<int> q;
//     public:
//         void add(int ele){
//             q.push(ele);
//         }
//         void remove(){
//             q.pop();
//             std::cout<<"Element removed.."<<std::endl;
//         }
//         void checkAccessibleElements(){
//             if(q.empty()){{std::cout<<"Queue is empty"<<std::endl;}}
//             else {std::cout<<"front element is: "<<q.front()<<" back element is: "<<q.back()<<std::endl;}
            
//         }
//         void checkEmpty(){
//             if(q.empty()){std::cout<<"Queue is empty"<<std::endl;}
//             else{std::cout<<"Queue is not empty"<<std::endl;}
//         }
// };

// int main(){
//     QueueHandler q;
//     q.add(10);
//     q.add(11);
//     q.add(12);
//     q.add(13);

//     q.checkAccessibleElements();

//     q.checkEmpty();

//     return 0;
// }