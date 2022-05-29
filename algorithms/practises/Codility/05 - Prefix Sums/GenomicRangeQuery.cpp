// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// https://app.codility.com/demo/results/training2RN3MP-QFM/
class DNA_PART
{
public:
    const int index;
    const char character;
    DNA_PART(int i, int N, char c) : 
        index{i}, character{c}
    {
        VAL = vector<int>(N, -1);
        //cout << "DNA part created: " << i << ", " << N << ", " << c << endl;
    }
    vector<int> VAL;
};

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<DNA_PART> dnas;
    int N = S.size();
    vector<char> chars { 'A', 'C', 'G', 'T' };
    int char_size = int(chars.size());
    for (int i = 1; i <= char_size; i++)
        dnas.push_back(DNA_PART(i, N, chars[i - 1]));
    
    for (int n = 0; n < N; n++) 
        for (int i = 0; i < char_size; i++) 
            if (S[n] == dnas[i].character) {
                dnas[i].VAL[n] = n;
                //cout << "equal dna[" << i << "].VAL[" << n << "] = " << n << endl;
            }

    int M = P.size();
    vector<int> result (M, 0);

    for (int m = 0; m < M; m++) {
        int l = P[m];
        int r = Q[m];

        for (int i = 0; i < char_size; i++)
            if (dnas[i].VAL[r] >= l)
                result[m] = dnas[i].index;
    }

    return result;
}