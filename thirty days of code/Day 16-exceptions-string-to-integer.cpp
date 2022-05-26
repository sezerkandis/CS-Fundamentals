// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/
   
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    getline(cin, S);
// Enter your code here.
// --------------------------------------------------------- // 
    try {
        int s = stoi(S);
        std::cout << s << std::endl;
    } catch (...) {
        std::cout << "Bad String" << std::endl;
    }
// --------------------------------------------------------- // 
    return 0;
}
