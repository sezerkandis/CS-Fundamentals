#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
int gemstones(vector<string> arr) {
    if (arr.size() == 0) {
        return 0;
    }
    
    int min_length = arr.at(0).size();
    std::map<unsigned int, std::vector<std::string>> words;
    for (const std::string& s : arr) { 
        words[s.size()].push_back(s);
        if (min_length > s.size()) {
            min_length = s.size();
        }
    }
    
    std::vector<char> gemstones;
    std::map<char, unsigned int> checkeds;    
    for (const char& c : words[min_length].at(0)) {
        if (checkeds.count(c) != 0) {
            continue;
        }
        
        checkeds[c]++;
        if (std::count_if(arr.begin(), arr.end(), [&](const std::string& word){ return std::find(word.begin(), word.end(), c) != word.end(); }) == arr.size()) {
            gemstones.push_back(c);
        }
    }    
    return gemstones.size();
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
