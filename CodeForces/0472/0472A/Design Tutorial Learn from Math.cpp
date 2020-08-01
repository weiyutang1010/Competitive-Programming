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
 
bool is_composite(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return true;
    }
    return false;
} 
 
void solve() {
    int x;
    cin >> x;
    
    for (int i = 4; i <= x / 2; i+=2) {
        if (is_composite(x - i)) {
            cout << i << " " << x - i << endl;
            return;
        }
    }
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