// Number Of Integers , Only Template

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getNumberOfIntegers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING L
 *  2. STRING R
 *  3. INTEGER K
 */

int getNumberOfIntegers(string L, string R, int K) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string L;
    getline(cin, L);

    string R;
    getline(cin, R);

    string K_temp;
    getline(cin, K_temp);

    int K = stoi(ltrim(rtrim(K_temp)));

    int ans = getNumberOfIntegers(L, R, K);

    fout << ans << "\n";

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
