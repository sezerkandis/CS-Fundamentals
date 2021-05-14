// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Enter your code here.
    // --------------------------------------------------------- //    
    stringstream ss(str);
    vector<int> result;
    string token;
	
    while(std::getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }

    return result;
    // --------------------------------------------------------- // 
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

