// https://www.hackerrank.com/challenges/cpp-lower-bound/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Enter your code here.
    // --------------------------------------------------------- // 
    int size = 0;
    std::cin >> size;
    std::vector<int> v;
    for (int i = 0; i < size; i++) {
        int value = 0;
        std::cin >> value;
        v.push_back(value);
        // std::cout << "added " << value << " to vector" << std::endl;
    }
    
    // printing vector elements for checking
    // for (int i = 0; i < size; i++) {
    //     std::cout << v[i] << ", ";
    // }
    // std::cout << std::endl;
    
    int query_count = 0;
    std::cin >> query_count;
    for (int i = 0; i < query_count; i++) {
        int value = 0;
        std::cin >> value;
        // std::cout << "searching " << value << " ";
        std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), value);
        int index = it - v.begin();
        std::string exist = index == size || v[index] != value ? "No " : "Yes ";
        std::cout << exist << std::to_string(index + 1) << std::endl;
    }
    // --------------------------------------------------------- // 
    
    return 0;
}
