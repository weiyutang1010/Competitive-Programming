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
    int temp;
    int ones = 0, twos = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 1) {
            ones++;
        } else {
            twos++;
        }
    }

    if (ones % 2) {
        cout << "NO" << endl;
        return;
    }

    twos = twos % 2;
    
    if (twos && ones < 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }


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
