// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/training9KKAB3-F8F/
vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)

    int size = A.size();
    vector<int> shifted(size, 0);

    if (size == 0)
        return shifted; 

    int index = K % size ? size - (K % size) : 0;

    for (int i = 0; i < size; i++)
    {
        shifted.at(i) = A.at(index);
        index = (index + 1) % size;
    }   

    return shifted;
}
