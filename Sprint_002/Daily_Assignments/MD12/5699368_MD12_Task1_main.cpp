#include"5699368_MD12_Task1_Shelf.h"
#include"5699368_MD12_Task1_Book.h"
#include<iostream>
#include<string>
#include<memory>
#include<vector>

int main(){

    // creating shelf obj and add two books and then print using <<
    Shelf shelf;
    shelf.addBook(std::make_shared<Book>("Garudzep","Vasant kanetkar", 12345.0));
    shelf.addBook(std::make_shared<Book>("Agnipankh","APJ Abdul Kalam", 112345.0));

    std::cout<<shelf;
}