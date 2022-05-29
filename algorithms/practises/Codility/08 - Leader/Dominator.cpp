// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingNNBZNA-YEQ/

#include <algorithm>
#include <map>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    std::map<int, int> values;
    int N = A.size();
    for (int i = 0; i < N; i++) {
        auto ret = values.insert(std::pair<int, int>(A[i], 1));
        if (ret.second == false)
        {
            auto it = values.find(A[i]);
            if (it != values.end())
                it->second++;
        }
    }

    int maximum = 0;
    int _index = 0;
    for(auto item : values) {
        //cout << "first: " <<item.first << ", second: "<< item.second << endl;
        if (item.second > maximum) {
            maximum = item.second;
            _index = item.first;
        }
    }

    if (maximum < N / 2)
        return -1;

    auto ret = find(A.begin(), A.end(), _index);
    if (ret != A.end())
        return ret - A.begin();
        
    return -1;
}