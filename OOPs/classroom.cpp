#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Student{
    private:
    string name;
    int age;
    int id;
    int grade;
    public:
    Student(string t, int a, int i, int grade){
        name = t;
        age = a;
        id = i;
        grade = grade;
    }
    string getName()
    {
        return this->name;
    }
    int getAge(){
        return this->age;
    }
    int getID(){
        return this->id;
    }
    int getGrade(){
        return this->grade;
    }
};

class Classroom{
    public:
    int id;
    vector<Student> arr;
    Classroom(int i){
        id = i;
        vector<Student> arr;
    }
    void add(Student b1){
        arr.push_back(b1);
    };

    void remove(Student b1){
        for(auto it=arr.begin();it!=arr.end();it++)
        {
            if(it->getID()==b1.getID())
            {
                arr.erase(it);
            }
        }
    }

    void display()
    {
        cout<<"Class: "<<id<<endl;
        for(auto it=arr.begin();it!=arr.end();it++)
        {
                cout<<"Name: " <<it->getName()<<endl;
                cout<<"Age: " <<it->getAge()<<endl;
                cout<<"ID: " <<it->getID()<<endl;
                cout<<"Grade: "<<it->getGrade()<<endl;
        }
    }
};

int main()
{
    Classroom lib = Classroom(3);
    Classroom lib1 = Classroom(4);
    Student b1=Student("Krish", 16, 7, 2);
    Student b2=Student("Krish2", 18, 9, 8);
    Student b3=Student("Krish3", 10, 22, 5);

    lib.add(b1);
    lib.add(b2);
    lib.remove(b1);
    lib.display();
    lib1.add(b3);
    lib1.display();
}