#include<iostream>

int main(){
    int* arr = new int[10];

    arr[1] = 10;
    arr[2] = 12;
    arr[0] = 11;

    for(int i=0;i<10;i++){
        std::cout<<"\n"<<arr[i];
    }

    delete[] arr;
    return 0;
}