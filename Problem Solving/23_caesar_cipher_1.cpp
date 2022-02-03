// https://www.hackerrank.com/challenges/caesar-cipher-1/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
 
// Enter your code here.
// --------------------------------------------------------- // 
#include <cctype>
#include <cstring>
string caesarCipher(string s, int k) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::unordered_map<char, unsigned int> chars;
    for(unsigned int i = 0; i < alphabet.size(); i++) {
        chars[alphabet[i]] = i;
    }
    
    for (unsigned int i = 0; i < s.size(); i++) {
        if (alphabet.find(tolower(s[i])) != std::string::npos) {
            unsigned int offset = (chars[tolower(s[i])] + k) % alphabet.size();
            s[i] = isupper(s[i]) ? toupper(alphabet[offset]) : alphabet[offset];
        }
    }
    return s;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

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
