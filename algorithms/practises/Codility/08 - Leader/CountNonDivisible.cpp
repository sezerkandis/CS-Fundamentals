// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingSXHQSF-SJ4/

#include <map>
vector<int> solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    const int N = A.size();

    map<int, int> divisors;

    // Get list of possible divisors, map will sort it
	// This is worst case O( N*log(N) )
	for (const auto &a: A) {
		divisors[a]++;
        //cout << a << ", " << divisors[a] << endl; 
	}

    // Go through and calculate the number of divisors that are missing
    // We know that there are at least N nondivisors present if none
	// of the divisors are present.  Making this +1 so I don't have to use
	// zero based indices
    vector<int> track((2 * N) + 1, N);

    // Generate divisors list
	// This is the Sieve of Eratosthenes method
	for (const auto &d: divisors) 
		for (int i=1; i*d.first <= 2*N; i++) 
			track[i * d.first] -= d.second;

	// Look up nondivisors
    vector<int> nondivisors(N, 0);
	for (int i=0; i<N; i++) 
        nondivisors[i] = track[A[i]];

    return nondivisors;
}