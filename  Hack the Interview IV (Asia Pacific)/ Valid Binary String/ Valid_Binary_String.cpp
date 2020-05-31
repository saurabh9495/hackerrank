// Valid Binary String

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER d
 */

// 0 0 0 1
int minimumMoves(string s, int d)
{
    int k = 0, ctr1 = 0, ctr2 = 0;
    for (auto it = s.begin(); it != s.end(); it++, k++)
    {
        if (s[k] == '1')
        {
            ctr1 = 0;
        }
        if (s[k] == '0')
        {
            ctr1++;
            if (ctr1 == d)
            {
                ctr2++;
                ctr1 = 0;
            }
        }
    }
    return ctr2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string d_temp;
    getline(cin, d_temp);

    int d = stoi(ltrim(rtrim(d_temp)));

    int result = minimumMoves(s, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
