// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingT62MH3-2EJ/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    uint size = A.size();
    unsigned long long int sum = 0;
    for (uint i = 0; i < size; i++)
    {
        sum = sum ^ A[i];
        //cout << sum << endl;
    }

    return sum;
}