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

void solve() {
    int MOD = 1e9 + 7;
    int n, x, pos;
    cin >> n >> x >> pos;
    
    int cntBig = 0, cntLess = 0;
    int hasBig = n - x, hasLess = x - 1;
    int lt = 0, rt = n;
    while (lt < rt) {
        int mid = (lt + rt) / 2;

        if (mid < pos) {
            lt = mid + 1;
            cntLess++;
        } else if (mid > pos) {
            rt = mid;
            cntBig++;
        } else {
            lt = mid + 1;
        }
    }

    int dontmatter = n - cntBig - cntLess - 1;

    if (hasLess < cntLess || hasBig < cntBig) {
        cout << 0 << endl;
        return;
    }

    int64_t small = 1;
    while (cntLess) {
        small *= hasLess;
        small %= MOD;
        cntLess--, hasLess--;
    }

    int64_t large = 1;
    while (cntBig) {
        large *= hasBig;
        large %= MOD;
        cntBig--, hasBig--;
    }

    int64_t rest = 1;
    while (dontmatter) {
        rest *= dontmatter;
        rest %= MOD;
        dontmatter--;
    }

    rest *= large;
    rest %= MOD;
    rest *= small;
    rest %= MOD;

    cout << rest << endl;
    return;

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
