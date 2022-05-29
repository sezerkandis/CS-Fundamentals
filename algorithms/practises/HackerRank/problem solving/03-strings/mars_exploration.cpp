#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// Enter your code here.
// --------------------------------------------------------- // 
int marsExploration(string s) {
    int count = 0;
    const std::string default_key = "SOS";
    for (int wIndex = 0; wIndex < s.size(); wIndex+=3) {
        std::string sos = s.substr(wIndex, 3);
        unsigned i = -1;
        count += std::count_if(sos.begin(), sos.end(), [&](const char& c){ i++; return c != default_key[i]; });       
    }
    return count;
}
// --------------------------------------------------------- //

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
