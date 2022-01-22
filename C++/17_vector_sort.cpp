// https://www.hackerrank.com/challenges/vector-sort/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	
    // Enter your code here.
    // --------------------------------------------------------- //	

    int N;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
	}
    // --------------------------------------------------------- //	
	
    return 0;
}