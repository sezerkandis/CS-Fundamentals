// https://www.hackerrank.com/challenges/palindrome-index/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
bool isPalindrome(const std::string& s) {
    if (s.size() < 2) {
        return true;
    }    
    int offset = s.size() % 2;
    std::string right_part = s.substr((s.size() / 2) + offset, s.size() / 2);
    std::reverse(right_part.begin(), right_part.end());
    return s.substr(0, s.size() / 2) == right_part;
}

int palindromeIndex(string s) {
    int result = -1, lentgh = s.size();
    if (isPalindrome(s)) {
        return result; 
    }
    
    for (int i = 0; i <= lentgh / 2; i++) {
        if (s[i] != s[lentgh - i - 1]) {
            s.erase(s.begin() + i);
            return isPalindrome(s) ?  i : lentgh - i - 1;
        }
    }
    return result;
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

        int result = palindromeIndex(s);

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
