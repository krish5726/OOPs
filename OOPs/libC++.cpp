#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;
 class Book{
         private:
         string title;
         string author;
         int copiesAvailable;
         int bookID;
         public:
         Book(int id, string t, string a, int c){
            this->bookID = id;
            this->title = t;
            this->author = a;
            this->copiesAvailable = c;
        }
         int getID(){
            return this->bookID;
        }
         string getTitle(){
            return this->title;
        }
         string getAuthor(){
            return this->author;
        }
         int getCopies(){
            return this->copiesAvailable;
        }
         void setCopies(int n){
            this->copiesAvailable = n;
        }
    };

 class Student{
         private:
         int studentID;
         string name;
         vector<Book*> borrowedBooks;
         public:
         Student(int id, string n){
            this->studentID = id;
            this->name = n;
        }
         int getID(){
            return this->studentID;
        }
         string getstring(){
            return this->name;
        }
         vector<Book*> getBorrowedBooks(){
            return this->borrowedBooks;
        }
         void setBorrowedBooks(vector<Book*> b){
            this->borrowedBooks = b;
        }
         void printBooks(){
            cout << "Books borrowed by student " << this->studentID << ":" << endl;
            if(this->borrowedBooks.size() == 0){
                cout << "No books borrowed." <<endl;
            }
            else{
                for(Book *b: this->borrowedBooks){
                    cout << "Book ID: " << b->getID() << ", ";
                    cout << "Title: " << "\"" << b->getTitle() << "\", ";
                    cout << "Author: " << "\"" << b->getAuthor() <<"\""<<endl;
                }
            }


        }
    };

 class Transactions{
        private:
         Book *b;
         Student *s;
        public:
         Transactions(Book *b, Student *s){
            this->b = b;
            this->s = s;
        }
         void borrow(){
            if(b->getCopies() > 0){
                vector<Book*> bk = s->getBorrowedBooks();
                bk.push_back(b);
                s->setBorrowedBooks(bk);
                b->setCopies(b->getCopies()-1);
            }
        }
         void returnBook(){
            vector<Book*> bk = s->getBorrowedBooks();
            for(auto it = bk.begin(); it!=bk.end(); it++){
                if((*it)->getID() == b->getID()){
                    bk.erase(it);
                }
            }
            s->setBorrowedBooks(bk);
            b->setCopies(b->getCopies() + 1);
        }
    };

     class Library{
        private:
         vector<Student*> students;
         vector<Book*> books;
         vector<Transactions*> trans;
        public:
         vector<Book*> getBooks(){
            return this->books;
        }
         vector<Student*> getStudents(){
            return this->students;
        }
         vector<Transactions*> getTrans(){
            return this->trans;
        }
         void setBooks(vector<Book*> b){
            this->books = b;
        }
         void setStudents(vector<Student*> b){
            this->students = b;
        }
         void setTrans(vector<Transactions*> b){
            this->trans = b;
        }
    };

vector<string> split(const string& str, const string& delim)
{
    vector<string> result;
    size_t start = 0;
    for (size_t found = str.find(delim); found != string::npos; found = str.find(delim, start))
    {
        result.emplace_back(str.begin() + start, str.begin() + found);
        start = found + delim.size();
    }
    if (start != str.size())
        result.emplace_back(str.begin() + start, str.end());
    return result;      
}

int main(){
    int n, m, q;
    cin >> n;
    cin >> m;
    cin >> q;
    Library lib = Library();
    vector<Book*> book;
    vector<Student*> std;
    vector<Transactions*> trans;
    for(int i = 0; i<n; i++){
        int bid;
        string name;
        string auth;
        int cp;
        cin >> bid;
        getline(cin, name);
        vector<string> listFilesMax = split(name, "\"");
        name = listFilesMax[1];
        auth = listFilesMax[3];
        char s = listFilesMax[4][1];
        cp = int(s) - 48;
        Book *b1 = new Book(bid, name, auth, cp);
        book.push_back(b1);
        lib.setBooks(book);
    }
    for(int i = 0; i<m; i++){
        int sid;
        string sname;
        cin >> sid;
        cin >> sname;
        Student *s1 = new Student(sid, sname);
        std.push_back(s1);
        lib.setStudents(std);
    }
    for(int i = 0; i<q; i++){
        int bo, bid, sid;
        cin >> bo;
        cin >> bid;
        cin >> sid;
        if(bo == 1){
            Book *b1 = new Book(1, "K", "K", 1);
            Student *s1 = new Student(1, "K");
            for(Book *bk: book){
                if(bid == bk->getID()){
                    b1 = bk;
                }
            }
            for(Student *s: std){
                if(sid == s->getID()){
                    s1 = s;
                }
            }
            Transactions *t = new Transactions(b1, s1);
            t->borrow();
        }
        else{
            Book *b1 = new Book(1, "K", "K", 1);
            Student *s1 = new Student(1, "K");
            for(Book *bk: book){
                if(bid == bk->getID()){
                    b1 = bk;
                }
            }
            for(Student *s: std){
                if(sid == s->getID()){
                    s1 = s;
                }
            }
            Transactions *t = new Transactions(b1, s1);
            t->returnBook();
        }
    }
    for(Student *s: std){
        s->printBooks();
    }
}