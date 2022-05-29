// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingY9VK93-QEA/
#include <numeric>
#include <unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    return std::unordered_set<int>(A.begin(), A.end()).size();
}