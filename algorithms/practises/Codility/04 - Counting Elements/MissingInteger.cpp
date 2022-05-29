// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// https://app.codility.com/demo/results/trainingMVZNRN-2H2/
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    const int max = 1000001;
    if (max < 0)
        return 1;

    uint N = A.size();
    vector<bool> integers(max, false);
    for (int i = 0; i < N; i++)
        if (A[i] > 0)
            integers[A[i]] = true;

    for (uint i = 1; i < max; i++)
        if (integers[i] == false)
            return i;

    return 1;
} 

