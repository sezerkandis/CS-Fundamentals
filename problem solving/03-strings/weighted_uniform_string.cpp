// https://www.hackerrank.com/challenges/weighted-uniform-string/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

// Enter your code here.
// --------------------------------------------------------- //
vector<string> weightedUniformStrings(string s, vector<int> queries) {    
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::unordered_map<char, unsigned int> chars;
    for (int i = 0; i < alphabet.size(); i++) {
        chars[alphabet[i]] = i + 1; 
    }
    
    unsigned int repeated = 1;
    std::unordered_set<unsigned int> weights { chars[s[0]] };
    for (int i = 1; i < s.size(); i++) {
        bool is_equal = s[i] == s[i - 1];
        repeated = is_equal ? repeated + 1 : 1;
        weights.insert(is_equal ? repeated * chars[s[i]] : chars[s[i]]);
    }
    
    // std::copy(weights.begin(), weights.end(), std::ostream_iterator<unsigned int>(std::cout, " "));
            
    std::vector<std::string> result;
    for (auto& q : queries) {
        result.push_back(weights.find(q) != weights.end() ? "Yes" : "No");
    }
    return result;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
