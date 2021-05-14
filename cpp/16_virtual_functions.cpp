// https://www.hackerrank.com/challenges/virtual-functions/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Enter your code here.
// --------------------------------------------------------- //	

class Person
{
protected:
    string name;
    int age;
public:
    virtual void putdata() = 0;
    virtual void getdata() = 0;
};

class Professor : public Person
{
public:
    Professor()
        :id {cur_id++}
    {         
    }

    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << id << endl;
    }

    void getdata()
    {
        cin >> name >> age >> publications;
    }
private:
    int publications;
    int id;
    static int cur_id; 
};

class Student : public Person
{
public:
    Student()
        : id {cur_id++}
    {
    }

    void putdata()
    {
        cout << name << " " << age << " " << sum << " " << id << endl;
    }

    void getdata()
    {
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            cin>>marks[i];
            sum += marks[i];
        }
    }
private:
    int marks[6];   
    int sum = 0;
    int id;
    static int cur_id; 
};

int Professor::cur_id{1};
int Student::cur_id{1};

// --------------------------------------------------------- //	

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
