#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
//UDUUUDUDDD
int countingValleys(int n, string s)
{
    int level = 0;
    int res = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == 'D')
        {
            --level;
        }
        else if (*it == 'U')
        {
            ++level;
            if (level == 0)
                ++res;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
