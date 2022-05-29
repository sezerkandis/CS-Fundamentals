// https://www.hackerrank.com/challenges/bitset-1/

##include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	// Enter your code here.
	// --------------------------------------------------------- // 
    const unsigned long long po = pow(2, 31);
    unsigned long long N,S,P,Q;
    unsigned long long count = 0;
    cin >> N >> S >> P >> Q;
    unsigned long long i, a0=S, a=S, ap=0;

    for(i=0; i<N; i++){
        a=(a*P+Q);
        a=a%po;
        
        if((a == a0 || a == ap) && i != 0){
            count = i + 1;
            break;
        }
        ap=a;
    }
    if (i == N) {
        count = i;
    }

    cout << count <<endl;
	// --------------------------------------------------------- // 	
    return 0;
}