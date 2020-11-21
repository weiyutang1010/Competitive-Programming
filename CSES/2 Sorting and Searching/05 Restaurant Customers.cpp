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
    int n;
    cin >> n;
    vector<int> cst(n);
    vector<int> leaving(n);
    for (int i = 0; i < n; i++) {
        cin >> cst[i];
        cin >> leaving[i];
    }
 
    sort(cst.begin(), cst.end());
    sort(leaving.begin(), leaving.end());
 
    int curr_cst = 0;
    int max_cst = 0;
    for (int i = 0, j = 0; i < n; i++) {
        curr_cst++;
        while (leaving[j] <= cst[i]) {
            j++;
            curr_cst--;
        }
        max_cst = max(max_cst, curr_cst);
    }
 
    cout << max_cst << endl;
 
        
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