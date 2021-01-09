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

int isHill(vector<int>& v, int i, int n) {
    return (i > 0 && i < n-1 && v[i] > v[i - 1] && v[i] > v[i + 1]);
}

int isValley(vector<int>& v, int i, int n) {
    return (i > 0 && i < n-1 && v[i] < v[i - 1] && v[i] < v[i + 1]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x: v) {
        cin >> x;
    }

    int num = 0;
    vector<int> is(n, 0);
    for (int i = 1; i < n - 1; i++) {
        if (isHill(v, i, n) || isValley(v, i, n)) {
            is[i] = 1;
            num++;
        }
    }

    int ans = num;
    for (int i = 1; i < n - 1; i++) {
        int temp = v[i];
        v[i] = v[i-1];
        ans = min(ans, num - is[i-1] - is[i] - is[i+1] + isHill(v, i-1, n) + isValley(v, i-1, n) + isHill(v,i,n) + isValley(v, i, n) + isHill(v,i+1,n) + isValley(v,i+1,n));
        v[i] = v[i+1];
        ans = min(ans, num - is[i-1] - is[i] - is[i+1] + isHill(v, i-1, n) + isValley(v, i-1, n) + isHill(v,i,n) + isValley(v, i, n) + isHill(v,i+1,n) + isValley(v,i+1,n));
        v[i] = temp;
    }

    cout << ans << endl;
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
