// https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    // Enter your code here.
    // --------------------------------------------------------- //
    int size = 0;
    std::cin >> size;
    set<int> list;
    for (int i = 0; i < size; i++) {
        int index = 0, value = 0;
        cin >> index >> value;
        
        if (index == 1 && list.find(value) == list.end()) {
            list.insert(value);
        }
        else if (index == 2 && list.find(value) != list.end()) {
            list.erase(value);
        }
        else if (index == 3) {
            std::string exist = list.find(value) != list.end() ? "Yes" : "No";
            std::cout << exist << std::endl;
        }
    }   
    // --------------------------------------------------------- //
    
    return 0;
}