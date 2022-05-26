// https://www.hackerrank.com/challenges/30-abstract-classes/
   
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

// Enter your code here.
// --------------------------------------------------------- // 
class MyBook : Book
{
public:
    MyBook(string title, string author, int price) : Book(title, author) , price{price}
    { }
    
    void display () override {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
private:
    const int price; 
};
// --------------------------------------------------------- // 

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
