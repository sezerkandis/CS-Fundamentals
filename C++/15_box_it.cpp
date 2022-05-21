// https://www.hackerrank.com/challenges/box-it/

#include<bits/stdc++.h>

using namespace std;

#include <iostream>
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

// Enter your code here.
// --------------------------------------------------------- //
class Box
{
public:
    Box()
    {
        
    }
    ~Box()
    {
        
    }
    Box(int l, int b, int h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    Box(Box &box)
    {
        length = box.getLength();
        breadth = box.getBreadth();
        height = box.getHeight();
    }
    
    int getLength() const 
    {
        return length;
    }
    int getBreadth () const 
    {
        return breadth;
    }
    int getHeight () const 
    {
        return height;
    }
    long long CalculateVolume() 
    {
        return (long long)(breadth) * length * height;
    }
    bool operator<(const Box &box)
    {
        return 
        length < box.length ||
        (breadth < box.breadth && length == box.length) ||
        (height < box.height && breadth == box.breadth && length == box.length);        
    } 
private:
    int length = 0, breadth = 0, height = 0;
};

ostream& operator<<(ostream& os, Box box)
{
    os << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();
    return os;
} 

// --------------------------------------------------------- //

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}