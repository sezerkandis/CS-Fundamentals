// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
//https://app.codility.com/demo/results/trainingRW8YUB-YT9/
#include <cmath>
int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    double difference = Y - X;
    return ceil(difference / D);
}