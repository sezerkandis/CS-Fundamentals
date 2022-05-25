// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <unordered_map>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
// Enter your code here.
// --------------------------------------------------------- // 
    int n; std::cin >> n;
    std::string key, value;
    std::unordered_map<std::string, std::string> phone_numbers;
    for (int i = 0; i < n; i++) {
        std::cin >> key >> value;
        phone_numbers[key] = value;
    }
    
    while(std::cin >> key) {
        std::string status = phone_numbers.count(key) == 0 ? "Not found" : key + "=" + phone_numbers[key];
        std:cout << status << std::endl;
    }
// --------------------------------------------------------- // 
    return 0;
}
