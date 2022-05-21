// https://www.hackerrank.com/challenges/camelcase/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
// Enter your code here.
// --------------------------------------------------------- // 
int camelcase(string s) {
    if (s.size() == 0) {
        return 0;
    }    
    return std::count_if(s.begin(), s.end(), [](char c){ return isupper(c); }) + 1;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
