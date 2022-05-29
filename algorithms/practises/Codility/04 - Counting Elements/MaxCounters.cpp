// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// https://app.codility.com/demo/results/trainingC2274P-A6G/
vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    uint M = A.size();              // M = 6
    vector<int> counters(N, 0);     // N = 5
    int minimum = 0, maximum = 0;

    for (uint k = 0; k < M; k++)
    {
        if (A[k] <= N)
        {
            int index = A[k] - 1;
            int counter = std::max(counters[index], minimum) + 1;
            counters[index] = counter;

            if (counter > maximum)
                maximum = counter;

            //cout << "A[k] <= N --> A[" << k << "]: " << A[k] << ", N: " << N << endl; 
        }
        else if (A[k] == N + 1)
        {
            minimum = maximum; // to set all to maximum with std::max;
            //cout << "A[k] == N --> A[" << k << "]: " << A[k] << ", N: " << N << endl; 
            //cout << "minimum changed: " << minimum << endl;
        }
    }

    for (uint k = 0; k < N; k++)
        counters[k] = std::max(counters[k], minimum);

    //for (uint i = 0; i < N; i++)
    //    cout << counters[i] << ", "; 
    //cout << endl;

    return counters;

}
