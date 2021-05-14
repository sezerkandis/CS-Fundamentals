// https://www.hackerrank.com/challenges/arrays-introduction/problem

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
    int arr[N];
    int i=0;
	
    while(i!=N){ 
        cin >> arr[i];
        i++;
    }

    i = N - 1;
    while (i != -1){
        cout << arr[i] << " ";
        i--;
    }
	// --------------------------------------------------------- // 
	
    return 0;
}
