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
    string s;
    cin >> s;
    
    vector<int> ones;
    for (int i = 0; i < (int)s.size(); i++) {
        int temp = 0;
        while (i < (int)s.size() && s[i] == '1') {
            temp++;
            i++;
        }
        if (temp != 0) {
            ones.push_back(temp);
        }
    }
    
    sort(ones.begin(), ones.end(), greater <>());
    
    int ans = 0;
    for (int i = 0; i < (int)ones.size(); i++) {
        if (!(i & 1)) {
            ans += ones[i];
        }
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
