// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // Enter your code here.
    // --------------------------------------------------------- //
    map<std::string, int> students;
    int size = 0;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int query = 0;
        std::string name = "";
        cin >> query;
        cin >> name;
        if (query == 1){
            int point = 0;
            cin >> point;
            students[name] += point;
        }
        else if (query == 2) {
            students.erase(name);
        }
        else if (query == 3) {
            if (students.find(name) != students.end()) {
                std::cout << students[name] << std::endl;
            }
            else {
                std::cout << "0" << std::endl;
            }
        }
    }
    // --------------------------------------------------------- //
      
    return 0;
}