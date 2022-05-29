// https://www.hackerrank.com/challenges/strings-xor/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Enter your code here.
// --------------------------------------------------------- //
string strings_xor(string s, string t) 
{
    string res = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == t[i])	// change this line 
            res += '0';		// change this line 
        else
            res += '1';		// change this line 
    }
    return res;
}
// --------------------------------------------------------- //

int main() {
    string s, t;
    cin >> s >> t;
    cout << strings_xor(s, t) << endl;
    return 0;
}