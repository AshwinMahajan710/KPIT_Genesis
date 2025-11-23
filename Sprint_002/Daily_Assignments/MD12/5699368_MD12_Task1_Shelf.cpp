#include"5699368_MD12_Task1_Shelf.h"
#include"5699368_MD12_Task1_Book.h"
#include<iostream>
#include<string>
#include<memory>
#include<vector>

// constructor --> default (delegated)
Shelf::Shelf(): Shelf("Unknown"){};

// constructor --> parameterized  
Shelf::Shelf(const std::string& shelfName_): m_shelfName(shelfName_){}

// method to add book
void Shelf::addBook(std::shared_ptr<Book> newBook){
    m_books.emplace_back(std::move(newBook));
    std::cout<<"Book moved to shelf successfully "<<std::endl;
}

// method to print details of shelf
std::ostream& operator << (std::ostream& out, const Shelf& other){
    out<<"\nShelf Name: "<<other.m_shelfName<<std::endl;
    for(const auto &book: other.m_books){
        out<<"\nBook Name: "<<book->getBookName()<<std::endl;
        out<<"Author Name: "<<book->getAuthor()<<std::endl;
        out<<"Price: "<<book->getPrice()<<std::endl;
    }
    return out;
}