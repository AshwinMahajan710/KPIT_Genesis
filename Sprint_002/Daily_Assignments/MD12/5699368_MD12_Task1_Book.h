#ifndef BOOK_H
#define BOOK_H

#include<string>

class Book{
    private:
        std::string m_bookName{};
        double m_price{};
        std::string m_author{};
    public:
        Book() ; // constructor delegation
        Book(const std::string& name_, const std::string author_, double price_);

        // getters
        std::string getBookName() const;
        std::string getAuthor() const;
        double getPrice() const;
        
        // setters
        void setBookName(const std::string& name_);
        void setAuthor(const std::string& author_);
        void setPrice(double price_);

        // helper display()
        void display() const;
};

#endif // BOOK_H
