//Optimal Network Routing and some code base, (not working)

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinEffort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY C as parameter.
 */

// 3 4

// 12(6,6), 6(1,7) 5(2,2) 3 
// 6(7,2) 13(10,11) 3(12,3) 15 
// 8 2 6 9 

int getMinEffort(vector<vector<int>> vect) {
    set<int> s;
    // auto ai = a.begin(); 
    // auto bi = b.begin();
    // for(;ai!=a.end(),bi!=b.end();ai++,bi++){     
    //     if(flag){
    //         v.push_back(*ai);
    //         v.push_back(*bi);
    //         cout << *ai << " "<< *bi <<" ";
    //     }
    //     else{
    //         v.push_back(*bi);
    //         v.push_back(*ai);
    //         cout << *bi << " "<< *ai << " ";
    //     }   
    // }
    int a=0;b=0,temp=0;
    set<pair<int, int>> S;
    int i=0,j=0;
    for (i = 0; i < vect.size()-1; i++) { 
        for (j = 0; j < vect[i].size()-1; j++) {
            a = abs(vect[i][j] - vect[i][j+1]);
            b = abs(vect[i][j] - vect[i+1][j]);
            s.insert(a,b); 
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(m);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int answer = getMinEffort(arr);

    fout << answer << "\n";

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
