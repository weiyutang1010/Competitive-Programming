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
    string st;
    cin >> st;
    
    int ans = 0;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int res = 0;
            int a = i, b = j;
            for (auto c: st) {
                if (c - '0' == a) {
                    res++;
                    swap(a, b);
                }
            }
            if  (i != j && (res & 1)) {
                res--;
            }
            ans = max(ans, res);
        }
    }
    
    cout << (int)st.size() - ans << endl;
    
    
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