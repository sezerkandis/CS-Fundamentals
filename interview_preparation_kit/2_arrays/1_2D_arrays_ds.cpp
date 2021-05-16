// https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr) { 
    // Enter your code here.
    // --------------------------------------------------------- //  
    /*
    arr.clear();
    arr = vector<vector<int>> {
        {-9, -9, -9, 1, 1, 1},
        {-9, -9, -9, 1, 1, 1},
        { 0, -9,  0, 4, 3, 2},
        {-9, -9, -9, 1, 2, 3},
        { 0,  0,  8, 6, 6, 0},
        { 0,  0,  0,-2, 0, 0},
        { 0,  0,  1, 2, 4, 0}
    }; 
    // printing matris
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
       }
       cout << endl;
    }
    
    // pattern should be like;
    // 00 01 02, 11, 20 21 22 (ignoring: 10, 12)
    // 01 02 03, 12, 21 22 23 (ignoring: 11, 13)
    // 02 03 04, 13, 22 23 24 (ignoring: 12, 14)
    // 03 04 05, 14, 23 24 25 (ignoring: 13, 15)
    // 10 11 12, 21, 30 31 32 (ignoring: 20, 22)
    // ...
    // ...  
        
    // expected output
    // -63, -34, -9, 12, 
    // -10,   0, 28, 23, 
    // -27, -11, -2, 10, 
    // 9,  17, 25, 18
    */
        
    const int pattern_size = 3;
    int N = arr.size();
    int T = N - (pattern_size - 1);
    int H = pow(T, 2);
    vector<int> hourglass(H);
    int max = INT_MIN;
    
    int c_offset = 0, r_offset = 0;
    int i = 0, r = 0, c = 0;
    for (i = 0; i < H; i++) {
        int sum = 0;
        int index = 0;
        for (r = 0; r < pattern_size; r++) {
            for (c = 0; c < pattern_size; c++) {
                if (index != pattern_size && index != pattern_size + 2) {
                    sum += arr[r + r_offset][c + c_offset];
                    //cout << c + c_offset << "" << r + r_offset << " ";
                }
                index++;
            }
        }
        c_offset++;
        c_offset %= T;
        if (c_offset == 0) {
            r_offset++;
            r_offset %= T;
        }
        if (sum > max) {
            max = sum;
        } 
        hourglass[i] = sum;
        //cout << endl;
    }
    
    // printing results
    /*for (int h = 0; h < hourglass.size(); h++) {
        if (h != 0 && h%T == 0)
            cout << endl;            
        cout << hourglass[h] << " ";
    }*/
    
    return max;
    // --------------------------------------------------------- //  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = hourglassSum(arr);

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
