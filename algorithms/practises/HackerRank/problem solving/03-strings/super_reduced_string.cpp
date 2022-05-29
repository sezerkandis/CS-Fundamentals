// https://www.hackerrank.com/challenges/reduced-string/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
string superReducedString(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            s.erase(i - 1, 2);
            i-=2;
        }
    }
    return s.size() == 0 ? "Empty String" : s;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}