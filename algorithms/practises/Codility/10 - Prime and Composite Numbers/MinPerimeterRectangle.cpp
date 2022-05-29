// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingGMNCP8-D5S/

#include <cmath>
#include <limits>
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int root_n = sqrt(N);
    int min_perimeter = std::numeric_limits<int>::max();
    for (int i = 1; i <= root_n; i++)
    {
        if (N%i != 0)
            continue;

        int b = N / i; // a = i
        int perimeter = 2 * (i + b);
        if (perimeter < min_perimeter)
            min_perimeter = perimeter;
    }

    return min_perimeter;
}

