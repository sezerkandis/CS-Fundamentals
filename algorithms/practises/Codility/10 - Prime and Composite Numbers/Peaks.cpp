// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingZQZJA6-ZE8/

#include <iterator>
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = A.size();
    if (N < 3)
        return 0;

    // detecting factors...
    int i = 1;
    vector<int> factors;
    while(i * i < N)
    {
        if (N %i == 0)
        {
            factors.push_back(i);
            //cout << "add to factors at (i) " << i << endl;
            if (N/i != i) {
                factors.push_back(N / i);
                //cout << "add to factors at (N / i) " << N / i << endl;
            }
        }
        i++;
    }

    if (i * i == N) {
        factors.push_back(i);
        //cout << "add to factors at (i*i) " << i << endl;
    }

    // detecting peak points...
    sort(factors.begin(), factors.end());
    vector<bool> peaks(N, false);
    int peak_count = 0;
    for (int j = 1; j < N -1; j++)
    {
        if (A[j] > A[j - 1] && A[j] > A[j + 1])
        {
            peaks[j] = true;
            peak_count++;
            //cout << "peak found at " << j << ", value: " << A[j] << endl;
        }
    }
    if (peak_count <= 1)
        return peak_count;

    vector<int> pre_sum_peaks;
    int ss = 0;
    for (auto j: peaks)
    {
        ss += j;
        pre_sum_peaks.push_back(ss);
        //cout << "added to pre_sum_peaks: " << ss << ", peak: " << j << endl;
    }

    int factor_size = factors.size();
    for (int j = 1; j < factor_size; j++) 
    {
        bool no_peak = false;
        for (int k = 0; k < N; k += factors[j]) 
        {
            int start_s = (k == 0) ? 0 : pre_sum_peaks[k - 1];
            if (pre_sum_peaks[k + factors[j] - 1] - start_s == 0)  
            {
                no_peak = true;
                //cout << "no peak!" << endl;
                break;    
            }
        }
        if (!no_peak) {
            return N / factors[j];     
            //cout << "yes peak: " << N / factors[j] << endl;   
        }    
    }

    cout << "factor size: " << factors.size() << endl;
    return 0;
}