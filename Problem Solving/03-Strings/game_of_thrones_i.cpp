// https://www.hackerrank.com/challenges/game-of-thrones/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
string gameOfThrones(string s) {
    std::unordered_map<char, unsigned int> chars;
    for (int i = 0; i < s.size(); i++) {
        chars[s[i]]++;
    }
    
    unsigned int count = std::count_if(chars.begin(), chars.end(), [&](const std::pair<char, unsigned int>& p){ return p.second %2 != 0; });
    return count <= 1 ? "YES" : "NO";
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
