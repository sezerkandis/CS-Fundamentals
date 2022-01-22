// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

#include <iostream>
#include <cstdio>
using namespace std;

// Enter your code here.
// --------------------------------------------------------- // 
string names[9] = {"one" , "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void funct(int a1, int a2)
{    
    for(int i = a1; i <= a2; i++) {
        if (i >= 1 && i <= 9) {
            cout << names[i - 1] << endl;
        }
        else if (i > 9) {
            if (i & 0x00000001) {
                cout << "odd" << endl;
            }
			else {
                cout << "even" << endl;
			}
        }
    }
}
// --------------------------------------------------------- // 

int main() {
    
    // Enter your code here.
    // --------------------------------------------------------- // 
    int a1, a2;
    cin >> a1 >> a2;
    funct(a1, a2);
    // --------------------------------------------------------- // 

    return 0;
}

