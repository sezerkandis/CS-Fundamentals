#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'rotLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER d
 */

vector<int> rotLeft(vector<int> a, int d) {
    // Enter your code here.
    // --------------------------------------------------------- //  
    // unlocked test case 3
    // d = 48;    
    // a = vector<int> {431, 397, 149, 275, 556, 362, 852, 789, 601, 357, 516, 575, 670, 507, 127, 888, 284, 405, 806, 27, 495, 879, 976, 467, 342, 356, 908, 750, 769, 947, 425, 643, 754, 396, 653, 595, 108, 75, 347, 394, 935, 252, 683, 966, 553, 724, 629, 567, 93, 494, 693, 965, 328, 187, 728, 389, 70, 288, 509, 252, 449};
    
    int rotation_count = d % a.size();
    if (rotation_count == 0)
        return a;
    
    int difference = a.size() - rotation_count;
    vector<int> buffer;
    for (int i = 0; i < rotation_count; i++) {
        buffer.push_back(a[i]);
    }
    for (int i = rotation_count; i < a.size(); i++) {
        a[i - rotation_count] = a[i];
    }
    for (int i = 0; i < buffer.size(); i++) {
        a[i + difference] = buffer[i];
    }
    
    // expected output for test case 3
    // 93 494 693 965 328 187 728 389 70 288 509 252 449 431 397 149 275 556 362 852 789 601 357 516 575 670 507 127 888 284 405 806 27 495 879 976 467 342 356 908 750 769 947 425 643 754 396 653 595 108 75 347 394 935 252 683 966 553 724 629 567
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }
    
    return a;
    // --------------------------------------------------------- // 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
