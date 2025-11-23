#include"5699368_MD12_Task1_Book.h"
#include<iostream>
#include<string>

// constructor -> default (delegated)
Book::Book(): Book("UNKOWN","UNKOWN",0.0){} ; 

// constructor --> parameterized
Book::Book(const std::string& name_, const std::string author_, double price_): m_bookName(name_), m_author(author_), m_price(price_){}

// getters
std::string Book::getBookName() const{
    return m_bookName;
}
std::string Book::getAuthor() const{
    return m_author;
}
double Book::getPrice() const{
    return m_price;
}

// setters
void Book::setBookName(const std::string& name_){
    m_bookName = name_;
}
void Book::setAuthor(const std::string& author_){
    m_author = author_;
}
void Book::setPrice(double price_){
    m_price = price_;
}

// helper display()
void Book::display() const{
    std::cout<<"\nBook Name: "<<m_bookName<<std::endl;
    std::cout<<"Author Name: "<<m_author<<std::endl;
    std::cout<<"Price: "<<m_price<<std::endl;
}