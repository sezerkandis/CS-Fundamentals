// https://www.hackerrank.com/challenges/time-conversion/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
string timeConversion(string s) {
    string time = "";
    if (s.size() != 10) {
        return time;
    }
    
    int hour = std::stoi(s.substr(0, 2));
    string rest = s.substr(2, s.size() - 4);
    string format = s.substr(s.size() - 2, s.size() - 1);
    std::transform(format.begin(), format.end(), format.begin(), ::toupper);
        
    hour = format=="AM" && hour == 12 ? (hour + 12) % 24
         : format=="PM" && hour != 12 ? (hour + 12)
         : hour;
        
    time = hour < 10 ? "0" : "";
    time += std::to_string(hour) + rest;
    return time;
}
// --------------------------------------------------------- // 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
