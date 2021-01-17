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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(k);
    for (int i = 0; i < k - (n - k) - 1; i++) {
        ans[i] = i + 1;
    }

    int j = 0;
    for (int i = k - (n - k) - 1; i < k; i++,j++) {
        ans[i] = k - j;
    }

    for (int& x: ans) {
        cout << x << " ";
    }
    cout << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
