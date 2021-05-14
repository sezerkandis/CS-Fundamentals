// https://www.hackerrank.com/challenges/c-tutorial-strings/problem

#include <iostream>
#include <string>
using namespace std;

int main() {	
	// Enter your code here.
	// --------------------------------------------------------- //    
    string a, b;
    cin >> a >> b;

    cout << a.size() << " " << b.size() << endl;
    cout << a + b << endl;

    char first_a = a[0];
    a[0] = b[0];
    b[0] = first_a;
    cout << a << " " << b << endl;
	// --------------------------------------------------------- //

    return 0;
}

