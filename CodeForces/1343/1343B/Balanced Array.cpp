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
    int x;
    cin >> x;
    
    if (x % 4 != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    
    int sum1 = 0;
    for (int i = 1; i <= x / 2; i++) {
        cout << i * 2 << " ";
        sum1 += i * 2;
    }
    
    int sum2 = 0;
    for (int i = 1; i < x / 2; i++) {
        cout << 2 * i - 1 << " ";
        sum2 += 2 * i - 1;
    }
    cout << sum1 - sum2 << endl;
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