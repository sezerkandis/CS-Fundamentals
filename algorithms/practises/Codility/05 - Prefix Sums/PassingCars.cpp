// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// https://app.codility.com/demo/results/trainingJC8R4T-XGT/

#include <numeric>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int n = A.size();
    uint num_passing = 0;
    vector<int> P(n, 0);
    partial_sum(A.begin(), A.end(), P.begin());

    for (int i = 0; i < n; i++) {
        //cout << "A["<< i << "]: " << A[i] << ", !A[i]: " << !A[i] << endl; 
        if (A[i] == 0) {
            num_passing += (P[n - 1] - P[i]);
            if (num_passing > 1000000000)
            return -1;
        }
    }

    return num_passing;
}