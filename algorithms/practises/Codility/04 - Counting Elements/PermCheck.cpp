// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
//https://app.codility.com/demo/results/trainingEMCYAW-KAB/
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    uint N = A.size();
    vector<bool> integers(N, false);

    uint exist_count = 0;
    for (uint i = 0; i < N; i++) {
        if (A[i] > N) {
            // cannot be more than size
            return 0;
        }
        if (A[i] > 0 && integers[A[i]] == false) {
            integers[A[i]] = true;
            exist_count++;
        }
        else {
            // already found
            return 0;
        }
    }

    return exist_count == N;
}