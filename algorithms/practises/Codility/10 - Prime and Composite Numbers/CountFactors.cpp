// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/training3DNPKU-UT2/
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int i = 1;
    int count = 0;
    while (i * i <= N) {
        if (N % i == 0) {
            count++;
            if (N / i != i)
                count ++;
        }
        i++;
    }
    return count;
}