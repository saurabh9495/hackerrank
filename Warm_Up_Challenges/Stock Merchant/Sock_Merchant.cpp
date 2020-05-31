// Sock Merchant

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//after_sorting
// 10 10 10 10 20 20 20 30 50
// 1 1 1 1 2 3 3 3 3 3

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar)
{
    sort(ar.begin(), ar.end());
    int ctr1 = 0, ctr2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (ar[i] == ar[i + 1])
        {
            ctr1++;
        }
        else
        {
            ctr1++;
            int temp = ctr1 / 2;
            ctr2 += temp;
            ctr1 = 0;
        }
    }
    ctr1++;
    ctr2 += ctr1 / 2;
    return ctr2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++)
    {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
