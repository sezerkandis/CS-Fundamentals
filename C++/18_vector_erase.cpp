// https://www.hackerrank.com/challenges/vector-erase/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    // Enter your code here.
    // --------------------------------------------------------- //	

    int n;
    cin >> n;

    vector<int> v;
    while(n--) {
        int a;
        cin >> a;
        v.push_back(a); 
    }

    int position;
    cin >> position;
    v.erase(v.begin() + position - 1);

    int startIndex, endIndex;
    cin >> startIndex >> endIndex;
    v.erase(v.begin() + startIndex - 1, v.begin() + (endIndex - 1));

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
	
    // --------------------------------------------------------- //	

    return 0;
}
