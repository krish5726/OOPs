#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Book
{
    
    private:
    string title;
    string author;
    int isbn;
    bool available;

    public:
    Book(string title,string author,int isbn)
    {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->available = false;
    }

    void setBookTitle(string title)
    {
        this->title = title;
    }
    void setBookAuthor(string author)
    {
        this->author = author;
    }
    void setBookISBN(int isbn)
    {
        this->isbn = isbn;
    }
    void setBookAvailable(bool available)
    {
        this->available = available;
    }

    string getBookTitle()
    {
        return this->title;
    }
    string getBookAuthor()
    {
        return this->author;
    }
    int getBookISBN()
    {
        return this->isbn;
    }
    bool getBookAvailable()
    {
        return this->available;
    }
};

class Library
{
    public:
    vector<Book>book;

    void add_book(Book b)
    {
        b.setBookAvailable(true);
        book.push_back(b);
    }

    void remove_book(Book b)
    {
        for(auto it = book.begin();it!=book.end();it++)
        {
            if(b.getBookISBN() == it->getBookISBN())
            {
                b.setBookAvailable(false);
                book.erase(it);
                break;
            }
        }
    }

    void display_books()
    {
        for(auto it = book.begin();it!=book.end();it++)
        {
            if(it->getBookAvailable())
            {
                cout << "Name:" << it->getBookTitle() << endl;
                cout << "Author:" << it->getBookAuthor() << endl;
                cout << "ISBN:" << it->getBookISBN() << endl;
                cout << endl;
            }
        }
    }
};

int main()
{
    Library lib;
    Book book1("A","A1",45);
    Book book2("B","B1",264);
    Book book3("C","C1",18);
    lib.add_book(book1);
    lib.add_book(book2);
    lib.add_book(book3);
    lib.display_books();
    lib.remove_book(book1);
    lib.display_books();
}