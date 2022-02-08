// https://www.hackerrank.com/challenges/anagram/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
int anagram(string s) {
    if (s.size() == 0 || s.size() %2 == 1) {
        return -1;
    }
    
    std::string s_left = s.substr(0, s.size() / 2);
    std::string s_right = s.substr(s.size() / 2, s.size() / 2);
    std::sort(s_left.begin(), s_left.end());
    std::sort(s_right.begin(), s_right.end());
    
    if (s_left == s_right) {
        return 0;
    }
    
    int count = 0;
    for (const char& c : s_left) {
        auto it = std::find(s_right.begin(), s_right.end(), c);
        if (it != s_right.end()) {
            s_right.erase(it - s_right.begin(), 1);
        }
        else {
            count++;
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

        int result = anagram(s);

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
