// https://www.hackerrank.com/challenges/drawing-book/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
// Enter your code here.
// --------------------------------------------------------- // 
    const double page_count = n, requested_page = p;
    
	// first pages
    if (requested_page == 1) {
        return 0;
    }
    
	// last pages
    if (int(page_count - requested_page) == 1) {
        return !(int(page_count) %2);
    }
    
	// other pages
    int from_front = ceil((requested_page - 1) / 2.0);
    int from_back = floor((page_count - requested_page) / 2.0);
    return min(from_front, from_back);
// --------------------------------------------------------- // 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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
