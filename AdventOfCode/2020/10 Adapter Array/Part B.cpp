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
    ifstream text("input.txt");
    vector<int> v;
    int n;
    string st;

    v.push_back(0);
    while (cin >> n) {
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    int adapter = v[v.size() - 1] + 3;

    v.push_back(adapter);

    vector<int64_t> dp(adapter + 1, 0);
    dp[0] = 1;
    // dp, similiar to coin change problem
    for (int i = 1; i < (int)v.size(); i++) {
        for (int j = 1; j <= 3; j++) {
            if (i - j >= 0 && v[i] - v[i - j] <= 3) {
                dp[v[i]] += dp[v[i - j]];
            }
        }
    }


    cout << dp[adapter] << endl;;

    text.close();
    return 0;
} 
