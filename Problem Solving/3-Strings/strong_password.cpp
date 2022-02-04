// https://www.hackerrank.com/challenges/strong-password/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

// Enter your code here.
// --------------------------------------------------------- // 
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    if (n < 2) {
        return 6 - n;
    }
        
    const std::string specials = "!@#$%^&*()-+";
    std::map<string, bool> cases;
    for (const char& c : password) {
        if (cases.count("digit") == 0 && isdigit(c)) {
            cases["digit"] = true;
        }
        if (cases.count("lower") == 0 && islower(c)) {
            cases["lower"] = true;
        }
        if (cases.count("upper") == 0 && isupper(c)) {
            cases["upper"] = true;
        }
        if (std::find(specials.begin(), specials.end(), c) != specials.end()) {            
            cases["special"] = true;
        }        
        if (cases.size() == 4) {
            break;
        }
    }
    
    const int remainings = 4 - cases.size();
    return password.size() + remainings < 6 ? 6 - password.size() : remainings;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
