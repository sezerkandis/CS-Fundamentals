// https://www.hackerrank.com/challenges/smart-number/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Enter your code here.
// --------------------------------------------------------- //
bool is_smart_number(int num) {
    int val = (int) sqrt(num);
    if(val * val == num)	  // change only this line in code
        return true;
    return false;
}
// --------------------------------------------------------- //

int main() {
    
    int test_cases;
    cin >> test_cases;
    int num;
    for(int i = 0; i < test_cases; i++) {
        cin >> num;
        bool ans = is_smart_number(num);
        if(ans) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}



