// https://www.hackerrank.com/challenges/30-review-loop/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
// Enter your code here.
// --------------------------------------------------------- // 
    int N; cin >> N;
    while(N) {
        std::string S; std::cin >> S;
        std::vector<string> keywords {"", ""};
        for (int i = 0; i < S.size(); i++) {
            int index = i%2;
            keywords[index] += S[i];
        }
        std::cout << keywords[0] << " " << keywords[1] << std::endl;
        N--;
    }
// --------------------------------------------------------- // 
    return 0;
}
