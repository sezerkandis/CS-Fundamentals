// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/training4XRRNM-J4P/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = A.size();
    if (N < 3)
        return 0;

    vector<int> peaks;
    for (int i=1; i<N - 1; i++) {
        if ((A[i] > A[i-1]) && (A[i] > A[i+1])) {
            peaks.push_back(i);
            //cout << "hill[" << i <<"]: " << A[i] << endl;
            i++;
        }
    }

    int peak_size = peaks.size();
    if (peak_size <= 1)
        return peak_size;

    int ret = 0;
    for (int  f = 2; f* (f-1) <= N; f++)
    {
        int indP = 1;
        int setFlags = f - 1;
        int lastP = 0;

        while (indP < peak_size && setFlags > 0)
        {
            if (peaks[indP] - peaks[lastP] >= f)
            {
                lastP = indP;
                setFlags--;
            }
            indP++;
        }
        if (setFlags == 0)
            ret = f;
    }

    return ret;
}