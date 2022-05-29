// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingGCP82H-SGD/ 
#include <limits>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    double avg = 0;
    long long sum = 0;
    uint N = A.size();
    double min_avg = std::numeric_limits<double>::max();
    uint _index = 0;

    for (uint i = 0; i < 2; i++)
    {
        sum = A[i] + A[i + 1];
        avg = (double)sum / 2;

        if (avg < min_avg)
        {
            min_avg = avg;
            _index = i;
        }
    }
    for (uint i = 2; i < N - 1; i++)
    {
        sum = A[i] + A[i + 1] + A[i + 2];
        avg = (double)sum / 3;

        if (avg < min_avg)
        {
            min_avg = avg;
            _index = i;
        }
    }
    return _index;
}