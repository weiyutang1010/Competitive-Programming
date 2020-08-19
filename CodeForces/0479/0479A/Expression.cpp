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
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    ans = max(ans, a * b + c);
    ans = max(ans, a + b * c);
    ans = max(ans, a * b * c);
    ans = max(ans, a + b + c);
    ans = max(ans, a * (b + c));
    ans = max(ans, (a + b) * c);

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
