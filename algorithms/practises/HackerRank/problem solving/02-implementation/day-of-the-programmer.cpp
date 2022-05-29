// https://www.hackerrank.com/challenges/day-of-the-programmer/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
string dayOfProgrammer(int year) {
    int day = 12;
    const int month = 9;
    if (year >= 1700 && year < 1918) {
        day += year %4 == 0 ? 0 : 1;
    }
    else if (year > 1918 && year <= 2700){
        day += (year %4 == 0 && year %100 != 0) || year %400 == 0 ? 0 : 1;
    }
    else {
        day = 26;
    }
    std::string s_day = day > 9 ? std::to_string(day) : "0" + std::to_string(day);
    const string s_month = "09";
    return s_day + "." + s_month + "." + std::to_string(year);
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
