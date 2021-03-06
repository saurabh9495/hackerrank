// Arrange Students

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrangeStudents' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

// 1 2 2 7
// 2 4 6 8

string arrangeStudents(vector<int> a, vector<int> b)
{
    vector<int> v;
    bool flag;
    sort(a.begin(), a.end()); // boys
    sort(b.begin(), b.end()); // girls

    auto aj = a.begin();
    auto bj = b.begin();
    for (; aj != a.end(), bj != b.end(); aj++, bj++)
    {
        if (*aj == *bj)
        {
            continue;
        }
        if (*aj < *bj)
        {
            flag = true;
            break;
        }
        if (*bj < *aj)
        {
            flag = false;
            break;
        }
    }

    auto ai = a.begin();
    auto bi = b.begin();
    for (; ai != a.end(), bi != b.end(); ai++, bi++)
    {
        if (flag)
        {
            v.push_back(*ai);
            v.push_back(*bi);
            cout << *ai << " " << *bi << " ";
        }
        else
        {
            v.push_back(*bi);
            v.push_back(*ai);
            cout << *bi << " " << *ai << " ";
        }
    }

    if (is_sorted(v.begin(), v.end()))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split(rtrim(b_temp_temp));

        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            int b_item = stoi(b_temp[i]);

            b[i] = b_item;
        }

        string result = arrangeStudents(a, b);

        fout << result << "\n";
    }

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
