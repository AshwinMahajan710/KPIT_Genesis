#ifndef SHELF_H
#define SHELF_H

#include"5699368_MD12_Task1_Book.h"
#include<iostream>
#include<string>
#include<memory>
#include<vector>

class Shelf{
    private:
        std::string m_shelfName;
        std::vector<std::shared_ptr<Book>> m_books;
    public:
        Shelf() ;
        Shelf(const std::string& shelfName_);

        // method to add book
        void addBook(std::shared_ptr<Book> newBook);

        // method to print details of shelf
        friend std::ostream& operator << (std::ostream& out, const Shelf& other);
};

#endif // SHELF_H
