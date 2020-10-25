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
ll get_sum(vector<int> &v1, vector<int> &v2) {
    ll sum1 = 0, sum2 = 0;
    for (int& x: v1) {
        sum1 += x;
    }
    for (int& x: v2) {
        sum2 += x;
    }
 
    return abs(sum1 - sum2);
}
 
void group(vector<int> v, ll& ans, vector<int> v1, vector<int> v2, int curr, int n) {
    if ((int)v1.size() + (int)v2.size() == n) {
        ans = min(ans, get_sum(v1, v2));
        return;
    }
    
    v1.push_back(v[curr]);
    group(v, ans, v1, v2, curr+1, n);
    v1.pop_back();
 
    v2.push_back(v[curr]);
    group(v, ans, v1, v2, curr+1, n);
 
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }
 
    ll ans = 1e9;
    vector<int> v1, v2;
    group(v, ans, v1, v2, 0, n);
 
    cout << ans << endl;
}    
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 