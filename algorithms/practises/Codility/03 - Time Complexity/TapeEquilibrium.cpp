

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingQU9BDU-HR9/
#include <limits>
#include <cmath>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    uint size = A.size();
    long long sum = 0; 
    vector<long long > sums; 
    for (uint i = 0; i < size; i++)
    {
        sum += A[i];
        sums.push_back(sum);
    }

    //cout << "sum: " << sum << endl;
    long long max = std::numeric_limits<long long>::max(); // LONG_MAX in limits.h
    //cout << "max: " << max << endl;

    for (uint i = 0; i < size - 1; i++)
    {        
        long long difference = abs(sums[i] - (sum - sums[i]));
        //cout << "sums[i]: " << sums[i] << endl;
        //cout << "difference: " << difference << endl;

        if (difference < max)
            max = difference;
    }

    return max;
}