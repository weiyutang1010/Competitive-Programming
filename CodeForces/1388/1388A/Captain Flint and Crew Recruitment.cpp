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

    if (n <= 30) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
    if (n - 30 == 6) {
        cout << 5 << " " << 6 << " ";
        cout << 10 << " " << 15 << endl;
        return;
    } else if (n - 30 == 10) {
        cout << 6 << " " << 14 << " ";
        cout << 15 << " " << 5 << endl;
        return;
    } else if (n - 30 == 14) {
        cout << 7 << " " << 6 << " ";
        cout << 10 << " " << 21 << endl;
        return;
    }

    cout << 6 << " " << 10 << " ";
    cout << 14 << " " << n - 30 << endl;
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
