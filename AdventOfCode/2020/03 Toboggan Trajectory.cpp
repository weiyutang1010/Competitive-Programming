/*
* author: weiyutang
*         Wei Yu Tang 
*/
 
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
 
using namespace std; 
 
const int MOD = 1e9 + 7;

int main() 
{
    // // Add an empty line
    // ofstream foutput;
    // foutput.open ("input.txt",ios::app);
    // foutput<<"\n";
    // foutput.close();

    ifstream text("input.txt");
    string st;
    vector<string> v;
    vector<ii> slope {{1,1},{3,1},{5,1},{7,1},{1,2}};
    vector<int> ans(5);

    while (getline(cin , st)) {
        v.push_back(st);
    }

    for (int i = 0; i < 5; i++) {
        int col = slope[i].f;
        int cnt = 0;
        for (int j = slope[i].s; j < (int)v.size(); j += slope[i].s) {
            if (v[j][col] == '#') {
                cnt++;
            }
            col = (col + slope[i].f) % v[0].size();
        }
        ans[i] = cnt;
    }

    int64_t res = 1;
    for (int& x: ans) {
        res *= x;
    }
    cout << res << endl;

    text.close();
    return 0;
} 
