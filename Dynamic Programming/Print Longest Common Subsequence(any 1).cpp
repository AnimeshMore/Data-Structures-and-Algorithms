//Hackerrank Problem Link - https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//Code starts here
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
        vector<int> res;
        int x=a.size();
        int y=b.size();
        int t[x+1][y+1];

        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }

        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(a[i-1]==b[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
                }
        }

        int i=x,j=y;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                res.push_back(a[i-1]);
                i--;
                j--;
            }else{
                if(t[i][j-1]>t[i-1][j]){
                    j--;
                }else{
                    i--;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
}
//Code ends here

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

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
