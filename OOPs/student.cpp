#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int scores[5];
};

double average(struct Student &s1)
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += s1.scores[i];
    }
    return sum / 5;
}

struct Student highestScorer(struct Student stud[])
{
    double max = 0;
    struct Student s1;
    for (int i = 0; i < 3; i++)
    {
        if (max < average(stud[i]))
        {
            max = average(stud[i]);
            s1 = stud[i];
        }
    }
    return s1;
}

void swapScores(struct Student &s1, struct Student &s2)
{
    for (int i = 0; i < 5; i++)
    {
        int temp = s1.scores[i];
        s1.scores[i] = s2.scores[i];
        s2.scores[i] = temp;
    }
}

void displayStudentInfo(struct Student s1)
{
    cout << "Student ID: " << s1.id << endl;
    cout << "Name:" << s1.name << endl;
    cout << "Marks: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << s1.scores[i] << " ";
    }
    cout << "" << endl;
}

void errorHandling(struct Student arr[]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<5; j++){
            if(arr[i].scores[j] > 100 || arr[i].scores[j] < 0){
                cout << "Error in marks of Student ID" << arr[i].id << endl;
            }
        }
    }
}

int main()
{
    struct Student s1 = {1, "Krish", {1, 2, 3, 4, 6}};
    struct Student s2 = {2, "Pagla", {1, 2, 3, 4, 7}};
    struct Student s3 = {3, "Paglii", {1, 2, 3, 4, 8}};
    struct Student arr[3] = {s1, s2, s3};
    int x;
    cout << "1. Calculate and display the average score for each student\n";
    cout << "2. Find and display the highest scorer\n";
    cout << "3. Swap scores between two students\n";
    cout << "4. Display information for all students\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> x;
    while(x != 5){
        if(x == 1){
            for(int i = 0; i<3; i++){
                cout << "Student ID: " << arr[i].id << " Average: " <<average(arr[i]) <<endl;
            }
        }
        else if(x == 2){
            struct Student s1 = highestScorer(arr);
            displayStudentInfo(s1);
        }
        else if(x == 3){
            swapScores(arr[0], arr[1]);
        }
        else if(x == 4){
            for(int i = 0; i<3; i++){
                displayStudentInfo(arr[i]);
            }
        }
        cin >> x;
    }
    return 0;
}
