// https://www.hackerrank.com/challenges/30-regex-patterns/
   
#include <bits/stdc++.h>

using namespace std;

// Enter your code here.
// --------------------------------------------------------- //
#include <map>
#include <set>
// --------------------------------------------------------- //

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Enter your code here.
// --------------------------------------------------------- //
inline bool ends_with(std::string const& value, std::string const& ending)
{
    if (ending.size() > value.size()) {
        return false;
    }
    
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
// --------------------------------------------------------- //

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    std::map<std::string, std::string> emails;
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
        string firstName = first_multiple_input[0];
        string emailID = first_multiple_input[1];
        
// Enter your code here.
// --------------------------------------------------------- //
        if (firstName.size() > 0 && firstName.size() <= 20) {
            if (emailID.size() > 0 && emailID.size() <= 50) {
                if (ends_with(emailID, "@gmail.com")) {
                    emails[emailID] = firstName;
                }
            }
        }
    }
    
    std::vector<std::string> names;
    std::for_each(emails.begin(), emails.end(), [&](auto it){ names.push_back(it.second); });
    std::sort(names.begin(), names.end());
    for (const auto name : names) {
        std::cout << name << std::endl;
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
