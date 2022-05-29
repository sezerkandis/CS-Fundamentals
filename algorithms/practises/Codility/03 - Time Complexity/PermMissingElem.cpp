// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingWR4HCQ-JBQ/
#include <numeric>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    unsigned long long int size = A.size();
    unsigned long long int sum = accumulate(A.begin(), A.end(), 0);
    return (((size + 1) * (size + 2)) / 2) - sum;
}
