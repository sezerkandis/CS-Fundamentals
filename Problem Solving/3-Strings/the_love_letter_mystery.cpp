// https://www.hackerrank.com/challenges/the-love-letter-mystery/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'theLoveLetterMystery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
int theLoveLetterMystery(string s) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::unordered_map<char, unsigned int> chars;
    for (int i = 0; i < alphabet.size(); i++) {
        chars[alphabet[i]] = i; 
    }
    
    int count = 0;
    char first, second;
    for (int i = 0; i < s.size() / 2; i++) {
        first = s[i], second = s[s.size() - 1 - i];
        if (first != second) {
            count += abs(int(chars[first] - chars[second]));
        }
    }
    return count;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
