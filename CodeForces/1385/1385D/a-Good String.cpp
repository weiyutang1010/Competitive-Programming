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

int calc(string s, char c) {
    if (s.size() == 1) {
        return s[0] != c;
    }
    
    int mid = s.size() / 2;
    
    int cntl = calc(s.substr(0, mid), c + 1);
    cntl += mid - count(s.begin() + mid, s.end(), c);
    int cntr = calc(s.substr(mid, mid), c + 1);
    cntr += mid - count(s.begin(), s.begin() + mid, c);
    
    return min(cntl, cntr);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    cout << calc(s, 'a') << endl;
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
