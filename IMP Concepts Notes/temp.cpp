#include<iostream>
#include<memory>

int main(){
    
        std::unique_ptr<int> a = std::make_unique<int>(10); // for creating single unique ptr
        std::unique_ptr<int> arr[10];
        for(auto i=0;i<10;i++){
            arr[i] = std::make_unique<int>(i+1);
        }

        arr[0].get();
        std::swap(arr[0],arr[1]); // swap works fine

        std::unique_ptr<int>  temp = std::move(arr[2]);

        for(auto& i: arr){
            std::cout<<*i<<std::endl;
        }

}