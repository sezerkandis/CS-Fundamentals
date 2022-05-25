// https://www.hackerrank.com/challenges/30-binary-numbers/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
// Enter your code here.
// --------------------------------------------------------- // 
    std::string str = std::bitset<32>(n).to_string() + "0";
    int count = 0, max_count = 0;
    for (const char& c : str) {
        if (c == '1') {
            count++;
        }
        else {
            max_count = max(max_count, count);
            count = 0;
        }
    }
    std::cout << max_count << std::endl;
// --------------------------------------------------------- // 
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
