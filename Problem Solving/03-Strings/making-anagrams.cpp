// https://www.hackerrank.com/challenges/making-anagrams/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

// Enter your code here.
// --------------------------------------------------------- //
int makingAnagrams(string s1, string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    
    // mapping characters
    std::map<char, unsigned int> s1_keys, s2_keys;
    for (const char& c : s1) {
        s1_keys[c]++;
    }
    for (const char& c : s2) {
        s2_keys[c]++;
    }
    
    // removing common characters
    for (const auto& c : s1_keys) {
        if (s2_keys[c.first] > 0) {
            int min = std::min(c.second, s2_keys[c.first]);
            s1_keys[c.first] -= min;
            s2_keys[c.first] -= min;
        }
    }
    
    int count = 0;
    // counting differences
    for (const auto& c : s1_keys) {
        count += c.second;
    }
    for (const auto& c : s2_keys) {
        count += c.second;
    }
    return count;
}
// --------------------------------------------------------- //

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
