// Repeated String

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    ll ans = 0;
    int A = 0;
    int B = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
       if (s[i] == 'a') A++;
       if ((ll)i < n % (ll)s.size() && s[i] == 'a') B++;
    }

    ll str =  n / (ll)s.size() * (ll)A + (ll)B;
    return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
