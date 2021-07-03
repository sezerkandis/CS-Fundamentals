// https://www.hackerrank.com/challenges/deque-stl/problem

#include <iostream>
#include <deque> 
#include <limits> 
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> q;
    for(int i = 0; i < n; i++)
    {
        while(!q.empty() && arr[i] > q.back()) {
            //cout << "q.pop_back -> arr[" << i << "]: " << arr[i] << ", q.back(): " << q.back() << endl;
            q.pop_back();  
        }
            
        q.push_back(arr[i]);  
        if(i >= k && q.front() == arr[i - k]) {
            //cout << "q.pop_front -> q.front(): " << q.front() << ", arr[" << i << " - " << k << "]: " << arr[i - k] << endl;
            q.pop_front(); 
        } 
        if(i >= k - 1) {
            printf(i < n-1 ? "%d ":"%d\n", q.front());
        }
    }
    /* SLOWER WAY 
    for (int i = 0; i < n - k + 1; i++) {
        int max = INT32_MIN;
        for (int j = i; j < i + k; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
        }
        std::cout << max << " "; 
    }
    std::cout << std::endl; */
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int arr[n];
    	for(int i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}