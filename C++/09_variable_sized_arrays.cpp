// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Enter your code here.
    // --------------------------------------------------------- //  

    int n, q;
    cin >> n >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> a[n];

    for (int arrayIndex = 0; arrayIndex < n; arrayIndex++)
    {
        int k;    
        cin >> k;

        int tmp;
        for (int i = 0; i < k; i++)
        {   
            cin >> tmp;
            a[arrayIndex].push_back(tmp);
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        int size = sizeof(a[i]) / sizeof(a[i][0]);
        for (int j = 0; j < size; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }*/

    for (int queryIndex = 0; queryIndex < q; queryIndex++)
    {        
        int i, j;
        cin >> i >> j;
        cout << a[i][j] << endl;
    }        
    // --------------------------------------------------------- //  

    return 0;
}

