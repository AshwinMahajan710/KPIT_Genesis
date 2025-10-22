// - A move constructor is a special constructor in C++ that’s called when you create a new object from a temporary (rvalue).

// - Suppose Following is the code 


#include<iostream>
#include<utility>

class Simple {
private:
    int* data;
public:
    Simple(int value) : data(new int(value)) {
        std::cout << "Constructor called, data = " << *data << std::endl;
    }

    ~Simple() {
        if(data) delete data;
        std::cout << "Destructor called" << std::endl;
    }

    // This is move constructor ---> && means "this constructor accepts a temporary object (rvalue) that is about to go away."
    Simple(Simple&& other) {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move constructor called" << std::endl;
    }
    
    Simple(const Simple& other) {
        data = new int (*other.data);
        std::cout << "Copy constructor called" << std::endl;
    }
};

// - The code like below will use the move constructor

int main(){

    Simple obj1(42);
    Simple obj2 = std::move(obj1); // This will call the move constructor
    Simple obj3(Simple(50)); // Now what happened here is instead of creating copy and then assign it .. here copiler automatically understand that I have to create object for obj3 and assigns object directly (Optimization technique)
}


// - We can see in the move constructor definition, that the data is assigned to the this object and then reference object data is erased so that there should no violation of integrity 