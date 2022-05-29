// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// https://app.codility.com/demo/results/trainingHHUNXN-WYR/
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int size = A.size();
    vector<bool> leaves (size, false);
    int leave_count = 0;

    for (uint i = 0; i < size; i++)
    {
        if (leaves[A[i] -1] == false)
        {
            leaves[A[i] - 1] = true;
            leave_count++;
            
            if (leave_count == X)
                return i;
        }
    }

    return -1;
}