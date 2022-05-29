// https://www.hackerrank.com/challenges/30-scope/
   
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
private:
    vector<int> elements;
  
public:
  	int maximumDifference;

// Enter your code here.
// --------------------------------------------------------- // 
    Difference(std::vector<int> e) {
        elements.assign(e.begin(), e.end());
        maximumDifference = 0;
    }
    void computeDifference () {
        for (int i = 0; i < elements.size() - 1; i++) {
            for (int j = i; j < elements.size(); j++) {
                int diff = abs(elements[i] - elements[j]);
                maximumDifference = max(maximumDifference, diff);
            }
        }
    }
// --------------------------------------------------------- // 
}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}