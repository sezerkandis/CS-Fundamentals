// https://www.hackerrank.com/challenges/pangrams/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
string pangrams(string s) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (const char& a : alphabet) {
        if (s.find(a) == std::string::npos && s.find(toupper(a)) == std::string::npos) { 
            return "not pangram";
        }
    }
    return "pangram";
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
