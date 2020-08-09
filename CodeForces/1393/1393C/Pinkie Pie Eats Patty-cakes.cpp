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
    int n;
    cin >> n;
    map<int, int> m;
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        m[temp]++;
        max_cnt = max(m[temp], max_cnt);
    }
    
    int max_freq = 0;
    for (auto x: m) {
        if (x.s == max_cnt) {
            max_freq++;    
        }
    }

    cout << ((n - max_freq) / (max_cnt - 1)) - 1 << endl;
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
