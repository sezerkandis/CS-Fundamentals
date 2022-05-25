// https://www.hackerrank.com/challenges/30-2d-arrays/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main()
{
    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }
    
// Enter your code here.
// --------------------------------------------------------- // 
    int max_sum = 0, sum = 0;
    const int hourglass_dimension = 4;
    std::vector<int> sums (pow(hourglass_dimension, 2), 0);
    for (int x = 0; x < hourglass_dimension; x++) {;
        for (int y = 0; y < hourglass_dimension; y++) {
            sum += arr[0+x][0+y] + arr[0+x][1+y] + arr[0+x][2+y];
            sum +=                 arr[1+x][1+y];
            sum += arr[2+x][0+y] + arr[2+x][1+y] + arr[2+x][2+y];
            sums[x * hourglass_dimension + y] = sum;
            sum = 0;
        }
    }
    std::cout << *std::max_element(sums.begin(), sums.end()) << std::endl;
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
